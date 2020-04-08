#include <msp430.h>
#include "led.h"
#include "switches.h"

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
  led_update();
}

char state = 1; // Setting this to 1 makes the first state GREEN
void led_update(){
  if (switch_state_changed) {
    state ^= 1; // Using a bitwise OR to change between the two states
    char ledFlags = 0; /* by default, no LEDs on */

    ledFlags |= state ? LED_GREEN : 0; // Manual Control for GREEN led
    ledFlags |= state ? 0 : LED_RED;// Maual Control for RED led

    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags;         // set bits for on leds
  }
  switch_state_changed = 0;
}

