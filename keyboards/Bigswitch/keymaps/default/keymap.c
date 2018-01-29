#include "bigswitch.h"

#define _MAIN 0
#define X_RTOG RGB_TOG
#define X_RBG_M_R RGB_M_R
#define X_RGB_M_P RGB_M_P
#define LONGPRESS_DELAY 150

// How long (in ms) to wait between animation steps for the breathing mode
//const uint8_t RGBLED_BREATHING_INTERVALS[] PROGMEM = {30, 20, 10, 5};

enum custom_keycodes {
  MY_CUSTOM_MACRO = SAFE_RANGE
};

enum mitosis_macros
{
  VOLU,
  VOLD,
  ESCM
};

//Tap Dance Declarations
enum {
  TD_ESC_CAPS = 0
};

//Tap Dance Definitions
const qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS)
  // Other declarations would go here, separated by commas, if you have them
};

static uint16_t key_timer;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch(keycode) {

    case MY_CUSTOM_MACRO:
    if (record->event.pressed) {
      key_timer = timer_read(); // if the key is being pressed, we start the timer.
    } else { // this means the key was just released, so we can figure out how long it was pressed for (tap or "held down").
    if (timer_elapsed(key_timer) > LONGPRESS_DELAY) { // LONGPRESS_DELAY being 150ms, the threshhold we pick for counting something as a tap.

      SEND_STRING("Testing the long press");
      return false; break;

    } else {
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
}
return true;
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {

    //switch multiplexing for media, short tap for volume up, long press for play/pause
    case VOLU:
    if (record->event.pressed) {
      key_timer = timer_read(); // if the key is being pressed, we start the timer.
    } else { // this means the key was just released, so we can figure out how long it was pressed for (tap or "held down").
    if (timer_elapsed(key_timer) > LONGPRESS_DELAY) { // LONGPRESS_DELAY being 150ms, the threshhold we pick for counting something as a tap.
      return MACRO(T(MPLY), END);
    } else {
      return MACRO(T(VOLU), END);
    }
  }
  break;

  //switch multiplexing for media, short tap for volume down, long press for next track
  case VOLD:
  if (record->event.pressed) {
    key_timer = timer_read();
  } else {
    if (timer_elapsed(key_timer) > LONGPRESS_DELAY) {
      return MACRO(T(MNXT), END);
    } else {
      return MACRO(T(VOLD), END);
    }
  }
  break;

  //switch multiplexing for escape, short tap for escape, long press for context menu
  case ESCM:
  if (record->event.pressed) {
    key_timer = timer_read();
  } else {
    if (timer_elapsed(key_timer) > LONGPRESS_DELAY) {
      return MACRO(T(APP), END);
    } else {
      return MACRO(T(ESC), END);
    }
  }
  break;

  break;
}
return MACRO_NONE;
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MAIN] = {
    {M(MY_CUSTOM_MACRO), TD(TD_ESC_CAPS), X_RBG_M_R, RGB_M_P}
  }
};
