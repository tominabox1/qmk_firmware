# Common feature for all keyboards
BOOTMAGIC_ENABLE = yes
EXTRAKEY_ENABLE = yes
TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes

ifeq ($(strip $(KEYBOARD)),lazydesigners/apricot)
RGB_MATRIX_ENABLE = no
DYNAMIC_MACRO_ENABLE = no
MOUSEKEY_ENABLE = no
CONSOLE_ENABLE = no
ENCODER_ENABLE = no
EXTRAKEY_ENABLE = yes
LTO_ENABLE = yes
endif

ifeq ($(strip $(KEYBOARD)), tominabox1/underscore33/rev2)
RGBLIGHT_ENABLE = no
DYNAMIC_MACRO_ENABLE = no
MOUSEKEY_ENABLE = yes
CONSOLE_ENABLE = no
LTO_ENABLE = yes
endif

SRC += tap_dancing.c
SRC += combos.c
SRC += tominabox1.c
