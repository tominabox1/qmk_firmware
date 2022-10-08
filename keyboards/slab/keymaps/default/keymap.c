/* Copyright 2022 tjcampie
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
#include "analog.h"
int16_t max_pot_val = 1023;
int16_t max_ticks = 20;
int16_t pot_oldVal = 0;
int16_t pot_val    = 0;
bool moving     = false;
#define POT_TOLERANCE 50
#define POT_PIN F0
#include "print.h"


void matrix_init_user(void) {
    analogReference(ADC_REF_POWER);
}

void matrix_scan_user(void){
    pot_val   = (analogReadPin(POT_PIN));

    // If there is a big enough change, then we need to do something
    if (abs(pot_val - pot_oldVal) > POT_TOLERANCE) {
        moving = true;
        pot_oldVal = pot_val;
    }
    else{
        if (moving){
            // Do some fancy conversion to get 'absolute' position to num tap_codes to send
            // Reset moving to 0 so that we don't get multiple attempts to do this
            int num_ticks = ((float)pot_val/max_pot_val)*max_ticks;
            for (int i = 0; i<max_ticks;++i){
                tap_code(KC__VOLDOWN);
            }
            for (int i = 0; i<num_ticks;++i){
                tap_code(KC__VOLUP);
            }
            moving = false;
        }
    }
}

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
    KC_1, KC_2, KC_3, KC_4,
    KC_5, KC_6, KC_7, KC_8
    )
};
