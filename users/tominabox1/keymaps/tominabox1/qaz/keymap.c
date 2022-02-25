
#include QMK_KEYBOARD_H
#include "quantum.h"
#include "tominabox1.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_qaz_wrap(
    KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_QUOTE,
    _______________HOMEROW_MOD_________________,
    LT(_NAV,KC_Z), KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT,
    KC_NAV_ENT, KC_NO, KC_NO, KC_NAV_ENT, KC_NUM_SPC, KC_MPLY, KC_MNXT,KC_SLSH
  ),

  [_NUM_SYM] = LAYOUT_qaz_wrap(
    __________________NUM_1____________________,
    __________________NUM_2____________________,
    RGB_SAI, RGB_HUI, RGB_VAI,  KC_UNDS,  KC_UNDS,  KC_RPRN,  KC_RBRC,  KC_COMM, KC_DOT,
    KC_TRNS,KC_TRNS,KC_TRNS,  KC_TRNS,   KC_TRNS,  LWIN(LCTL(KC_LEFT)),LWIN(LCTL(KC_RIGHT)),KC_TRNS
  ),

  [_NAV] = LAYOUT_qaz_wrap(
    KC_PGDN,  KC_UP,  KC_PGDN, KC_F3, KC_F4,  KC_NO,  KC_PGDN,    KC_UP,  KC_PGUP,    TD(TD_RESET),
    KC_LEFT,  KC_DOWN,  KC_RIGHT,  KC_F7,  KC_F8,  KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RGHT,   KC_END,
    KC_TRNS,  KC_F2,  KC_F3,  KC_F4,  LCTL(KC_F12),  KC_F6,   KC_F7,   KC_F8, KC_BSLASH,
    KC_TRNS,  RGB_TOG, RGB_MOD,KC_TRNS,   KC_TRNS,LWIN(LCTL(KC_LEFT)),LWIN(LCTL(KC_RIGHT)), KC_NO
  ),

};
