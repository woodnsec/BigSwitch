#include "bigswitch.h"

#define _MAIN 0
#define X_RTOG RGB_TOG
#define X_RBG_M_R RGB_M_R
#define X_RGB_M_P RGB_M_P

// How long (in ms) to wait between animation steps for the breathing mode
//const uint8_t RGBLED_BREATHING_INTERVALS[] PROGMEM = {30, 20, 10, 5};

enum custom_keycodes {
    MY_CUSTOM_MACRO = SAFE_RANGE
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
      
        switch(keycode) {
            case MY_CUSTOM_MACRO:
                SEND_STRING(SS_RCTRL("tf")); // this is our macro
                rgblight_enable();
                rgblight_setrgb(255, 0, 0);
                _delay_ms(500);
                rgblight_toggle();
                _delay_ms(500);
                rgblight_toggle();
                _delay_ms(500);
                rgblight_toggle();
                _delay_ms(500);
                rgblight_toggle();
                _delay_ms(500);
                rgblight_toggle();
                _delay_ms(500);
                rgblight_toggle();
                _delay_ms(500);
                rgblight_disable();
                return false; break;
        }
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAIN] = {
      {MY_CUSTOM_MACRO, X_RTOG, X_RBG_M_R, RGB_M_P}
    }
};
