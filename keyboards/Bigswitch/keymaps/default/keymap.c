#include "bigswitch.h"

#define _MAIN 0

enum custom_keycodes {
    MY_CUSTOM_MACRO = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case MY_CUSTOM_MACRO:
                SEND_STRING("QMK is the best thing ever!"); // this is our macro!
                return false; break;
        }
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = {
      {MY_CUSTOM_MACRO}
    }
};