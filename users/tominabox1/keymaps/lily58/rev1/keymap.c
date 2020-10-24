#include QMK_KEYBOARD_H
#define QMK_ESC_OUTPUT C6  // usually COL
#define QMK_ESC_INPUT F6  // usually ROW
#define QMK_LED BO

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

#define _QWERTY 0
#define _FKEY 1

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  BOMB_DROP,
};

enum {
    TD_GESC,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_GESC] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_ESC),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_QWERTY] = LAYOUT( \
  KC_ESC, KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV, \
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    BOMB_DROP,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, \
  KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, MO(_FKEY),  KC_NO,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, \
                             KC_GRV, KC_NO,KC_SPC, KC_SPC,   KC_ENT,   RAISE,   KC_BSPC, KC_RGUI \
),
[_FKEY] = LAYOUT( \
  KC_F1,   KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV, \
  KC_F7,   KC_F8,   KC_F9,    KC_E,    KC_R,    BOMB_DROP,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, \
  KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, MO(_FKEY),  KC_NO,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, \
                             DM_REC1, DM_REC2,KC_SPC, DM_PLY2,   KC_ENT,   RAISE,   KC_BSPC, KC_RGUI \
),
};

int RGB_current_mode;

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BOMB_DROP:
        if (record->event.pressed) {
            tap_code(KC_5);
            tap_code(KC_G);
        } else {

        }
    break;
    }
    return true;
};

