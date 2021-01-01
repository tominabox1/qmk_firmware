CONSOLE_ENABLE = no
BOOTMAGIC_ENABLE = lite      # Virtual DIP switch configuration
NKRO_ENABLE = yes

ifeq ($(strip $(KEYBOARD)), crkbd/rev1)
RGB_MATRIX_ENABLE = yes
EXTRAFLAGS += -flto
BOOTLOADER = qmk-dfu
OLED_DRIVER_ENABLE = yes
TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
EXTRAKEY_ENABLE = yes
NKRO_ENABLE = yes
SRC += tominabox1.c
endif

ifeq ($(strip $(KEYBOARD)), lazydesigners/dimple)
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes        # Audio control and System control
BACKLIGHT_ENABLE = yes       # Enable keyboard backlight functionality on B7 by default
RGBLIGHT_ENABLE = yes        # Enable keyboard RGB underglow
endif

ifeq ($(strip $(KEYBOARD)), thevankeyboards/roadkit)
EXTRAKEY_ENABLE = yes
TAP_DANCE_ENABLE = no
COMBO_ENABLE = yes
endif

ifeq ($(strip $(KEYBOARD)), hhkb)
TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
SRC += tominabox1.c
endif

ifeq ($(strip $(KEYBOARD)), treadstone32)
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
RGBLIGHT_ENABLE = yes
LED_ANIMATIONS = yes
ifeq ($(strip $(LED_ANIMATIONS)), yes)
    # OPT_DEFS += -DRGBLIGHT_ANIMATIONS
    OPT_DEFS += -DLED_ANIMATIONS
endif
SRC += tominabox1.c
endif

ifeq ($(strip $(KEYBOARD)), _33)
TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
NKRO_ENABLE = yes
RGBLIGHT_ENABLE = no
SRC += tominabox1.c
endif

ifeq ($(strip $(KEYBOARD)), jj40)
TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
RGBLIGHT_ENABLE = yes
NKRO_ENABLE = no
LED_ANIMATIONS = yes
SRC += tominabox1.c
endif
