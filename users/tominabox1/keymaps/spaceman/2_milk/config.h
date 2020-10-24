#undef DIRECT_PINS
#define DIRECT_PINS { \
    {B3}, \
    {B7}  \
}

#ifdef RGBLIGHT_ENABLE
#undef RGB_DI_PIN
#define RGB_DI_PIN C7
#undef RGBLED_NUM
#define RGBLED_NUM 3
#define RGBLIGHT_ANIMATIONS
#endif