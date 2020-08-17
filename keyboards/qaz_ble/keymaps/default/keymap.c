/*
Copyright 2018 Sekigon

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "app_ble_func.h"

enum layers{
  _BASE,
  _NUM_SYM,
  _NAV
};

enum custom_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  ADJUST,
  KANJI,
  RGBRST,
  AD_WO_L, /* Start advertising without whitelist  */
  BLE_DIS, /* Disable BLE HID sending              */
  BLE_EN, /* Enable BLE HID sending               */
  USB_DIS, /* Disable USB HID sending              */
  USB_EN, /* Enable USB HID sending               */
  DELBNDS, /* Delete all bonding                   */
  ADV_ID0, /* Start advertising to PeerID 0        */
  ADV_ID1, /* Start advertising to PeerID 1        */
  ADV_ID2, /* Start advertising to PeerID 2        */
  ADV_ID3, /* Start advertising to PeerID 3        */
  ADV_ID4, /* Start advertising to PeerID 4        */
  BATT_LV, /* Display battery level in milli volts */
  DEL_ID0, /* Delete bonding of PeerID 0           */
  DEL_ID1, /* Delete bonding of PeerID 1           */
  DEL_ID2, /* Delete bonding of PeerID 2           */
  DEL_ID3, /* Delete bonding of PeerID 3           */
  DEL_ID4, /* Delete bonding of PeerID 4           */
  ENT_DFU, /* Start bootloader                     */
  ENT_SLP, /* Deep sleep mode                      */
};

// #define KC_RST   ENT_DFU
// #define KC_BATT  BATT_LV
// #define KC_BTON  BLE_EN
// #define KC_BTOF  BLE_DIS
// #define KC_USBON USB_EN
// #define KC_USBOF USB_DIS
// #define KC_BTNEW AD_WO_L
// #define KC_BTID0 ADV_ID0
// #define KC_BTID1 ADV_ID1
// #define KC_BTID2 ADV_ID2
// #define KC_BTID3 ADV_ID3
// #define KC_BTID4 ADV_ID4

enum combo_events {
  COMBO_BSPC,
  COMBO_NUMBAK,
  COMBO_TAB,
  COMBO_ESC,
  COMBO_DEL,
};

#define KC_NUM_SPC LT(_NUM_SYM, KC_SPC)
#define KC_GA LGUI_T(KC_A)
#define KC_AS LALT_T(KC_R)
#define KC_CD LCTL_T(KC_S)
#define KC_SF LSFT_T(KC_T)
#define KC_SJ RSFT_T(KC_N)
#define KC_CK RCTL_T(KC_E)
#define KC_AL RALT_T(KC_I)
#define KC_GSCLN RGUI_T(KC_O)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_space(
    KC_Q,   KC_W,   KC_F,   KC_P,   KC_G,   KC_J,   KC_L,    KC_U,   KC_Y,     KC_QUOT,
    KC_GA,  KC_AS,  KC_CD,  KC_SF,   KC_D,   KC_H,  KC_SJ,   KC_CK,  KC_AL, KC_GSCLN,
    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_K,   KC_M, KC_COMM, KC_DOT,
    KC_NO, KC_NO, KC_NO, KC_BSPC, LT(_NUM_SYM,KC_SPACE), KC_ENT, KC_RGUI, KC_RCTL
  ),

  [_NUM_SYM] = LAYOUT_split_space(
    KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
    KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_EQUAL, KC_MINS,
    KC_LCBR, KC_LBRC, KC_LPRN, KC_UNDS, KC_RPRN, KC_RBRC, KC_RCBR, KC_SCLN, KC_QUOTE,
    ENT_DFU, USB_EN, USB_DIS, KC_TRNS, KC_TRNS, KC_TRNS, AD_WO_L, DELBNDS
  )
};

#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_bspc[] = {KC_Y, KC_QUOT, COMBO_END};
const uint16_t PROGMEM combo_numbak[] = {KC_0, KC_9, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_F, KC_W, COMBO_END};
const uint16_t PROGMEM combo_del[] = {KC_MINS, KC_EQL, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO_BSPC] = COMBO(combo_bspc,KC_BSPC),
  [COMBO_NUMBAK] = COMBO(combo_numbak,KC_BSPC),
  [COMBO_TAB] = COMBO(combo_tab,KC_TAB),
  [COMBO_ESC] = COMBO(combo_esc,KC_ESC),
  [COMBO_DEL] = COMBO(combo_del,KC_DEL),

};
#endif

static inline void update_change_layer(bool pressed, uint8_t layer1, uint8_t layer2, uint8_t layer3) {

  pressed ? layer_on(layer1) : layer_off(layer1);
  IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2) ? layer_on(layer3) : layer_off(layer3);
}

void keyboard_post_init_user(void) {
  set_usb_enabled(false);
}

int RGB_current_mode;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  char str[16];

  bool result = true;

  if (record->event.pressed) {
    switch (keycode) {
    case DELBNDS:
      delete_bonds();
      result = false;
      break;
    case AD_WO_L:
      restart_advertising_wo_whitelist();
      result = false;
      break;
    case USB_EN:
      set_usb_enabled(true);
      result = false;
      break;
    case USB_DIS:
      set_usb_enabled(false);
      result = false;
      break;
    case BLE_EN:
      set_ble_enabled(true);
      result = false;
      break;
    case BLE_DIS:
      set_ble_enabled(false);
      result = false;
      break;
    case ADV_ID0:
      restart_advertising_id(0);
      result = false;
      break;
    case ADV_ID1:
      restart_advertising_id(1);
      result = false;
      break;
    case ADV_ID2:
      restart_advertising_id(2);
      result = false;
      break;
    case ADV_ID3:
      restart_advertising_id(3);
      result = false;
      break;
    case ADV_ID4:
      restart_advertising_id(4);
      result = false;
      break;
    case DEL_ID0:
      delete_bond_id(0);
      result = false;
      break;
    case DEL_ID1:
      delete_bond_id(1);
      result = false;
      break;
    case DEL_ID2:
      delete_bond_id(2);
      result = false;
      break;
    case DEL_ID3:
      delete_bond_id(3);
      result = false;
      break;
    case BATT_LV:
      sprintf(str, "%4dmV", get_vcc());
      send_string(str);
      result = false;
      break;
    case ENT_DFU:
      bootloader_jump();
      result = false;
      break;
    }
  }

  return result;
}
