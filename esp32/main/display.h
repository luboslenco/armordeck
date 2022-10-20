#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 128

void display_init(int8_t DC, int8_t CS);
void display_show(void);
void display_shutdown(void);
