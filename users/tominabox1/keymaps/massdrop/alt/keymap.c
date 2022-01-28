#include QMK_KEYBOARD_H
#include "tominabox1.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE]=LAYOUT_65_ansi_blocker(
    KC_GRV,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPACE,       TG(_GAME),
    KC_TAB,  KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_QUOT,    KC_LBRC, KC_RBRC, KC_BSPC,       KC_DEL,
    KC_LCAP, LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), TD(TD_DCAP), KC_H, RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O), KC_QUOT,          KC_ENT,  KC_P4,
    KC_LSFT, LT(_ADJUST,KC_Z), KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH,                   KC_RSFT,                KC_UP,               KC_P1,
    KC_LCTL, KC_LALT, KC_LGUI,                LT(_NUM_SYM,KC_SPC),                                 KC_RALT, MO(_ADJUST),                         KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_NUM_SYM]=LAYOUT_65_ansi_blocker(
    KC_GRV,  KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,    KC_F11, KC_F12,  KC_F13,       KC_INS,
    KC_TAB,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,   KC_0,    KC_LBRC, KC_RBRC, KC_BSPC,       KC_DEL,
    KC_LCAP, KC_EXLM, KC_AT, KC_HASH, TD(TD_DLR_LP), KC_PERC, KC_CIRC, TD(TD_AMP_RP), KC_ASTR, KC_EQUAL, KC_MINS, KC_QUOT,          KC_ENT,                                      KC_P4,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_UNDS, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH,                   KC_RSFT,                KC_UP,               KC_P1,
    KC_LCTL, KC_LALT, KC_LGUI,                LT(_NUM_SYM,KC_SPC),                                  KC_RALT, MO(_ADJUST),                         KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_GAME]=LAYOUT_65_ansi_blocker(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, TG(_GAME),
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME,
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_P,
    KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(_ADJUST),   KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_ADJUST] = LAYOUT_65_ansi_blocker(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, TO(_BASE),
    _______, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, _______,KC_UP,_______, KC_PSCR, KC_SLCK, KC_PAUS, _______, KC_END,
    _______, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,          _______, KC_VOLU,
    _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_PGUP, KC_VOLD,
    _______, _______, _______,                            _______,                            _______, _______, KC_HOME, KC_PGDN, KC_END
    )
};
