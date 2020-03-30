#include <msp430.h>
#include "led.h"
#include "switches.h"

void led_init()
{
  // Set output to LEDs
  P1DIR |= LEDS;
  // Set state to 1 to we can update in the next method
  switch_state_changed = 1;
  // Update the LEDs
  led_update();
}

void led_update(){
  // Update LEDs if needed
  if (switch_state_changed) {
    // Default to all LEDS off
    char ledFlags = 0;
    // Set LED flags based on the button's state.
    // Recall that the state is reversed, so "down" means unpressed
    ledFlags |= switch_state_down ? LED_GREEN : LED_RED;
    // Clear bits for off LEDs
    P1OUT = 0;
    // Set bits for on LEDs
    P1OUT |= ledFlags;
  }
  // Update Complete
  switch_state_changed = 0;
}

