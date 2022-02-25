#include QMK_KEYBOARD_H
#include "quantum.h"
#include "tominabox1.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_33_big_space(
	KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_QUOT,
	LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), TD(TD_DCAP), KC_H, RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O),
                  LT(_NAV, KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M, KC_COMM,  KC_DOT,     KC_SLSH,
    KC_MPLY, KC_NUM_SPC, KC_MNXT
  ),

  [_NUM_SYM] = LAYOUT_33_big_space(
	KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,
    KC_EXLM,    KC_AT,  KC_HASH,   TD(TD_DLR_LP), KC_PERC, KC_CIRC, TD(TD_AMP_RP),  KC_ASTR,   KC_EQL,  KC_MINS,
    KC_TRNS,  KC_LCBR,  KC_LBRC,  KC_LPRN,   KC_UNDS, KC_RPRN,  KC_RBRC,  KC_RCBR,  KC_DOT,  KC_SLSH,
  LWIN(LCTL(KC_LEFT)), KC_TRNS, LWIN(LCTL(KC_RIGHT))
  ),

  [_NAV] = LAYOUT_33_big_space(
    KC_PGDN,  KC_UP,  KC_PGUP, KC_NO, KC_NO,  KC_NO,  KC_PGDN,    KC_UP,  KC_PGUP,    TD(TD_RESET),
    KC_LEFT,  KC_DOWN,  KC_RIGHT,  KC_NO,  KC_NO,  KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RGHT,   KC_END,
    RGB_MOD,  DM_REC1,  KC_NO,  KC_NO,  LCTL(KC_F12),  KC_NO,    KC_NO,  KC_COMM,   KC_DOT,  KC_BSLS,
    LWIN(LCTL(KC_LEFT)), KC_TRNS,  LWIN(LCTL(KC_RIGHT))
  ),

  [_GAME] = LAYOUT_33_big_space(
	KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_L, KC_U, KC_Y, TO(_BASE),
	KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_N, KC_E, KC_I, KC_O,
	KC_LCTRL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_M, KC_COMM, KC_DOT, KC_SLSH,
  KC_TRNS, KC_TRNS,  KC_TRNS
  ),
};
