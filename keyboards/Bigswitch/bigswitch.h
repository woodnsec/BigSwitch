#ifndef BIGSWITCH_H
#define BIGSWITCH_H

#include "quantum.h"

#define KEYMAP( \
      k01 \
) \
{ \
    { k01 } \
}

#define KC_KEYMAP(k01) KEYMAP(KC_##k01)

#endif
