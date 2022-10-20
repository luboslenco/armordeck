
#include "display.h"
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/spi_master.h"
#include "driver/gpio.h"

#define SSD1351_SETCOLUMN 0x15
#define SSD1351_SETROW 0x75
#define SSD1351_WRITERAM 0x5C
#define SSD1351_DISPLAYOFFSET 0xA2
#define SSD1351_NORMALDISPLAY 0xA6
#define SSD1351_FUNCTIONSELECT 0xAB
#define SSD1351_DISPLAYOFF 0xAE
#define SSD1351_DISPLAYON 0xAF
#define SSD1351_PRECHARGE 0xB1
#define SSD1351_CLOCKDIV 0xB3
#define SSD1351_SETVSL 0xB4
#define SSD1351_SETGPIO 0xB5
#define SSD1351_PRECHARGE2 0xB6
#define SSD1351_VCOMH 0xBE
#define SSD1351_CONTRASTABC 0xC1
#define SSD1351_CONTRASTMASTER 0xC7
#define SSD1351_MUXRATIO 0xCA
#define SSD1351_COMMANDLOCK 0xFD
#define SSD1351_REMAP 0xA0

int8_t dc, cs;
// uint16_t screen[SCREEN_HEIGHT * SCREEN_WIDTH];
uint16_t screen[SPI_MAX_DMA_LEN / 2]; // 4096 - 4

spi_device_handle_t _spi;

void spi_write_bytes(const uint8_t* data, size_t len) {
	spi_transaction_t trans;
	memset(&trans, 0, sizeof(spi_transaction_t));
	trans.length = len * 8;
	trans.tx_buffer = data;
	spi_device_transmit(_spi, &trans);
}

void ssd1351_command(uint8_t c) {
	gpio_set_level(dc, 0);
	spi_write_bytes(&c, 1);
}

void ssd1351_data(uint8_t c) {
	gpio_set_level(dc, 1);
	spi_write_bytes(&c, 1);
}

void display_init(int8_t DC, int8_t CS) {
	dc = DC;
	cs = CS;

	gpio_reset_pin(dc);
	gpio_set_direction(dc, GPIO_MODE_OUTPUT);
	gpio_set_level(dc, 0);

	spi_bus_config_t spi_bus_config = {
		.mosi_io_num = 23,
		.miso_io_num = -1,
		.sclk_io_num = 18,
		.quadwp_io_num = -1,
		.quadhd_io_num = -1,
		.max_transfer_sz = 0,
		.flags = 0
	};
	spi_bus_initialize(HSPI_HOST, &spi_bus_config, SPI_DMA_CH_AUTO);

	spi_device_interface_config_t spi_dev_config;
	memset(&spi_dev_config, 0, sizeof(spi_device_interface_config_t));
	spi_dev_config.clock_speed_hz = 16000000;
	spi_dev_config.spics_io_num = cs;
	spi_dev_config.queue_size = 1;
	spi_bus_add_device(HSPI_HOST, &spi_dev_config, &_spi);

	gpio_reset_pin(cs);
	gpio_set_direction(cs, GPIO_MODE_OUTPUT);
	gpio_set_level(cs, 0);

	ssd1351_command(SSD1351_COMMANDLOCK);
	ssd1351_data(0x12);
	ssd1351_command(SSD1351_COMMANDLOCK);
	ssd1351_data(0xB1);
	ssd1351_command(SSD1351_DISPLAYOFF);
	ssd1351_command(SSD1351_CLOCKDIV);
	ssd1351_command(0xF1);
	ssd1351_command(SSD1351_MUXRATIO);
	ssd1351_data(127);
	ssd1351_command(SSD1351_DISPLAYOFFSET);
	ssd1351_data(0x0);
	ssd1351_command(SSD1351_SETGPIO);
	ssd1351_data(0x00);
	ssd1351_command(SSD1351_FUNCTIONSELECT);
	ssd1351_data(0x01);
	ssd1351_command(SSD1351_PRECHARGE);
	ssd1351_command(0x32);
	ssd1351_command(SSD1351_VCOMH);
	ssd1351_command(0x05);
	ssd1351_command(SSD1351_NORMALDISPLAY);
	ssd1351_command(SSD1351_CONTRASTABC);
	ssd1351_data(0xC8);
	ssd1351_data(0x80);
	ssd1351_data(0xC8);
	ssd1351_command(SSD1351_CONTRASTMASTER);
	// ssd1351_data(0x0F);
	ssd1351_data(0x09);
	ssd1351_command(SSD1351_REMAP);
	ssd1351_data(0x74);
	ssd1351_command(SSD1351_SETVSL);
	ssd1351_data(0xA0);
	ssd1351_data(0xB5);
	ssd1351_data(0x55);
	ssd1351_command(SSD1351_PRECHARGE2);
	ssd1351_data(0x01);
	ssd1351_command(SSD1351_DISPLAYON);
}

#include "doom/doomgeneric.h"
extern uint8_t I_VideoBuffer[];
unsigned char *I_GetPalette();

void display_show(void) {
	ssd1351_command(SSD1351_SETCOLUMN);
	ssd1351_data(0);
	ssd1351_data(SCREEN_WIDTH - 1);
	ssd1351_command(SSD1351_SETROW);
	ssd1351_data(0);
	ssd1351_data(SCREEN_HEIGHT - 1);
	ssd1351_command(SSD1351_WRITERAM);
	gpio_set_level(dc, 1);

	uint16_t *palette = (uint16_t *)I_GetPalette();
	uint8_t *buffer = I_VideoBuffer;
	int j = 0;
	for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; ++i) {
		int x = i % SCREEN_WIDTH + 16;
		int y = i / SCREEN_WIDTH;

		screen[j++] = palette[buffer[y * DOOMGENERIC_RESX + x]];
		screen[j - 1] = (screen[j - 1] >> 8) | (screen[j - 1] << 8);
		if (j >= SPI_MAX_DMA_LEN / 2) {
			spi_write_bytes((uint8_t*)(screen), SPI_MAX_DMA_LEN);
			j = 0;
		}
	}
	if (j > 0) spi_write_bytes((uint8_t*)(screen), j);

	// uint16_t i = 0;
	// uint16_t len = SCREEN_WIDTH * SCREEN_HEIGHT * 2;
	// while (i < len) {
	// 	spi_write_bytes((uint8_t*)(screen) + i, len - i > SPI_MAX_DMA_LEN ? SPI_MAX_DMA_LEN : len - i);
	// 	i += SPI_MAX_DMA_LEN;
	// }
}

void display_shutdown(void) {
	ssd1351_command(SSD1351_DISPLAYOFF);
}
