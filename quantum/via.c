/* Copyright 2019 Jason Williams (Wilba)
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

#ifndef RAW_ENABLE
#    error "RAW_ENABLE is not enabled"
#endif

#ifndef DYNAMIC_KEYMAP_ENABLE
#    error "DYNAMIC_KEYMAP_ENABLE is not enabled"
#endif

<<<<<<< HEAD
#ifndef VIAL_ENABLE
#error Compiling VIA keymaps is not supported with the vial-qmk repo, please use qmk_firmware instead, or set VIAL_ENABLE=yes
#endif

// If VIA_CUSTOM_LIGHTING_ENABLE is not defined, then VIA_QMK_BACKLIGHT_ENABLE is set
// if BACKLIGHT_ENABLE is set, so handling of QMK Backlight values happens here by default.
// if VIA_CUSTOM_LIGHTING_ENABLE is defined, then VIA_QMK_BACKLIGHT_ENABLE must be explicitly
// set in keyboard-level config.h, so handling of QMK Backlight values happens here
#if defined(BACKLIGHT_ENABLE) && !defined(VIA_CUSTOM_LIGHTING_ENABLE)
#    define VIA_QMK_BACKLIGHT_ENABLE
#endif

// If VIA_CUSTOM_LIGHTING_ENABLE is not defined, then VIA_QMK_RGBLIGHT_ENABLE is set
// if RGBLIGHT_ENABLE is set, so handling of QMK RGBLIGHT values happens here by default.
// If VIA_CUSTOM_LIGHTING_ENABLE is defined, then VIA_QMK_RGBLIGHT_ENABLE must be explicitly
// set in keyboard-level config.h, so handling of QMK RGBLIGHT values happens here
#if defined(RGBLIGHT_ENABLE) && !defined(VIA_CUSTOM_LIGHTING_ENABLE)
#    define VIA_QMK_RGBLIGHT_ENABLE
#endif

#if defined(RGB_MATRIX_ENABLE) && !defined(VIA_QMK_RGBLIGHT_ENABLE) && !defined(VIA_CUSTOM_LIGHTING_ENABLE) && !defined(VIALRGB_ENABLE)
#    define VIA_QMK_RGB_MATRIX_ENABLE
#endif

=======
>>>>>>> master
#include "quantum.h"

#include "via.h"

#include "raw_hid.h"
#include "dynamic_keymap.h"
#include "eeprom.h"
#include "version.h" // for QMK_BUILDDATE used in EEPROM magic

<<<<<<< HEAD
#ifdef VIAL_ENABLE
#include "vial.h"
#endif

#ifdef VIALRGB_ENABLE
#include "vialrgb.h"
#endif

// Forward declare some helpers.
#if defined(VIA_QMK_BACKLIGHT_ENABLE)
void via_qmk_backlight_set_value(uint8_t *data);
void via_qmk_backlight_get_value(uint8_t *data);
#endif

#if defined(VIA_QMK_RGBLIGHT_ENABLE)
void via_qmk_rgblight_set_value(uint8_t *data);
void via_qmk_rgblight_get_value(uint8_t *data);
#endif

#if defined(VIA_QMK_RGB_MATRIX_ENABLE)
void via_qmk_rgb_matrix_set_value(uint8_t *data);
void via_qmk_rgb_matrix_get_value(uint8_t *data);
void eeconfig_update_rgb_matrix(void);
=======
#if defined(RGB_MATRIX_ENABLE)
#    include <lib/lib8tion/lib8tion.h>
>>>>>>> master
#endif

// Can be called in an overriding via_init_kb() to test if keyboard level code usage of
// EEPROM is invalid and use/save defaults.
bool via_eeprom_is_valid(void) {
#ifdef VIAL_ENABLE
    uint8_t magic0 = BUILD_ID & 0xFF;
    uint8_t magic1 = (BUILD_ID >> 8) & 0xFF;
    uint8_t magic2 = (BUILD_ID >> 16) & 0xFF;
#else
    char *  p      = QMK_BUILDDATE; // e.g. "2019-11-05-11:29:54"
    uint8_t magic0 = ((p[2] & 0x0F) << 4) | (p[3] & 0x0F);
    uint8_t magic1 = ((p[5] & 0x0F) << 4) | (p[6] & 0x0F);
    uint8_t magic2 = ((p[8] & 0x0F) << 4) | (p[9] & 0x0F);
#endif

    return (eeprom_read_byte((void *)VIA_EEPROM_MAGIC_ADDR + 0) == magic0 && eeprom_read_byte((void *)VIA_EEPROM_MAGIC_ADDR + 1) == magic1 && eeprom_read_byte((void *)VIA_EEPROM_MAGIC_ADDR + 2) == magic2);
}

// Sets VIA/keyboard level usage of EEPROM to valid/invalid
// Keyboard level code (eg. via_init_kb()) should not call this
void via_eeprom_set_valid(bool valid) {
#ifdef VIAL_ENABLE
    uint8_t magic0 = BUILD_ID & 0xFF;
    uint8_t magic1 = (BUILD_ID >> 8) & 0xFF;
    uint8_t magic2 = (BUILD_ID >> 16) & 0xFF;
#else
    char *  p      = QMK_BUILDDATE; // e.g. "2019-11-05-11:29:54"
    uint8_t magic0 = ((p[2] & 0x0F) << 4) | (p[3] & 0x0F);
    uint8_t magic1 = ((p[5] & 0x0F) << 4) | (p[6] & 0x0F);
    uint8_t magic2 = ((p[8] & 0x0F) << 4) | (p[9] & 0x0F);
#endif

    eeprom_update_byte((void *)VIA_EEPROM_MAGIC_ADDR + 0, valid ? magic0 : 0xFF);
    eeprom_update_byte((void *)VIA_EEPROM_MAGIC_ADDR + 1, valid ? magic1 : 0xFF);
    eeprom_update_byte((void *)VIA_EEPROM_MAGIC_ADDR + 2, valid ? magic2 : 0xFF);
}

// Override this at the keyboard code level to check
// VIA's EEPROM valid state and reset to defaults as needed.
// Used by keyboards that store their own state in EEPROM,
// for backlight, rotary encoders, etc.
// The override should not set via_eeprom_set_valid(true) as
// the caller also needs to check the valid state.
__attribute__((weak)) void via_init_kb(void) {}

// Called by QMK core to initialize dynamic keymaps etc.
void via_init(void) {
    // Let keyboard level test EEPROM valid state,
    // but not set it valid, it is done here.
    via_init_kb();
    via_set_layout_options_kb(via_get_layout_options());

    // If the EEPROM has the magic, the data is good.
    // OK to load from EEPROM.
    if (!via_eeprom_is_valid()) {
        eeconfig_init_via();
    }
}

void eeconfig_init_via(void) {
    // set the magic number to false, in case this gets interrupted
    via_eeprom_set_valid(false);
    // This resets the layout options
    via_set_layout_options(VIA_EEPROM_LAYOUT_OPTIONS_DEFAULT);
    // This resets the keymaps in EEPROM to what is in flash.
    dynamic_keymap_reset();
    // This resets the macros in EEPROM to nothing.
    dynamic_keymap_macro_reset();
    // Save the magic number last, in case saving was interrupted
    via_eeprom_set_valid(true);
}

// This is generalized so the layout options EEPROM usage can be
// variable, between 1 and 4 bytes.
uint32_t via_get_layout_options(void) {
    uint32_t value = 0;
    // Start at the most significant byte
    void *source = (void *)(VIA_EEPROM_LAYOUT_OPTIONS_ADDR);
    for (uint8_t i = 0; i < VIA_EEPROM_LAYOUT_OPTIONS_SIZE; i++) {
        value = value << 8;
        value |= eeprom_read_byte(source);
        source++;
    }
    return value;
}

__attribute__((weak)) void via_set_layout_options_kb(uint32_t value) {}

void via_set_layout_options(uint32_t value) {
    via_set_layout_options_kb(value);
    // Start at the least significant byte
    void *target = (void *)(VIA_EEPROM_LAYOUT_OPTIONS_ADDR + VIA_EEPROM_LAYOUT_OPTIONS_SIZE - 1);
    for (uint8_t i = 0; i < VIA_EEPROM_LAYOUT_OPTIONS_SIZE; i++) {
        eeprom_update_byte(target, value & 0xFF);
        value = value >> 8;
        target--;
    }
}

#if defined(AUDIO_ENABLE)
float via_device_indication_song[][2] = SONG(STARTUP_SOUND);
#endif // AUDIO_ENABLE

// Used by VIA to tell a device to flash LEDs (or do something else) when that
// device becomes the active device being configured, on startup or switching
// between devices. This function will be called six times, at 200ms interval,
// with an incrementing value starting at zero. Since this function is called
// an even number of times, it can call a toggle function and leave things in
// the original state.
__attribute__((weak)) void via_set_device_indication(uint8_t value) {
#if defined(BACKLIGHT_ENABLE)
    backlight_toggle();
#endif // BACKLIGHT_ENABLE
#if defined(RGBLIGHT_ENABLE)
    rgblight_toggle_noeeprom();
#endif // RGBLIGHT_ENABLE
#if defined(RGB_MATRIX_ENABLE)
    rgb_matrix_toggle_noeeprom();
#endif // RGB_MATRIX_ENABLE
#if defined(AUDIO_ENABLE)
    if (value == 0) {
        wait_ms(10);
        PLAY_SONG(via_device_indication_song);
    }
#endif // AUDIO_ENABLE
}

// Called by QMK core to process VIA-specific keycodes.
bool process_record_via(uint16_t keycode, keyrecord_t *record) {
    // Handle macros
    if (record->event.pressed) {
<<<<<<< HEAD
        if (keycode >= MACRO00 && keycode <= MACRO00 + DYNAMIC_KEYMAP_MACRO_COUNT - 1) {
            uint8_t id = keycode - MACRO00;
=======
        if (keycode >= QK_MACRO && keycode <= QK_MACRO_MAX) {
            uint8_t id = keycode - QK_MACRO;
>>>>>>> master
            dynamic_keymap_macro_send(id);
            return false;
        }
    }

    return true;
}

//
// via_custom_value_command() has the default handling of custom values for Core modules.
// If a keyboard is using the default Core modules, it does not need to be overridden,
// the VIA keyboard definition will have matching channel/IDs.
//
// If a keyboard has some extra custom values, then via_custom_value_command_kb() can be
// overridden to handle the extra custom values, leaving via_custom_value_command() to
// handle the custom values for Core modules.
//
// If a keyboard has custom values and code that are overlapping with Core modules,
// then via_custom_value_command() can be overridden and call the same functions
// as the default implementation, or do whatever else is required.
//
// DO NOT call raw_hid_send() in the override function.
//

// This is the default handler for "extra" custom values, i.e. keyboard-specific custom values
// that are not handled by via_custom_value_command().
__attribute__((weak)) void via_custom_value_command_kb(uint8_t *data, uint8_t length) {
    // data = [ command_id, channel_id, value_id, value_data ]
    uint8_t *command_id = &(data[0]);
    // Return the unhandled state
    *command_id = id_unhandled;
}

// This is the default handler for custom value commands.
// It routes commands with channel IDs to command handlers as such:
//
//      id_qmk_backlight_channel    ->  via_qmk_backlight_command()
//      id_qmk_rgblight_channel     ->  via_qmk_rgblight_command()
//      id_qmk_rgb_matrix_channel   ->  via_qmk_rgb_matrix_command()
//      id_qmk_audio_channel        ->  via_qmk_audio_command()
//
__attribute__((weak)) void via_custom_value_command(uint8_t *data, uint8_t length) {
    // data = [ command_id, channel_id, value_id, value_data ]
    uint8_t *channel_id = &(data[1]);

#if defined(BACKLIGHT_ENABLE)
    if (*channel_id == id_qmk_backlight_channel) {
        via_qmk_backlight_command(data, length);
        return;
    }
#endif // BACKLIGHT_ENABLE

#if defined(RGBLIGHT_ENABLE)
    if (*channel_id == id_qmk_rgblight_channel) {
        via_qmk_rgblight_command(data, length);
        return;
    }
#endif // RGBLIGHT_ENABLE

#if defined(RGB_MATRIX_ENABLE)
    if (*channel_id == id_qmk_rgb_matrix_channel) {
        via_qmk_rgb_matrix_command(data, length);
        return;
    }
#endif // RGBLIGHT_ENABLE

#if defined(AUDIO_ENABLE)
    if (*channel_id == id_qmk_audio_channel) {
        via_qmk_audio_command(data, length);
        return;
    }
#endif // AUDIO_ENABLE

    (void)channel_id; // force use of variable

    // If we haven't returned before here, then let the keyboard level code
    // handle this, if it is overridden, otherwise by default, this will
    // return the unhandled state.
    via_custom_value_command_kb(data, length);
}

// Keyboard level code can override this, but shouldn't need to.
// Controlling custom features should be done by overriding
// via_custom_value_command_kb() instead.
__attribute__((weak)) bool via_command_kb(uint8_t *data, uint8_t length) {
    return false;
}

void raw_hid_receive(uint8_t *data, uint8_t length) {
    uint8_t *command_id   = &(data[0]);
    uint8_t *command_data = &(data[1]);

<<<<<<< HEAD
#ifdef VIAL_ENABLE
    /* When unlock is in progress, we can only react to a subset of commands */
    if (vial_unlock_in_progress) {
        if (data[0] != id_vial_prefix)
            goto skip;
        uint8_t cmd = data[1];
        if (cmd != vial_get_keyboard_id && cmd != vial_get_size && cmd != vial_get_def && cmd != vial_get_unlock_status && cmd != vial_unlock_start && cmd != vial_unlock_poll)
            goto skip;
    }
#endif
=======
    // If via_command_kb() returns true, the command was fully
    // handled, including calling raw_hid_send()
    if (via_command_kb(data, length)) {
        return;
    }
>>>>>>> master

    switch (*command_id) {
        case id_get_protocol_version: {
            command_data[0] = VIA_PROTOCOL_VERSION >> 8;
            command_data[1] = VIA_PROTOCOL_VERSION & 0xFF;
            break;
        }
        case id_get_keyboard_value: {
            switch (command_data[0]) {
                case id_uptime: {
                    uint32_t value  = timer_read32();
                    command_data[1] = (value >> 24) & 0xFF;
                    command_data[2] = (value >> 16) & 0xFF;
                    command_data[3] = (value >> 8) & 0xFF;
                    command_data[4] = value & 0xFF;
                    break;
                }
                case id_layout_options: {
                    uint32_t value  = via_get_layout_options();
                    command_data[1] = (value >> 24) & 0xFF;
                    command_data[2] = (value >> 16) & 0xFF;
                    command_data[3] = (value >> 8) & 0xFF;
                    command_data[4] = value & 0xFF;
                    break;
                }
                case id_switch_matrix_state: {
<<<<<<< HEAD
#ifdef VIAL_ENABLE
                    /* Disable wannabe keylogger unless unlocked */
                    if (!vial_unlocked)
                        goto skip;
#endif

#if ((MATRIX_COLS / 8 + 1) * MATRIX_ROWS <= 28)
                    uint8_t i = 1;
                    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
                        matrix_row_t value = matrix_get_row(row);
#    if (MATRIX_COLS > 24)
=======
                    uint8_t offset = command_data[1];
                    uint8_t rows   = 28 / ((MATRIX_COLS + 7) / 8);
                    uint8_t i      = 2;
                    for (uint8_t row = 0; row < rows && row + offset < MATRIX_ROWS; row++) {
                        matrix_row_t value = matrix_get_row(row + offset);
#if (MATRIX_COLS > 24)
>>>>>>> master
                        command_data[i++] = (value >> 24) & 0xFF;
#endif
#if (MATRIX_COLS > 16)
                        command_data[i++] = (value >> 16) & 0xFF;
#endif
#if (MATRIX_COLS > 8)
                        command_data[i++] = (value >> 8) & 0xFF;
#endif
                        command_data[i++] = value & 0xFF;
                    }
                    break;
                }
                case id_firmware_version: {
                    uint32_t value  = VIA_FIRMWARE_VERSION;
                    command_data[1] = (value >> 24) & 0xFF;
                    command_data[2] = (value >> 16) & 0xFF;
                    command_data[3] = (value >> 8) & 0xFF;
                    command_data[4] = value & 0xFF;
                    break;
                }
                default: {
                    // The value ID is not known
                    // Return the unhandled state
                    *command_id = id_unhandled;
                    break;
                }
            }
            break;
        }
        case id_set_keyboard_value: {
            switch (command_data[0]) {
                case id_layout_options: {
                    uint32_t value = ((uint32_t)command_data[1] << 24) | ((uint32_t)command_data[2] << 16) | ((uint32_t)command_data[3] << 8) | (uint32_t)command_data[4];
                    via_set_layout_options(value);
                    break;
                }
                case id_device_indication: {
                    uint8_t value = command_data[1];
                    via_set_device_indication(value);
                    break;
                }
                default: {
                    // The value ID is not known
                    // Return the unhandled state
                    *command_id = id_unhandled;
                    break;
                }
            }
            break;
        }
        case id_dynamic_keymap_get_keycode: {
            uint16_t keycode = dynamic_keymap_get_keycode(command_data[0], command_data[1], command_data[2]);
            command_data[3]  = keycode >> 8;
            command_data[4]  = keycode & 0xFF;
            break;
        }
        case id_dynamic_keymap_set_keycode: {
            dynamic_keymap_set_keycode(command_data[0], command_data[1], command_data[2], (command_data[3] << 8) | command_data[4]);
            break;
        }
        case id_dynamic_keymap_reset: {
            dynamic_keymap_reset();
            break;
        }
<<<<<<< HEAD
        case id_lighting_set_value: {
#if defined(VIA_QMK_BACKLIGHT_ENABLE)
            via_qmk_backlight_set_value(command_data);
#endif
#if defined(VIA_QMK_RGBLIGHT_ENABLE)
            via_qmk_rgblight_set_value(command_data);
#endif
#if defined(VIALRGB_ENABLE)
            vialrgb_set_value(data, length);
#endif
#if defined(VIA_QMK_RGB_MATRIX_ENABLE)
            via_qmk_rgb_matrix_set_value(command_data);
#endif
#if defined(VIA_CUSTOM_LIGHTING_ENABLE)
            raw_hid_receive_kb(data, length);
#endif
#if !defined(VIA_QMK_BACKLIGHT_ENABLE) && !defined(VIA_QMK_RGBLIGHT_ENABLE) && !defined(VIALRGB_ENABLE) && !defined(VIA_CUSTOM_LIGHTING_ENABLE) && !defined(VIA_QMK_RGB_MATRIX_ENABLE)
            // Return the unhandled state
            *command_id = id_unhandled;
#endif
            break;
        }
        case id_lighting_get_value: {
#if defined(VIA_QMK_BACKLIGHT_ENABLE)
            via_qmk_backlight_get_value(command_data);
#endif
#if defined(VIA_QMK_RGBLIGHT_ENABLE)
            via_qmk_rgblight_get_value(command_data);
#endif
#if defined(VIALRGB_ENABLE)
            vialrgb_get_value(data, length);
#endif
#if defined(VIA_QMK_RGB_MATRIX_ENABLE)
            via_qmk_rgb_matrix_get_value(command_data);
#endif
#if defined(VIA_CUSTOM_LIGHTING_ENABLE)
            raw_hid_receive_kb(data, length);
#endif
#if !defined(VIA_QMK_BACKLIGHT_ENABLE) && !defined(VIA_QMK_RGBLIGHT_ENABLE) && !defined(VIALRGB_ENABLE) && !defined(VIA_CUSTOM_LIGHTING_ENABLE) && !defined(VIA_QMK_RGB_MATRIX_ENABLE)
            // Return the unhandled state
            *command_id = id_unhandled;
#endif
            break;
        }
        case id_lighting_save: {
#if defined(VIA_QMK_BACKLIGHT_ENABLE)
            eeconfig_update_backlight_current();
#endif
#if defined(VIA_QMK_RGBLIGHT_ENABLE)
            eeconfig_update_rgblight_current();
#endif
#if defined(VIALRGB_ENABLE)
            vialrgb_save(data, length);
#endif
#if defined(VIA_QMK_RGB_MATRIX_ENABLE)
            eeconfig_update_rgb_matrix();
#endif
#if defined(VIA_CUSTOM_LIGHTING_ENABLE)
            raw_hid_receive_kb(data, length);
#endif
#if !defined(VIA_QMK_BACKLIGHT_ENABLE) && !defined(VIA_QMK_RGBLIGHT_ENABLE) && !defined(VIALRGB_ENABLE) && !defined(VIA_CUSTOM_LIGHTING_ENABLE) && !defined(VIA_QMK_RGB_MATRIX_ENABLE)
            // Return the unhandled state
            *command_id = id_unhandled;
#endif
=======
        case id_custom_set_value:
        case id_custom_get_value:
        case id_custom_save: {
            via_custom_value_command(data, length);
>>>>>>> master
            break;
        }
#ifdef VIA_EEPROM_ALLOW_RESET
        case id_eeprom_reset: {
            via_eeprom_set_valid(false);
            eeconfig_init_via();
            break;
        }
#endif
        case id_dynamic_keymap_macro_get_count: {
            command_data[0] = dynamic_keymap_macro_get_count();
            break;
        }
        case id_dynamic_keymap_macro_get_buffer_size: {
            uint16_t size   = dynamic_keymap_macro_get_buffer_size();
            command_data[0] = size >> 8;
            command_data[1] = size & 0xFF;
            break;
        }
        case id_dynamic_keymap_macro_get_buffer: {
            uint16_t offset = (command_data[0] << 8) | command_data[1];
            uint16_t size   = command_data[2]; // size <= 28
            if (size <= 28)
                dynamic_keymap_macro_get_buffer(offset, size, &command_data[3]);
            break;
        }
        case id_dynamic_keymap_macro_set_buffer: {
#ifdef VIAL_ENABLE
            /* Until keyboard is unlocked, don't allow changing macros */
            if (!vial_unlocked)
                goto skip;
#endif
            uint16_t offset = (command_data[0] << 8) | command_data[1];
            uint16_t size   = command_data[2]; // size <= 28
            if (size <= 28)
                dynamic_keymap_macro_set_buffer(offset, size, &command_data[3]);
            break;
        }
        case id_dynamic_keymap_macro_reset: {
            dynamic_keymap_macro_reset();
            break;
        }
        case id_dynamic_keymap_get_layer_count: {
            command_data[0] = dynamic_keymap_get_layer_count();
            break;
        }
        case id_dynamic_keymap_get_buffer: {
            uint16_t offset = (command_data[0] << 8) | command_data[1];
            uint16_t size   = command_data[2]; // size <= 28
            if (size <= 28)
                dynamic_keymap_get_buffer(offset, size, &command_data[3]);
            break;
        }
        case id_dynamic_keymap_set_buffer: {
            uint16_t offset = (command_data[0] << 8) | command_data[1];
            uint16_t size   = command_data[2]; // size <= 28
            if (size <= 28)
                dynamic_keymap_set_buffer(offset, size, &command_data[3]);
            break;
        }
#if defined(VIAL_ENABLE) && !defined(VIAL_INSECURE)
        /* As VIA removed bootloader jump entirely, we shall only keep it for secure builds */
        case id_bootloader_jump: {
            /* Until keyboard is unlocked, don't allow jumping to bootloader */
            if (!vial_unlocked)
                goto skip;
            // Need to send data back before the jump
            // Informs host that the command is handled
            raw_hid_send(data, length);
            // Give host time to read it
            wait_ms(100);
            bootloader_jump();
            break;
        }
#endif
#ifdef VIAL_ENABLE
        case id_vial_prefix: {
            vial_handle_cmd(data, length);
            break;
        }
#endif
        default: {
            // The command ID is not known let the keyboard implement it
            raw_hid_receive_kb(data, length);
            break;
        }
    }
#ifdef VIAL_ENABLE
skip:
#endif
    // Return the same buffer, optionally with values changed
    // (i.e. returning state to the host, or the unhandled state).
    raw_hid_send(data, length);
}

#if defined(BACKLIGHT_ENABLE)

void via_qmk_backlight_command(uint8_t *data, uint8_t length) {
    // data = [ command_id, channel_id, value_id, value_data ]
    uint8_t *command_id        = &(data[0]);
    uint8_t *value_id_and_data = &(data[2]);

    switch (*command_id) {
        case id_custom_set_value: {
            via_qmk_backlight_set_value(value_id_and_data);
            break;
        }
        case id_custom_get_value: {
            via_qmk_backlight_get_value(value_id_and_data);
            break;
        }
        case id_custom_save: {
            via_qmk_backlight_save();
            break;
        }
        default: {
            *command_id = id_unhandled;
            break;
        }
    }
}

#    if BACKLIGHT_LEVELS == 0
#        error BACKLIGHT_LEVELS == 0
#    endif

void via_qmk_backlight_get_value(uint8_t *data) {
    // data = [ value_id, value_data ]
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);
    switch (*value_id) {
        case id_qmk_backlight_brightness: {
            // level / BACKLIGHT_LEVELS * 255
            value_data[0] = ((uint16_t)get_backlight_level()) * 255 / BACKLIGHT_LEVELS;
            break;
        }
        case id_qmk_backlight_effect: {
#    ifdef BACKLIGHT_BREATHING
            value_data[0] = is_backlight_breathing() ? 1 : 0;
#    else
            value_data[0] = 0;
#    endif
            break;
        }
    }
}

void via_qmk_backlight_set_value(uint8_t *data) {
    // data = [ value_id, value_data ]
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);
    switch (*value_id) {
        case id_qmk_backlight_brightness: {
            // level / 255 * BACKLIGHT_LEVELS
            backlight_level_noeeprom(((uint16_t)value_data[0]) * BACKLIGHT_LEVELS / 255);
            break;
        }
        case id_qmk_backlight_effect: {
#    ifdef BACKLIGHT_BREATHING
            if (value_data[0] == 0) {
                backlight_disable_breathing();
            } else {
                backlight_enable_breathing();
            }
#    endif
            break;
        }
    }
}

void via_qmk_backlight_save(void) {
    eeconfig_update_backlight_current();
}

#endif // BACKLIGHT_ENABLE

<<<<<<< HEAD
#if defined(VIA_QMK_RGBLIGHT_ENABLE)
=======
#if defined(RGBLIGHT_ENABLE)
#    ifndef RGBLIGHT_LIMIT_VAL
#        define RGBLIGHT_LIMIT_VAL 255
#    endif
>>>>>>> master

void via_qmk_rgblight_command(uint8_t *data, uint8_t length) {
    // data = [ command_id, channel_id, value_id, value_data ]
    uint8_t *command_id        = &(data[0]);
    uint8_t *value_id_and_data = &(data[2]);

    switch (*command_id) {
        case id_custom_set_value: {
            via_qmk_rgblight_set_value(value_id_and_data);
            break;
        }
        case id_custom_get_value: {
            via_qmk_rgblight_get_value(value_id_and_data);
            break;
        }
        case id_custom_save: {
            via_qmk_rgblight_save();
            break;
        }
        default: {
            *command_id = id_unhandled;
            break;
        }
    }
}

void via_qmk_rgblight_get_value(uint8_t *data) {
    // data = [ value_id, value_data ]
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);
    switch (*value_id) {
        case id_qmk_rgblight_brightness: {
            value_data[0] = rgblight_get_val();
            break;
        }
        case id_qmk_rgblight_effect: {
            value_data[0] = rgblight_is_enabled() ? rgblight_get_mode() : 0;
            break;
        }
        case id_qmk_rgblight_effect_speed: {
            value_data[0] = rgblight_get_speed();
            break;
        }
        case id_qmk_rgblight_color: {
            value_data[0] = rgblight_get_hue();
            value_data[1] = rgblight_get_sat();
            break;
        }
    }
}

void via_qmk_rgblight_set_value(uint8_t *data) {
    // data = [ value_id, value_data ]
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);
    switch (*value_id) {
        case id_qmk_rgblight_brightness: {
            rgblight_sethsv_noeeprom(rgblight_get_hue(), rgblight_get_sat(), value_data[0]);
            break;
        }
        case id_qmk_rgblight_effect: {
            if (value_data[0] == 0) {
                rgblight_disable_noeeprom();
            } else {
                rgblight_enable_noeeprom();
                rgblight_mode_noeeprom(value_data[0]);
            }
            break;
        }
        case id_qmk_rgblight_effect_speed: {
            rgblight_set_speed_noeeprom(value_data[0]);
            break;
        }
        case id_qmk_rgblight_color: {
            rgblight_sethsv_noeeprom(value_data[0], value_data[1], rgblight_get_val());
            break;
        }
    }
}

void via_qmk_rgblight_save(void) {
    eeconfig_update_rgblight_current();
}

#endif // QMK_RGBLIGHT_ENABLE

#if defined(RGB_MATRIX_ENABLE)

<<<<<<< HEAD
// VIA supports only 4 discrete values for effect speed; map these to some
// useful speed values for RGB Matrix.
enum speed_values {
    RGBLIGHT_SPEED_0 = UINT8_MAX / 16, // not 0 to avoid really slow effects
    RGBLIGHT_SPEED_1 = UINT8_MAX / 4,
    RGBLIGHT_SPEED_2 = UINT8_MAX / 2,     // matches the default value
    RGBLIGHT_SPEED_3 = UINT8_MAX / 4 * 3, // UINT8_MAX is really fast
};

static uint8_t speed_from_rgblight(uint8_t rgblight_speed) {
    switch (rgblight_speed) {
        case 0:
            return RGBLIGHT_SPEED_0;
        case 1:
            return RGBLIGHT_SPEED_1;
        case 2:
        default:
            return RGBLIGHT_SPEED_2;
        case 3:
            return RGBLIGHT_SPEED_3;
    }
}
=======
#    if !defined(RGB_MATRIX_MAXIMUM_BRIGHTNESS) || RGB_MATRIX_MAXIMUM_BRIGHTNESS > UINT8_MAX
#        undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#        define RGB_MATRIX_MAXIMUM_BRIGHTNESS UINT8_MAX
#    endif

void via_qmk_rgb_matrix_command(uint8_t *data, uint8_t length) {
    // data = [ command_id, channel_id, value_id, value_data ]
    uint8_t *command_id        = &(data[0]);
    uint8_t *value_id_and_data = &(data[2]);
>>>>>>> master

    switch (*command_id) {
        case id_custom_set_value: {
            via_qmk_rgb_matrix_set_value(value_id_and_data);
            break;
        }
        case id_custom_get_value: {
            via_qmk_rgb_matrix_get_value(value_id_and_data);
            break;
        }
        case id_custom_save: {
            via_qmk_rgb_matrix_save();
            break;
        }
        default: {
            *command_id = id_unhandled;
            break;
        }
    }
}

void via_qmk_rgb_matrix_get_value(uint8_t *data) {
    // data = [ value_id, value_data ]
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);

    switch (*value_id) {
<<<<<<< HEAD
        case id_qmk_rgblight_brightness:
            value_data[0] = rgb_matrix_get_val();
=======
        case id_qmk_rgb_matrix_brightness: {
            value_data[0] = ((uint16_t)rgb_matrix_get_val() * UINT8_MAX) / RGB_MATRIX_MAXIMUM_BRIGHTNESS;
>>>>>>> master
            break;
        }
        case id_qmk_rgb_matrix_effect: {
            value_data[0] = rgb_matrix_is_enabled() ? rgb_matrix_get_mode() : 0;
            break;
        }
        case id_qmk_rgb_matrix_effect_speed: {
            value_data[0] = rgb_matrix_get_speed();
            break;
        }
        case id_qmk_rgb_matrix_color: {
            value_data[0] = rgb_matrix_get_hue();
            value_data[1] = rgb_matrix_get_sat();
            break;
        }
    }
}

void via_qmk_rgb_matrix_set_value(uint8_t *data) {
    // data = [ value_id, value_data ]
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);
    switch (*value_id) {
<<<<<<< HEAD
        case id_qmk_rgblight_brightness:
            rgb_matrix_sethsv_noeeprom(rgb_matrix_get_hue(), rgb_matrix_get_sat(), value_data[0]);
=======
        case id_qmk_rgb_matrix_brightness: {
            rgb_matrix_sethsv_noeeprom(rgb_matrix_get_hue(), rgb_matrix_get_sat(), scale8(value_data[0], RGB_MATRIX_MAXIMUM_BRIGHTNESS));
>>>>>>> master
            break;
        }
        case id_qmk_rgb_matrix_effect: {
            if (value_data[0] == 0) {
                rgb_matrix_disable_noeeprom();
            } else {
                rgb_matrix_enable_noeeprom();
                rgb_matrix_mode_noeeprom(value_data[0]);
            }
            break;
        }
        case id_qmk_rgb_matrix_effect_speed: {
            rgb_matrix_set_speed_noeeprom(value_data[0]);
            break;
        }
        case id_qmk_rgb_matrix_color: {
            rgb_matrix_sethsv_noeeprom(value_data[0], value_data[1], rgb_matrix_get_val());
            break;
        }
    }
}

void via_qmk_rgb_matrix_save(void) {
    eeconfig_update_rgb_matrix();
}

#endif // RGB_MATRIX_ENABLE

#if defined(AUDIO_ENABLE)

extern audio_config_t audio_config;

void via_qmk_audio_command(uint8_t *data, uint8_t length) {
    // data = [ command_id, channel_id, value_id, value_data ]
    uint8_t *command_id        = &(data[0]);
    uint8_t *value_id_and_data = &(data[2]);

    switch (*command_id) {
        case id_custom_set_value: {
            via_qmk_audio_set_value(value_id_and_data);
            break;
        }
        case id_custom_get_value: {
            via_qmk_audio_get_value(value_id_and_data);
            break;
        }
        case id_custom_save: {
            via_qmk_audio_save();
            break;
        }
        default: {
            *command_id = id_unhandled;
            break;
        }
    }
}

void via_qmk_audio_get_value(uint8_t *data) {
    // data = [ value_id, value_data ]
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);
    switch (*value_id) {
        case id_qmk_audio_enable: {
            value_data[0] = audio_config.enable ? 1 : 0;
            break;
        }
        case id_qmk_audio_clicky_enable: {
            value_data[0] = audio_config.clicky_enable ? 1 : 0;
            break;
        }
    }
}

void via_qmk_audio_set_value(uint8_t *data) {
    // data = [ value_id, value_data ]
    uint8_t *value_id   = &(data[0]);
    uint8_t *value_data = &(data[1]);
    switch (*value_id) {
        case id_qmk_audio_enable: {
            audio_config.enable = value_data[0] ? 1 : 0;
            break;
        }
        case id_qmk_audio_clicky_enable: {
            audio_config.clicky_enable = value_data[0] ? 1 : 0;
            break;
        }
    }
}

void via_qmk_audio_save(void) {
    eeconfig_update_audio(audio_config.raw);
}

#endif // QMK_AUDIO_ENABLE
