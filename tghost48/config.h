// Copyright 2023 Hoan (@hvuitsme)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID    0xFEED
#define PRODUCT_ID   0x0000
#define DEVICE_VER   0x0001
#define MANUFACTURER hvuitsme
#define PRODUCT      tghost48

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



/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

