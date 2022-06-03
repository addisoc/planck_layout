/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "action_tapping.h" // necessary for action_tapping_process

#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2
#define _LAYER3 3
#define _LAYER4 4


enum custom_keycodes {
    LAYER0 = SAFE_RANGE,
    LAYER1,
    LAYER2,
    LAYER3,
    LAYER4,
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(4,KC_TAB):
            return 200;
        default:
            return TAPPING_TERM;
    }
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_LAYER0] = LAYOUT(LT(4,KC_TAB), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, LT(3,KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT, KC_BTN1, KC_LCTL, KC_LALT, KC_LGUI, MO(1), KC_SPC, KC_SPC, LT(2,KC_ENT), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),

[_LAYER1] = LAYOUT(KC_TRNS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS, KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BSLS, KC_TRNS, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

[_LAYER2] = LAYOUT(KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_NO, KC_NO, KC_UNDS, KC_MINS, KC_EQL, KC_PLUS, KC_DEL, KC_TRNS, KC_F5, KC_F6, KC_F7, KC_F8, KC_NO, KC_NO, KC_NO, KC_LCBR, KC_RCBR, KC_NO, KC_NO, KC_TRNS, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO, KC_NO, KC_LBRC, KC_RBRC, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

[_LAYER3] = LAYOUT(KC_TRNS, KC_BRID, KC_BRIU, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_UP, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_MPLY, KC_MRWD, KC_MFFD, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO, KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

[_LAYER4] = LAYOUT(RGB_TOG, DYN_REC_START1, DYN_REC_START2, KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_D, KC_BTN1, KC_MS_U, KC_BTN2, KC_NO, LCTL(LSFT(LGUI(KC_4))), KC_NO, DYN_MACRO_PLAY1, DYN_MACRO_PLAY2, KC_NO, KC_NO, KC_NO, KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_R, KC_WH_L, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_TOG, QK_BOOTLOADER, DEBUG, KC_NO) 

};

