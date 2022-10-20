#include "doom.h"
#ifndef _WIN32
#include "display.h"
#include <driver/gpio.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "doom/doomkeys.h"
#include "doom/doomgeneric.h"

static bool first = true;

void D_DoomMain (void);
void D_DoomFrame (void);
extern uint8_t I_VideoBuffer[];
unsigned char *I_GetPalette();
uint32_t DG_GetTicksMs() { return 0; }

int key_flag = 0;
bool flag_up = false;
bool flag_down = false;
bool flag_left = false;
bool flag_right = false;
bool flag_a = false;
bool flag_b = false;
bool flag_left_strafe = false;
bool flag_right_strafe = false;
bool flag_use = false;
bool done = false;
int DG_GetKey(int *pressed, unsigned char *doomKey) {

	#ifndef _WIN32

	const int PIN_LEFT = 16;
	const int PIN_UP = 35;
	const int PIN_RIGHT = 12;
	const int PIN_DOWN = 15;
	const int PIN_A = 4;
	const int PIN_B = 17;

	if (done) {
		done = false;
		return 0;
	}

	if (gpio_get_level(PIN_DOWN) == 0) {
		if (!flag_down) {
			flag_down = true;
			*doomKey = KEY_DOWNARROW;
			*pressed = 1;
			return 1;
		}
	}
	else if (flag_down && gpio_get_level(PIN_DOWN) == 1) {
		*doomKey = KEY_DOWNARROW;
		*pressed = 0;
		flag_down = false;
		return 1;
	}
	if (gpio_get_level(PIN_DOWN) == 0 && gpio_get_level(PIN_A) == 0) {
		if (!flag_use) {
			flag_use = true;
			*doomKey = KEY_USE;
			*pressed = 1;
			return 1;
		}
	}
	else if (flag_use && gpio_get_level(PIN_DOWN) == 1) {
		*doomKey = KEY_USE;
		*pressed = 0;
		flag_use = false;
		return 1;
	}
	else if (gpio_get_level(PIN_UP) == 0) {
		if (!flag_up) {
			flag_up = true;
			*doomKey = KEY_UPARROW;
			*pressed = 1;
			return 1;
		}
	}
	else if (flag_up && gpio_get_level(PIN_UP) == 1) {
		*doomKey = KEY_UPARROW;
		*pressed = 0;
		flag_up = false;
		return 1;
	}

	if (gpio_get_level(PIN_LEFT) == 0 && gpio_get_level(PIN_B) == 0) {
		if (!flag_left_strafe) {
			flag_left_strafe = true;
			*doomKey = KEY_STRAFE_L;
			*pressed = 1;
			return 1;
		}
	}
	else if (flag_left_strafe && gpio_get_level(PIN_LEFT) == 1) {
		*doomKey = KEY_STRAFE_L;
		*pressed = 0;
		flag_left_strafe = false;
		return 1;
	}

	else if (gpio_get_level(PIN_RIGHT) == 0 && gpio_get_level(PIN_B) == 0) {
		if (!flag_right_strafe) {
			flag_right_strafe = true;
			*doomKey = KEY_STRAFE_R;
			*pressed = 1;
			return 1;
		}
	}
	else if (flag_right_strafe && gpio_get_level(PIN_RIGHT) == 1) {
		*doomKey = KEY_STRAFE_R;
		*pressed = 0;
		flag_right_strafe = false;
		return 1;
	}
	else if (gpio_get_level(PIN_LEFT) == 0) {
		// if (!flag_left) {
			flag_left = true;
			*doomKey = KEY_LEFTARROW;
			*pressed = 1;
			done = true;
			return 1;
		// }
	}
	else if (flag_left && gpio_get_level(PIN_LEFT) == 1) {
		*doomKey = KEY_LEFTARROW;
		*pressed = 0;
		flag_left = false;
		return 1;
	}

	else if (gpio_get_level(PIN_RIGHT) == 0) {
		// if (!flag_right) {
			flag_right = true;
			*doomKey = KEY_RIGHTARROW;
			*pressed = 1;
			done = true;
			return 1;
		// }
	}
	else if (flag_right && gpio_get_level(PIN_RIGHT) == 1) {
		*doomKey = KEY_RIGHTARROW;
		*pressed = 0;
		flag_right = false;
		return 1;
	}

	if (gpio_get_level(PIN_A) == 0) {
		if (!flag_a) {
			flag_a = true;
			*doomKey = KEY_FIRE;
			*pressed = 1;
			return 1;
		}
	}
	else if (flag_a && gpio_get_level(PIN_A) == 1) {
		*doomKey = KEY_FIRE;
		*pressed = 0;
		flag_a = false;
		return 1;
	}

	else if (gpio_get_level(PIN_B) == 0) {
		if (!flag_b) {
			flag_b = true;
			*doomKey = KEY_ENTER;
			*pressed = 1;
			return 1;
		}
	}
	else if (flag_b && gpio_get_level(PIN_B) == 1) {
		*doomKey = KEY_ENTER;
		*pressed = 0;
		flag_b = false;
		return 1;
	}

	#else // _WIN32

	if (key_flag == 1) {
		key_flag = 2;
		*doomKey = KEY_ENTER;
		*pressed = 1;
		return 1;
	}
	else if (key_flag == 2) {
		key_flag = 0;
		*doomKey = KEY_ENTER;
		*pressed = 0;
		return 1;
	}

	if (key_flag == 20) {
		key_flag = 21;
		*doomKey = KEY_USE;
		*pressed = 1;
		return 1;
	}
	else if (key_flag == 21) {
		key_flag = 100;
		return 0;
	}
	else if (key_flag == 100) {
		key_flag = 0;
		*doomKey = KEY_USE;
		*pressed = 0;
		return 1;
	}

	else if (key_flag == 3) {
		key_flag = 4;
		*doomKey = KEY_FIRE;
		*pressed = 1;
		return 1;
	}
	else if (key_flag == 4) {
		key_flag = 99;
		return 0;
	}
	else if (key_flag == 99) {
		key_flag = 0;
		*doomKey = KEY_FIRE;
		*pressed = 0;
		return 1;
	}

	else if (key_flag == 5) {
		key_flag = 0;
		*doomKey = KEY_UPARROW;
		*pressed = 1;
		return 1;
	}
	else if (key_flag == 6) {
		key_flag = 0;
		*doomKey = KEY_UPARROW;
		*pressed = 0;
		return 1;
	}

	else if (key_flag == 7) {
		key_flag = 0;
		*doomKey = KEY_DOWNARROW;
		*pressed = 1;
		return 1;
	}
	else if (key_flag == 8) {
		key_flag = 0;
		*doomKey = KEY_DOWNARROW;
		*pressed = 0;
		return 1;
	}
	else if (key_flag == 9) {
		key_flag = 0;
		*doomKey = KEY_LEFTARROW;
		// *doomKey = KEY_STRAFE_L;
		*pressed = 1;
		return 1;
	}
	else if (key_flag == 10) {
		key_flag = 0;
		*doomKey = KEY_LEFTARROW;
		// *doomKey = KEY_STRAFE_L;
		*pressed = 0;
		return 1;
	}

	else if (key_flag == 11) {
		key_flag = 0;
		*doomKey = KEY_RIGHTARROW;
		// *doomKey = KEY_STRAFE_R;
		*pressed = 1;
		return 1;
	}
	else if (key_flag == 12) {
		key_flag = 0;
		*doomKey = KEY_RIGHTARROW;
		// *doomKey = KEY_STRAFE_R;
		*pressed = 0;
		return 1;
	}
	#endif

	return 0;
}

void doom_run() {
	if (first) {
		D_DoomMain();
		first = false;
	}

	D_DoomFrame();
}
