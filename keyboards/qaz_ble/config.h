#ifndef CONFIG_H
#define CONFIG_H

// #include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0x7431
#define PRODUCT_ID 0x0001
#define DEVICE_VER 0x0001
#define MANUFACTURER whydobearsexplod
#define PRODUCT qaz keyboard


/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 7

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* number of backlight levels */

#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 3
#endif

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/* prevent stuck modifiers */
#define PREVENT_STUCK_MODIFIERS

#define PROGMEM


#endif
