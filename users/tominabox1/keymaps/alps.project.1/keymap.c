
#include QMK_KEYBOARD_H
#include "quantum.h"
#include "tominabox1.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_GESC, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_QUOTE, KC_BSPC,
    KC_TAB, LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_D, KC_H, RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O),
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH,
    DM_RSTP, DM_PLY1, KC_NAV_ENT, KC_NUM_SPC, KC_NAV_ENT,RGUI(RSFT(RCTL(KC_4)))
  ),

  [_NUM_SYM] = LAYOUT(
    KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
    KC_TAB, KC_EXLM, KC_AT, KC_HASH, TD(TD_DLR_LP), KC_PERC, KC_CIRC, TD(TD_AMP_RP), KC_ASTR, KC_EQUAL, KC_MINS,
    KC_DEL, DM_REC1, DM_RSTP, DM_PLY1,  KC_UNDS,  KC_UNDS,  KC_RPRN,  KC_RBRC,  KC_COMM, KC_DOT, KC_PIPE,
    KC_TRNS,KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS
  ),

  [_NAV] = LAYOUT(
    KC_GRV,  KC_F1,  KC_F2, KC_F3, KC_F4,  KC_NO,  KC_NO, KC_PGDN, KC_UP,  KC_PGUP,  KC_NO,   TD(TD_RESET),
    KC_TAB, KC_NO, KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RGHT,   KC_END,
    RGB_TOG,  KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_NO,   KC_NO,  KC_NO,  KC_COMM,   KC_DOT, KC_BSLS,
    KC_TRNS,KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS
  ),

};
