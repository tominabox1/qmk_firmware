/* Copyright 2018 Jumail Mundekkat
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

#define L1BS LT(2, KC_BSPC)
#define LSUP LSFT_T(KC_UP)
#define CTLL LCTL_T(KC_LEFT)
#define ECTL LCTL_T(KC_ESC)
#define ALLM ALL_T(KC_MINS)
#define SCLS LT(3, KC_SCLN)

// Establishes tap dance keys
enum {
  SPC_ENT = 0,
  SP_PUNC,
  NXT_PRV,
  DSH_UND,
  PLS_EQL,
  MIN_GRV,
  NML_PLS
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [SPC_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_ENT),
  [SP_PUNC] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_SCLN),
  [NXT_PRV] = ACTION_TAP_DANCE_DOUBLE(KC_MNXT,KC_MPRV),
  [DSH_UND] = ACTION_TAP_DANCE_DOUBLE(KC_PMNS,KC_UNDS),
  [PLS_EQL] = ACTION_TAP_DANCE_DOUBLE(KC_PPLS,KC_EQL),
  [MIN_GRV] = ACTION_TAP_DANCE_DOUBLE(KC_MINS,KC_GRV),
  [NML_PLS] = ACTION_TAP_DANCE_DOUBLE(KC_EQL,KC_NLCK)
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* [0] BASE
 * ,---------------------------------------------------------------------------------------------------------------,
 * | ESC  |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   | ` ~  | NMLK | PLAY | NEXT |  /   |
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      | PREV |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |  Q   |  W   |  E   |  R   |  T   |  Y   |  U   |  I   |  O   |  P   |  \   |  7   |  8   |  9   |  *   |
 * |      |      |      |      |      |      |      |      |      |      |      | RGUI | HOME | UP   |PGUP  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | CAPS |  A   |  S   |  D   |  F   |  G   |  H   |  J   |  K   |  L   |  '"  |ENTER |  4   |  5   |  6   |  -   |
 * | SHIFT|      |      |      |      |      |      |      |      |      |  ;:  |SHIFT | LEFT |      | RIGHT|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  Z   |  X   |  C   |  V   |  B   |  N   |  M   |  ,   |  .   |  /   |  Up  |  1   |  2   |  3   |  +   |
 * | DEL  |      |      |      |      |      |      |      |      |      |      |      | END  | DOWN |PGDN  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  Backspace  |    Space    |      |      | Left | Down | Right|  0   |  .   |      |
 * | Ctrl | Alt  | LYR2 | GUI  |             |             | LYR3 | FIND |      |      |      |INSERT|      |ENTER |
 * `---------------------------------------------------------------------------------------------------------------'
 */

  [0] = LAYOUT(
    KC_ESC,   	     KC_1,    KC_2,     KC_3,     KC_4,            KC_5,             KC_6,    KC_7,    KC_8,           KC_9,     KC_0,     TD(MIN_GRV),     TD(NML_PLS), KC_MPLY, TD(NXT_PRV), KC_PSLS,
    KC_TAB,          KC_Q,    KC_W,     KC_E,     KC_R,            KC_T,             KC_Y,    KC_U,    KC_I,           KC_O,     KC_P,     RGUI_T(KC_BSLS), KC_P7,       KC_P8,   KC_P9,       RALT_T(KC_PAST),
    LSFT_T(KC_CAPS), KC_A,    KC_S,     KC_D,     KC_F,            KC_G,             KC_H,    KC_J,    KC_K,           KC_L,     KC_SCLN,  KC_QUOT,         KC_P4,       KC_P5,   KC_P6,       TD(DSH_UND),
    KC_DEL,          KC_Z,    KC_X,     KC_C,     KC_V,            KC_B,             KC_N,    KC_M,    KC_COMM,        KC_DOT,   KC_SLSH,  KC_UP,           KC_P1,       KC_P2,   KC_P3,       TD(PLS_EQL),
    KC_LCTL,  	     KC_LALT, TT(2),    KC_LGUI,  LALT_T(KC_BSPC), LALT_T(KC_BSPC),  KC_SPC,  KC_SPC,  RSFT_T(KC_ENT), TT(3),    KC_LEFT,  KC_DOWN,         KC_RIGHT,    KC_0,    KC_PDOT,     RCTL_T(KC_ENT)
  ),

/* [1] GAME
 * ,---------------------------------------------------------------------------------------------------------------,
 * | ESC  |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   | BKSPC| NMLK | PLAY | NEXT |  /   |
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      | PREV |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |  Q   |  W   |  E   |  R   |  T   |  Y   |  U   |  I   |  O   |  P   |  \   |  7   |  8   |  9   |  *   |
 * |      |      |      |      |      |      |      |      |      |      |      |      | HOME | UP   |PGUP  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | CAPS |  A   |  S   |  D   |  F   |  G   |  H   |  J   |  K   |  L   |  '"  |ENTER |  4   |  5   |  6   |  -   |
 * | SHIFT|      |      |      |      |      |      |      |      |      |  ;:  |SHIFT | LEFT |      | RIGHT|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  Z   |  X   |  C   |  V   |  B   |  N   |  M   |  ,   |  .   |  /   |  Up  |  1   |  2   |  3   |  +   |
 * | DEL  |      |      |      |      |      |      |      |      |      |      |      | END  | DOWN |PGDN  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  Space      |    Space    |      |      | Left | Down | Right|  0   |  .   |      |
 * | Ctrl | Alt  | LYR2 | GUI  |             |             | LYR3 | FIND |      |      |      |INSERT|      |ENTER |
 * `---------------------------------------------------------------------------------------------------------------'
 */

  [1] = LAYOUT(
    KC_ESC,   	     KC_1,     KC_2,     KC_3,     KC_4,    KC_5,    KC_6,    KC_7,    KC_8,     KC_9,       KC_0,     	   KC_BSPC,   	   KC_NLCK,    KC_MPLY,   TD(NXT_PRV), KC_PSLS,
    KC_TAB,    	     KC_Q,     KC_W,     KC_E,     KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,       KC_P,     	   KC_BSLS,  	   KC_P7,      KC_P8,     KC_P9,       RALT_T(KC_PAST),
    LSFT_T(KC_CAPS), KC_A,     KC_S,     KC_D,     KC_F,    KC_G,    KC_H,    KC_J,    KC_K,     KC_L,       TD(SP_PUNC),  RSFT_T(KC_ENT), KC_P4,      KC_P5,     KC_P6,       TD(DSH_UND),
    KC_DEL,  	     KC_Z,     KC_X,     KC_C,     KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,     KC_SLSH,      KC_UP,    	   KC_P1,      KC_P2,     KC_P3,       TD(PLS_EQL),
    KC_LCTL,         KC_LALT,  KC_LGUI,  TT(2),    KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  TT(3),    LCTL(KC_F), KC_LEFT,      KC_DOWN,  	   KC_RIGHT,   KC_0,      KC_PDOT,     RCTL_T(KC_ENT)
  ),

/* [2] SYMBOL
 * ,---------------------------------------------------------------------------------------------------------------,
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      | pipe |
 * |------+-------------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |  [   |   ]  |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |  ;:  |      |      |      |      |      |
 * | PREV |      |      |      |      |      |      |      |      |      |      |      |      |      |      |   _  |
 * |------+------|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | MUTE |      |      |      |      |      |      |      |      |
 * | PLAY |      |      |      |      |      |      |      |      |      |      |      |      |      |      |   =  |
 * |------+------|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  PRINT      |  PRINT      |      |      |      |      |      |      |      |      |
 * | NEXT |      |      |      |  SCREEN     |  SCREEN     |      |      |      |      |      |      |      | lyr3 |
 * `---------------------------------------------------------------------------------------------------------------'
 */

	[2] = LAYOUT(
    _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,  _______,  KC_PIPE,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_LBRC,  KC_RBRC,  _______,  _______,  _______,  _______,  _______,
    KC_MPRV,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_SCLN,  _______,  _______,  _______,  _______,  KC_UNDS,
    KC_MPLY,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MUTE,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_EQL,
    KC_MNXT,  _______,  _______,  _______,  _______,  _______,  KC_PSCR,  KC_PSCR,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  MO(3)
  ),

/* [3] SYSTEM
 * ,---------------------------------------------------------------------------------------------------------------,
 * |      | F11  | F12  | F13  | F14  | F15  |  F16 |  F17 | F18  | F19  | F20  |      |      |      |      |RESET |
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+-------------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      | DEF  |      |      |      |
 * |      |      |      |      |      |      |      |      |      |      |      |      | LYR1 |      |      |      |
 * |------+------|------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |             |      |      |      |      |      | DEF  |      |      |
 * |      |      |      |      |             |             |      |      |      |      |      | LYR0 |      |      |
 * `---------------------------------------------------------------------------------------------------------------'
 */

	[3] = LAYOUT(
    _______,  KC_F11,   KC_F12,   KC_F13,   KC_F14,  KC_F15,   KC_F16,   KC_F17,   KC_F18,   KC_F19,   KC_F20,   _______,  _______,  _______,  _______,  RESET,
    _______,  _______,  _______,  _______,  _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  DF(1),    _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  DF(0),    _______,  _______
  ), 

};

/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
*/
