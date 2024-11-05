/* Copyright 2015-2021 Jack Humbert
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

#ifdef AUDIO_ENABLE
#    include "muse.h"
#endif

enum planck_layers {
  _QWERTY,
  _NAVIGATION,
  _NUMBER,
  _SYMBOL,
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT,
  EXT_PLV
};

#define NAV MO(_NAVIGATION)
#define NUMBER MO(_NUMBER)
#define SYMBOL MO(_SYMBOL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Missing
 * - Add Layers on thumb keys
 */

/* Qwerty
 * ,-----------------------------------------------------------------------.
 * |  Q  |  W  |  E  |  R  |  T  |     |     |  Y  |  U  |  I  |  O  |  P  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|-----|
 * |  A  |  S  |  D  |  F  |  G  |     |     |  H  |  J  |  K  |  L  |  ;  | SCAG / GACS
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|-----|
 * |  Z  |  X  |  C  |  V  |  B  |     |     |  N  |  M  |  ,  |  .  |  /  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|-----|
 * |     |     |     | DEL | ENT |     |     | SPC | BKSP|     |     |     |
 * `-----------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_Q,         KC_W,         KC_E,         KC_R,               KC_T,   _______, _______, KC_Y,            KC_U,                KC_I,         KC_O,         KC_P,
    LSFT_T(KC_A), LCTL_T(KC_S), LALT_T(KC_D), LGUI_T(KC_F),       KC_G,   _______, _______, KC_H,            RGUI_T(KC_J),        LALT_T(KC_K), RCTL_T(KC_L), RSFT_T(KC_SCLN), 
    KC_Z,         KC_X,         KC_C,         KC_V,               KC_B,   _______, _______, KC_N,            KC_M,                KC_COMM,      KC_DOT,       KC_SLSH, 
    _______,      _______,      _______,      LT(SYMBOL, KC_DEL), KC_ENT, _______, _______, LT(NAV, KC_SPC), LT(NUMBER, KC_BSPC), _______,      _______,      _______
),

/* Navigation
 * ,-----------------------------------------------------------------------.
 * |     |     | MUP |     |     |     |     |     |MSPD1|MSPD2|MSPD3|     | 
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |MLEFT|MDOWN|MRGHT|  M1 |     |     |LEFT |DOWN | UP  |RGHT |     | 
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |  M2 |     |     |NEXT |VOLD |VOLU |PLAY |     |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----|-----+-----+-----|
 * |     |     |     |     |     |     |     |  X  |     |     |     |     |
 * `-----------------------------------------------------------------------'
 */
[_NAVIGATION] = LAYOUT_planck_grid(
    _______, _______,         KC_MS_U,         _______,         _______, _______, _______, _______,         KC_ACL0,         KC_ACL1,         KC_ACL2,       _______,
    KC_LSFT, LCTL_T(KC_MS_L), LALT_T(KC_MS_D), LGUI_T(KC_MS_R), KC_BTN1, _______, _______, RGUI_T(KC_LEFT), LALT_T(KC_DOWN), RCTL_T(KC_UP), RSFT_T(KC_RGHT), _______,
    _______, _______,         _______,         _______,         KC_BTN2, _______, _______, KC_MNXT,         KC_VOLD,         KC_VOLU,       KC_MPLY,         _______,
    _______, _______,         _______,         _______,         _______, _______, _______, _______,         _______,         _______,       _______,         _______ 
),

/* Number 
 * ,-----------------------------------------------------------------------.
 * |  1  |  2  |  3  |  4  |  5  |     |     |  6  |  7  |  8  |  9  |  0  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----| // Move ` and ' to left side, " is really weird 
 * |     |     |     |     |     |     |     |  ~  |  -  |  =  |  [  |  ]  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     |     |  `  |  '  |  \  |  |  |  /  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     | ESC | TAB |     |     |     |  X  |     |     |     |
 * `-----------------------------------------------------------------------'
 */
[_NUMBER] = LAYOUT_planck_grid(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______, _______, _______, KC_TILD, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,
    _______, _______, _______, _______, _______, _______, _______, KC_GRV,  KC_QUOT, KC_BSLS, KC_PIPE, KC_SLSH,
    _______, _______, _______, KC_ESC,  KC_TAB,  _______, _______, _______, _______, _______, _______, _______
),

/* Symbol
 * ,-----------------------------------------------------------------------.
 * |  !  |  @  |  #  |  $  |  %  |     |     |  ^  |  &  |  *  |  (  |  )  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     | ESC |     |     |  ~  |  _  |  +  |  {  |  }  | SCAG / GACS
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     | TAB |     |     |  `  |  '  |  "  |  [  |  ]  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |  X  |     |     |     |     |     |     |     |     |
 * `-----------------------------------------------------------------------'
 */
[_SYMBOL] = LAYOUT_planck_grid(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_ESC,  _______, _______, KC_TILD, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,
    _______, _______, _______, _______, KC_TAB,  _______, _______, KC_GRV,  KC_QUOT, KC_DQUO, KC_LBRC, KC_RBRC,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};
