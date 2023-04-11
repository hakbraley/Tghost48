// Copyright 2023 Hoan (@hvuitsme)
// SPDX-License-Identifier: GPL-2.0-or-later

#include <stdio.h>
#include QMK_KEYBOARD_H
#include "keymap_japanese.h"

extern keymap_config_t keymap_config;

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE = 0,
    _FN1
};

#define _______ KC_TRANSPARENT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,              KC_H,    KC_J,    KC_K,    KC_L,    KC_LBRC, KC_RBRC,
        KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,              KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
        KC_LCTL,   KC_LOPT, _______, MO(2),   MO(1),   KC_SPC,  KC_MUTE,  KC_SPC,  _______, KC_LEFT, KC_UP,   KC_DOWN, KC_RIGHT
    ),
    [_FN1] = LAYOUT(
        _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};
