// Copyright 2023 Hoan (@hvuitsme)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

#define XXX KC_NO

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
    l00, l04, l10, l14, l20, l24, r00, r04, r10, r14, r20, r24,  \
    l01, l05, l11, l15, l21, l25, r01, r05, r11, r15, r21, r25,  \
    l02, l06, l12, l16, l22, l26, r02, r06, r12, r16, r22, r26,  \
    l03, l07, l13, l17, l23, l27, l28, r03, r07, r13, r17, r23, r27   \
) { \
    { l00, l01, l02, l03, l04, l05, l06, l07 }, \
    { l10, l11, l12, l13, l14, l15, l16, l17 }, \
    { l20, l21, l22, l23, l24, l25, l26, l27 }, \
    { r00, r01, r02, r03, r04, r05, r06, r07 }, \
    { r10, r11, r12, r13, r14, r15, r16, r17 }, \
    { r20, r21, r22, r23, r24, r25, r26, r27 }, \
    { XXX, XXX, XXX } \
}
