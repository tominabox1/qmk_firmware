/*
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

//Tap Dance Declarations
enum {
  WIN_CAPS = 0
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [WIN_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_CAPS)
// Other declarations would go here, separated by commas, if you have them
};

//In Layer declaration, add tap dance item in place of a key code
//


// Layer shorthand
enum layer {
  _main,
  _gaming,
  _FN,
  _FN2,
  _FN3,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /* custom Space with Arrows - layer 0
 * .-----------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      |   6    | 7      | 8      | 9      | 0      |  -     | =      | GRAVE  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    |  [     | Q      | W      | E      | R      |   T    | Y      | U      | I      | O      |  P     | ]      | GUI \  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |SFTCAPS |  DEL   | A      | S      | D      | F      |   G    | H      | J      | K      | L      |  ;:    |  '"    |SFTENT  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | HOME   | PG UP  | Z      | X      | C      | V      |   B    | N      | M      | ,      | .      |  /     |  UP    | END    |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | PG DN  | LALT   |  FN    |  LGUI  |      BACKSP     |      SPACE      |  FN2   |  FIND  | RIGHT  | DOWN   |CTRLRGHT|
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */

 [_main] = LAYOUT_ortho_5x14(
  KC_ESC,   		KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,     KC_7,     KC_8,    KC_9,    KC_0,       KC_MINS, KC_EQL,  KC_GRV, \
  KC_TAB,   		KC_LBRC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,     KC_U,    KC_I,    KC_O,       KC_P,    KC_RBRC, RGUI_T(KC_BSLS), \
  LSFT_T(KC_CAPS),  KC_DEL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_H,     KC_J,    KC_K,    KC_L,       KC_SCLN, KC_QUOT, RSFT_T(KC_ENT),  \
  KC_HOME,  		KC_PGUP, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_N,     KC_M,    KC_COMM, KC_DOT,     KC_SLSH, KC_UP,   KC_END, \
  KC_LCTL,  		KC_PGDN, KC_LALT, TT(2),   KC_LGUI, KC_BSPC, KC_BSPC,  KC_SPC,   KC_SPC,  TT(3),   LCTL(KC_F), KC_LEFT, KC_DOWN, RCTL_T(KC_RGHT)  \
 ),

/* custom gaming - layer 1
 * .-----------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      |   6    | 7      | 8      | 9      | 0      |  -     | =      | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    |  [     | Q      | W      | E      | R      |   T    | Y      | U      | I      | O      |  P     | ]      | GUI \  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |SFTCAPS |        | A      | S      | D      | F      |   G    | H      | J      | K      | L      |  ;:    |  '"    |SFTENT  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | HOME   | PG UP  | Z      | X      | C      | V      |   B    | N      | M      | ,      | .      |  /     |  UP    | END    |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | PG DN  |        |  FN    |        |      BACKSP     |      SPACE      |  FN2   |  FIND  | RIGHT  | DOWN   |CTRLRGHT|
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */

 [_gaming] = LAYOUT_ortho_5x14(
  KC_ESC,   		KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,     KC_7,     KC_8,    KC_9,    KC_0,       KC_MINS, KC_EQL,  KC_BSPC, \
  KC_TAB,   		KC_LBRC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,     KC_U,    KC_I,    KC_O,       KC_P,    KC_RBRC, RGUI_T(KC_BSLS), \
  LSFT_T(KC_CAPS),  KC_DEL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_H,     KC_J,    KC_K,    KC_L,       KC_SCLN, KC_QUOT, RSFT_T(KC_ENT),  \
  KC_HOME,  		KC_PGUP, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_N,     KC_M,    KC_COMM, KC_DOT,     KC_SLSH, KC_UP,   KC_END, \
  KC_LCTL,  		KC_PGDN, KC_NO,   TT(2),   KC_NO,   KC_SPC,  KC_SPC,   KC_SPC,   KC_SPC,  TT(3),   LCTL(KC_F), KC_LEFT, KC_DOWN, RCTL_T(KC_RGHT)  \
 ),


/* FUNCTION - layer 2
 * .-----------------------------------------------------------------------------------------------------------------------------.
 * |        |   F1   |   F2   |   F3   |   F4   |   F5   |   F6   |  F7    |   F8   |   F9   |  F10   |   F11  |  F12   | CALC   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | GRAVE  |        |  UP    |        |        |        |        |        |        |    7   |   8    |   9    |  \     |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | PRV TR |  LEFT  |  DOWN  |  RIGHT |        |        |        |        |        |    4   |   5    |    6   |  *     |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | PLAY   |        |        |        |        |        |        |        | MUTE   |    1   |   2    |   3    |  -     |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
 * | NXT TR |PRNTSCN |        |        |        | PAUSE  |        | ENTER  |        |    0   |  .     |        |  +     | FN3    |
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */


 [_FN] = LAYOUT_ortho_5x14(
  _______, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9, KC_F10,  KC_F11,  KC_F12,  KC_CALC, \
  KC_GRV,  _______,  KC_UP,   _______, _______, _______, _______, _______, _______, KC_7,  KC_8,    KC_9,    KC_PSLS, _______, \
  KC_MPRV, KC_LEFT,  KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, KC_4,  KC_5,    KC_6,    KC_PAST, _______, \
  KC_MPLY, _______,  _______, _______, _______, _______, _______, _______, KC_MUTE, KC_1,  KC_2,    KC_3,    KC_PMNS, _______, \
  KC_MNXT, KC_PSCR,  _______, _______, _______, KC_PAUS, _______, KC_ENT,  _______, KC_0,  KC_DOT,  _______, KC_PPLS, MO(4)  \
 ),

/* FUNCTION2 - layer 3
 * .-----------------------------------------------------------------------------------------------------------------------------.
 * |        |   F1   |   F2   |   F3   |   F4   |   F5   |   F6   |  F7    |   F8   |   F9   |  F10   |   F11  |  F12   | MENU   |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */


 [_FN2] = LAYOUT_ortho_5x14(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_APP,   \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
 ),

/* FUNCTION3 - layer 4
 * .-----------------------------------------------------------------------------------------------------------------------------.
 * |DefLayr0|DefLayr1|        |        |        |        |        |        |        |        |        |        |        | RESET  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |RGBHUE+ |RGBMODE+|BRIGHT+ |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |RGBHUE- |RGBMODE-|BRIGHT- |        |
 * '-----------------------------------------------------------------------------------------------------------------------------'
 */


 [_FN3] = LAYOUT_ortho_5x14(
  DF(0),   DF(1),   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,   \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUI, RGB_MODE_FORWARD, RGB_VAI, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUD, RGB_MODE_REVERSE, RGB_VAD, _______ \
 ),

 
};
