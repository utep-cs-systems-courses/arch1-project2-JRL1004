#include "led_s.h"

char asm_switch(state, ledFlags)
{
  switch (state) {
    case 1: ledFlags |= LED_RED; break;
    case 2: ledFlags |= LED_GREEN; break;
    case 3: ledFlags |= LEDS;
  }
  return ledFlags;
}

