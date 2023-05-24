// Meme Modes
#include "tominabox1.h"
__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true;}
__attribute__((weak)) bool encoder_update_keymap(uint8_t index, bool clockwise) {return true;}
__attribute__((weak)) bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {return true;}

bool encoder_update_user(uint8_t index, bool clockwise) {
    return encoder_update_keymap(index, clockwise);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    // bool process_record_secrets(uint16_t keycode, keyrecord_t * record) {
    //     switch (keycode) {
    //         case KC_SECRET_1: // Secrets!  Externally defined strings, not stored in repo
    //             if (record->event.pressed) {
    //                 clear_mods();
    //                 clear_oneshot_mods();
    //                 send_string_with_delay(secrets[keycode - KC_SECRET_1], 100);
    //             }
    //             return false;
    //             break;
    //     }
    //     return true;
    // }

    return process_record_keymap(keycode, record) && process_record_secrets(keycode, record);
}
