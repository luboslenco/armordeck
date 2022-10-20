#include <string.h>
#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>
#include <esp_sleep.h>
#include <sdkconfig.h>
#include <driver/rtc_io.h>
#include "display.h"
#include "doom.h"

#define PIN_MOSE 23
#define PIN_CLK 18
#define PIN_DC 26
#define PIN_RST 25
#define PIN_CS 0
#define PIN_LEFT 16
#define PIN_UP 35
#define PIN_RIGHT 12
#define PIN_DOWN 15
#define PIN_A 4
#define PIN_B 17

void app_main(void) {
	display_init(PIN_DC, PIN_CS);

	gpio_set_pull_mode(PIN_UP, GPIO_PULLUP_ONLY);
	gpio_set_pull_mode(PIN_DOWN, GPIO_PULLUP_ONLY);
	gpio_set_pull_mode(PIN_LEFT, GPIO_PULLUP_ONLY);
	gpio_set_pull_mode(PIN_RIGHT, GPIO_PULLUP_ONLY);
	gpio_set_pull_mode(PIN_A, GPIO_PULLUP_ONLY);
	gpio_set_pull_mode(PIN_B, GPIO_PULLUP_ONLY);

	while (1) {
		doom_run();

		// Enter sleep, PIN_DOWN to wake up
		if (gpio_get_level(PIN_B) == 0 && gpio_get_level(PIN_A) == 0) {
			display_shutdown();
			rtc_gpio_pullup_en(GPIO_NUM_15);
			rtc_gpio_pulldown_dis(GPIO_NUM_15);
			rtc_gpio_hold_en(GPIO_NUM_15);
			esp_sleep_enable_ext0_wakeup(GPIO_NUM_15, 0);
			esp_deep_sleep_start();
		}

		// Reset
		if (gpio_get_level(PIN_UP) == 0 && gpio_get_level(PIN_DOWN) == 0 && gpio_get_level(PIN_LEFT) == 0 && gpio_get_level(PIN_RIGHT) == 0) {
			esp_restart();
		}

		display_show();
	}
}
