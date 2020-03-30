#include <msp430.h>
#include "led.h"

unsigned char red_on = 0, green_on = 0;
unsigned char led_changed = 0;

static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};
static char counter = 0;

void led_init()
{
  // Bits attached to LEDs are outputs
  P1DIR |= LEDS;
  // We need to set this to 1 so that update executes
  led_changed = 1;
  // Update the LEDs
  led_update();
}

void led_update()
{
  if (led_changed) {
      // We want to count from 0 to 3, so we set up a counter for it
    counter += 1;
    if (counter > 3) {
      counter = 0;
    }
      // Use the counter to calculate the flags
    char ledFlags = ((counter & 2) << 5) | (counter&1);
      // Clear bit for off LEDs
    P1OUT = 0;
      // Set the bit for on LEDs
    P1OUT |= ledFlags;
      // Mark that we have updated
    led_changed = 0;
  }
}

