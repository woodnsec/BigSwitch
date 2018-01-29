#ifndef BIGSWITCH_H
#define BIGSWITCH_H

#include "quantum.h"

#define KEYMAP( \
      k01, k02, k03, k04 \
) \
{ \
    { k01, k02, k03, k04} \
}

#define KC_KEYMAP(k01, k02, k03, k04) KEYMAP(KC_##k01, KC_##k02, KC_##k03, KC_##k04)

#endif
