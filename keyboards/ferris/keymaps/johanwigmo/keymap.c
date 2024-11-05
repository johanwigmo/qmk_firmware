// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

#define KC_LSHA LSFT_T(KC_A)
#define KC_LCTS LCTL_T(KC_S)
#define KC_LALD LALT_T(KC_D)
#define KC_LGUF LGUI_T(KC_F)

#define KC_RGUJ RGUI_T(KC_J)
#define KC_LALK LALT_T(KC_K)
#define KC_RCTL RCTL_T(KC_L)
#define KC_RSHC RSFT_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_LSHA, KC_LCTS, KC_LALD, KC_LGUF, KC_G,        KC_H,    KC_RGUJ, KC_LALK, KC_RCTL, KC_RSHC, 
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                            LT(3,KC_DEL), KC_ENT, LT(1,KC_SPC), LT(2,KC_BSPC)
  ),

  [1] = LAYOUT(

    KC_NO,   KC_ACL0, KC_ACL1, KC_ACL2, KC_NO,       KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO,
    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_BTN1,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BTN2,     KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, KC_NO,
                                      KC_NO, KC_NO, KC_NO, KC_NO
  ),

  [2] = LAYOUT(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO,       KC_TILD, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_GRV,  KC_QUOT, KC_BSLS, KC_PIPE, KC_SLSH,
                                    KC_ESC, KC_TAB, KC_NO, KC_NO
  ),

  [3] = LAYOUT(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_ESC,      KC_TILD, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TAB,      KC_GRV,  KC_QUOT, KC_DQUO, KC_LBRC, KC_RBRC,
                                      KC_NO, KC_NO, KC_NO, KC_NO 
  ),
};
