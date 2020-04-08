#include <msp430.h>
#include "led.h"
#include "switches.h"

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
  led_update();
}

/*
Designed Output:
  0: Both Off
  1:  R
  2: G
  3: GR
*/
void led_update(){
  if (switch_state_changed) {
    static char state = 0
    if (state > 3) {
      state = 0;
    }
    char ledFlags = 0; /* by default, no LEDs on */

    switch (state) {
      case 1: ledFlags |= LED_RED; break;
      case 2: ledFlags |= LED_GREEN; break;
      case 3: ledFlags |= LEDS;
    }

    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags;         // set bits for on leds

    state += 1; // Move to next state
  }
  switch_state_changed = 0;
}

