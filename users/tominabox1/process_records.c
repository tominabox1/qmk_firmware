// Meme Modes
#include "tominabox1.h"
#if (__has_include("secrets.h") && !defined(NO_SECRETS))
#    include "secrets.h"
#else
static const char *const secrets[] = {"test1"};
#endif
__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true;}
__attribute__((weak)) bool encoder_update_keymap(uint8_t index, bool clockwise) {return true;}
__attribute__((weak)) bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {return true;}
uint8_t mod_state;

bool encoder_update_user(uint8_t index, bool clockwise) {
    return encoder_update_keymap(index, clockwise);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

        switch (keycode) {
            case KC_SECRET_1: // Secrets!  Externally defined strings, not stored in repo
                if (record->event.pressed) {
                    clear_mods();
                    clear_oneshot_mods();
                    send_string_with_delay(secrets[keycode - KC_SECRET_1], 100);
                }
                return false;
                break;

            case KC_COMM:
                if (record->event.pressed) {
                    mod_state = get_mods();                                                                         // save mod state for comparison and later restoration
                    if ((mod_state & MOD_MASK_CTRL) && (mod_state & MOD_MASK_SHIFT)) {                              // if either ctrl is held
                        unregister_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_RCTL) | MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)); // unregister both ctrl
                        tap_code16(KC_SCLN);                                                                        // send ":" unmolested
                        set_mods(mod_state);                                                                        // restore mod state
                        return false;                                                                               // done processing
                    }

                    else if (mod_state & MOD_MASK_CTRL) {                     // if either ctrl is held
                        unregister_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_RCTL)); // unregister both ctrl
                        tap_code16(KC_COLN);                                  // send ":" unmolested
                        set_mods(mod_state);                                  // restore mod state
                        return false;                                         // done processing
                    }

                    else {                   // else, if ctrl isn't held
                        tap_code16(KC_COMM); // send "/"
                        return false;        // done processing
                    }
                }
                return false;
                break;
        }
    return process_record_keymap(keycode, record) && process_record_secrets(keycode, record);
}
