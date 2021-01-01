ifeq ($(strip $(KEYBOARD)), lazydesigners/dimple)
EXTRAKEY_ENABLE = yes
RGBLIGHT_ENABLE = no
BACKLIGHT_ENABLE = no
TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
SRC += tominabox1.c
endif

ifeq ($(strip $(KEYBOARD)), thevankeyboards/minivan)
EXTRAKEY_ENABLE = yes
TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
RGBLIGHT_ENABLE = yes
SRC += tominabox1.c
endif

ifeq ($(strip $(KEYBOARD)), thevankeyboards/roadkit)
EXTRAKEY_ENABLE = yes
TAP_DANCE_ENABLE = no
COMBO_ENABLE = yes
endif

ifeq ($(strip $(KEYBOARD)), treadstone32/rev1)
RGBLIGHT_ENABLE = yes
LED_ANIMATIONS = yes
TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = yes

ifeq ($(strip $(LED_ANIMATIONS)), yes)
    # OPT_DEFS += -DRGBLIGHT_ANIMATIONS
    OPT_DEFS += -DLED_ANIMATIONS
endif

SRC += tominabox1.c
endif

ifeq ($(strip $(KEYBOARD)), handwired/postageboard/mini)
TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
NKRO_ENABLE = yes
RGBLIGHT_ENABLE = no
LED_ANIMATIONS = no
ifeq ($(strip $(LED_ANIMATIONS)), yes)
    # OPT_DEFS += -DRGBLIGHT_ANIMATIONS
    OPT_DEFS += -DLED_ANIMATIONS
endif
SRC += tominabox1.c
endif

ifeq ($(strip $(KEYBOARD)), le_chiffre)
TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
RGBLIGHT_ENABLE = no
NKRO_ENABLE = yes
LED_ANIMATIONS = no
MOUSEKEY_ENABLE = yes
OLED_DRIVER_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
SRC += tominabox1.c
endif

ifeq ($(strip $(KEYBOARD)), lazydesigners/dimple)
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes        # Audio control and System control
BACKLIGHT_ENABLE = yes       # Enable keyboard backlight functionality on B7 by default
RGBLIGHT_ENABLE = yes        # Enable keyboard RGB underglow
endif

ifeq ($(strip $(KEYBOARD)), alpha)
TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
RGBLIGHT_ENABLE = yes
NKRO_ENABLE = yes
LED_ANIMATIONS = yes
MOUSEKEY_ENABLE = yes
BOOTLOADER = atmel-dfu
SRC += tominabox1.c
endif

ifeq ($(strip $(KEYBOARD)), qaz)
TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
RGBLIGHT_ENABLE = no
NKRO_ENABLE = yes
LED_ANIMATIONS = no
MOUSEKEY_ENABLE = yes
BOOTLOADER = atmel-dfu
DYNAMIC_MACRO_ENABLE = yes
SRC += tominabox1.c
endif

ifeq ($(strip $(KEYBOARD)), underscore33/rev2)
TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
RGBLIGHT_ENABLE = no
DYNAMIC_MACRO_ENABLE = yes
MOUSEKEY_ENABLE = yes
CONSOLE_ENABLE = no
LTO_ENABLE = yes
SRC += tominabox1.c
endif

ifeq ($(strip $(KEYBOARD)), alps.project.2)
TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
RGBLIGHT_ENABLE = no
DYNAMIC_MACRO_ENABLE = yes
MOUSEKEY_ENABLE = no
CONSOLE_ENABLE = no
SRC += tominabox1.c
endif

ifeq ($(strip $(KEYBOARD)), alps.project.1)
TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
RGBLIGHT_ENABLE = no
DYNAMIC_MACRO_ENABLE = yes
MOUSEKEY_ENABLE = no
CONSOLE_ENABLE = no
SRC += tominabox1.c
endif

ifeq ($(strip $(KEYBOARD)), leftover30_arm)
TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
#RGBLIGHT_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
MOUSEKEY_ENABLE = yes
CONSOLE_ENABLE = no
ENCODER_ENABLE = yes
EXTRAKEY_ENABLE = yes
LTO_ENABLE = yes
EXTRAFLAGS += -flto
SRC += tominabox1.c
endif
