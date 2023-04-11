// Copyright 2023 Hoan (@hvuitsme)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"


/* key matrix size */
#define MATRIX_COLS 6  // 6 columns on each side
#define MATRIX_ROWS 9  // 4 rows for each side, and 1 extra row for the rotary encoder

/* keyboard matrix assignments */
#define MATRIX_COL_PINS { F6, F7, B1, B3, B2, B6 }
#define MATRIX_ROW_PINS { D7, E6, B4, B5 }

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW



/* encoder pin definitions */
#define ENCODERS_PAD_A { F4 }
#define ENCODERS_PAD_B { F5 }
#define ENC_PIN C6  // extra row pin connected to encoder switch. used in matrix.c



/* rgblight definitions */
#define RGB_DI_PIN D3   // The pin connected to the data pin of the LEDs
#define RGBLED_NUM 56   // The number of LEDs connected
#define RGBLIGHT_SLEEP  // RGB lighting will be switched off when the host goes to sleep
#define RGBLIGHT_LIMIT_VAL 127  // The maximum brightness level (max allowed is 255)

/* enabled rgb animations. comment out the effects you do not want enabled. */
#define RGBLIGHT_EFFECT_ALTERNATING         // Enable alternating animation mode.
#define RGBLIGHT_EFFECT_BREATHING	        // Enable breathing animation mode.
#define RGBLIGHT_EFFECT_CHRISTMAS	        // Enable christmas animation mode.
#define RGBLIGHT_EFFECT_KNIGHT	            // Enable knight animation mode.
#define RGBLIGHT_EFFECT_RAINBOW_MOOD	    // Enable rainbow mood animation mode.
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL	    // Enable rainbow swirl animation mode.
#define RGBLIGHT_EFFECT_RGB_TEST	        // Enable RGB test animation mode.
#define RGBLIGHT_EFFECT_SNAKE	            // Enable snake animation mode.
#define RGBLIGHT_EFFECT_STATIC_GRADIENT	    // Enable static gradient mode.
#define RGBLIGHT_EFFECT_TWINKLE	            // Enable twinkle animation mode.

/* change the order of the LED indexes to match the keymap layout */
#define RGBLIGHT_LED_MAP {                                  \
    /* per-key LEDs */                                      \
    05, 04, 03, 02, 01, 00,         47, 46, 45, 44, 43, 42, \
    06, 07, 08, 09, 10, 11,         36, 37, 38, 39, 40, 41, \
    17, 16, 15, 14, 13, 12,         35, 34, 33, 32, 31, 30, \
    18, 19, 20, 21, 22, 23,         24, 25, 26, 27, 28, 29, \
    /* underglow LEDs */                                    \
            54,         55,         48,         49,         \
            53,         52,         51,         50          \
}
