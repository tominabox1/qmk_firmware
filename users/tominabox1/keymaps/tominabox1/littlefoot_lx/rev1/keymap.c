
#include QMK_KEYBOARD_H
#include "quantum.h"

#include "tominabox1.h"

enum littlefoot_keycodes {
    MUTE = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_ESC,   KC_F1,   KC_F2, KC_F3,   KC_F4,   KC_MPRV,   KC_MPLY,   KC_MNXT,   KC_MPLY,   MUTE,
  //,-----------------------------------------------------------------------------------------------------------.
                  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,KC_QUOTE,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
               LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), TD(TD_DCAP), KC_H, RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O),
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
                  LT(_NAV, KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M, KC_COMM,  KC_DOT,     KC_SLSH,
    KC_NUM_SPC
  ),

  [_NUM_SYM] = LAYOUT(
    KC_ESC,   KC_F1, KC_F2,   KC_F3,   KC_F4,   LWIN(LCTL(KC_LEFT)),   LWIN(KC_TAB),   LWIN(LCTL(KC_RIGHT)),   KC_MPLY,   KC_F10,
    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0, //0 + 9 = KC_BSPC
    KC_EXLM,    KC_AT,  KC_HASH,   TD(TD_DLR_LP), KC_PERC, KC_CIRC, TD(TD_AMP_RP),  KC_ASTR,   KC_EQL,  KC_MINS,
    KC_GRAVE,  KC_LCBR,  KC_LBRC,  KC_LPRN,   KC_UNDS, KC_RPRN,  KC_RBRC,  KC_RCBR,  KC_DOT,  KC_SLSH,
    KC_TRNS
  ),

  [_NAV] = LAYOUT(
    KC_F1,   KC_F2, KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   TG(_GAME),
    KC_PGDN,   KC_UP,  KC_PGUP,  KC_NO,  KC_NO,  KC_GRV ,KC_PGDN,    KC_UP,  KC_PGUP,    KC_SCLN,
    KC_LEFT,  KC_DOWN,  KC_RIGHT,  KC_NO,  SPONGEBOB,  KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RGHT,   KC_END,
    KC_TRNS,  KC_NO,  KC_NO,  KC_NO,  LCTL(KC_F12),  KC_MINS,    KC_RO,  KC_COMM,   KC_DOT,  KC_BSLS,
    KC_TRNS
  ),

  [_GAME] = LAYOUT(
  KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_L, KC_U, KC_Y, TG(_GAME),
  KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O,
  KC_LCTRL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_M, KC_COMM, KC_DOT, KC_SLSH,
  KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO, KC_NO,KC_NO,KC_NO,
    KC_SPACE
  ),
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record){
    switch (keycode){
        case MUTE:
            if(record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_F12);
                unregister_code(KC_LCTL);
                unregister_code(KC_F12);
                return false;
            }
        break;
    }
    return true;
}
