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
/*  Schematic switch labels
    01A  05A  09A  13A  17A  21A         26A  30A  34A  38A  42A  46A
    02A  06A  10A  14A  18A  22A         27A  31A  35A  39A  43A  47A
    03A  07A  11A  15A  19A  23A         28A  32A  36A  40A  44A  48A
    04A  08A  12A  16A  20A  24A   ENC   29A  33A  37A  41A  45A  49A 
*/
#define LAYOUT( \
    c00, c10, c20, c30, c40, c50,        r00, r01, r02, r03, r04, r05,   \
    c01, c11, c21, c31, c41, c51,        r10, r11, r12, r13, r14, r15,   \
    c02, c12, c22, c32, c42, c52,        r20, r21, r22, r23, r24, r25,   \
    c03, c13, c23, c33, c43, c53,  c0R,  r30, r31, r32, r33, r34, r35,   \
) \
{ \
    /* LEFT SIDE SWITCHES, COL2ROW  */ \
    { c00, c10, c20, c30, c40, c50 },  \
    { c01, c11, c21, c31, c41, c51 },  \
    { c02, c12, c22, c32, c42, c52 },  \
    { c03, c13, c23, c33, c43, c53 },  \
    /* RIGHT SIDE SWITCHES, ROW2COL */ \
    { r00, r01, r02, r03, r04, r05 },  \
    { r10, r11, r12, r13, r14, r15 },  \
    { r20, r21, r22, r23, r24, r25 },  \
    { r30, r31, r32, r33, r34, r35 },  \
    /* ENCODER SWITCH, COL0 TO ENC_PIN */  \
    { c0R, XXX, XXX, XXX, XXX, XXX },  \
}
