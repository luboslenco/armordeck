#include <kinc/graphics1/graphics.h>
#include <kinc/system.h>
#include <kinc/input/keyboard.h>

#define SCREEN_WIDTH (128 * 4)
#define SCREEN_HEIGHT (128 * 4)

#include "../../esp32/main/doom.c"

extern uint8_t I_VideoBuffer[];
unsigned char *I_GetPalette();

static void update(void) {
	doom_run();

	uint16_t *palette = (uint16_t *)I_GetPalette();
	uint8_t *buffer = I_VideoBuffer;
	uint8_t *screen = (uint8_t *)kinc_internal_g1_image;
	kinc_g1_begin();
	for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; ++i) {
		int x = (i % SCREEN_WIDTH) / 4 + 16;
		int y = (i / SCREEN_WIDTH) / 4;
		uint16_t c = palette[buffer[y * 160 + x]];
		screen[i * 4 + 0] = ((c & 0xF800) >> 11) << 3;
		screen[i * 4 + 1] = ((c & 0x7E0) >> 5) << 2;
		screen[i * 4 + 2] = ((c & 0x1F) >> 0) << 3;
	}
	kinc_g1_end();
}

void on_key_down(int key_code) {
	switch (key_code) {
		case KINC_KEY_W:
			key_flag = 5;
			break;
		case KINC_KEY_S:
			key_flag = 7;
			break;
		case KINC_KEY_A:
			key_flag = 9;
			break;
		case KINC_KEY_D:
			key_flag = 11;
			break;
		case KINC_KEY_CONTROL:
			key_flag = 3;
			break;
		case KINC_KEY_RETURN:
			key_flag = 1;
			break;
		case KINC_KEY_SPACE:
			key_flag = 20;
			break;
	}
}

void on_key_up(int key_code) {
	switch (key_code) {
		case KINC_KEY_W:
			key_flag = 6;
			break;
		case KINC_KEY_S:
			key_flag = 8;
			break;
		case KINC_KEY_A:
			key_flag = 10;
			break;
		case KINC_KEY_D:
			key_flag = 12;
			break;
	}
}

int kickstart(int argc, char **argv) {
	kinc_init("ArmorDeck", SCREEN_WIDTH, SCREEN_HEIGHT, NULL, NULL);
	kinc_g1_init(SCREEN_WIDTH, SCREEN_HEIGHT);
	kinc_set_update_callback(update);
	kinc_keyboard_set_key_down_callback(&on_key_down);
	kinc_keyboard_set_key_up_callback(&on_key_up);
	kinc_start();
	return 0;
}
