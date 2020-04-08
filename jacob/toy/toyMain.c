
#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"

int main(void) {
	/*
    setup master oscillator, CPU & peripheral clocks 
    Source: libTimer.h
  */
  configureClocks();
  // Initialize Switches. Source: switches.h
  switch_init();
   // Inititialize LEDs. Source: led.h
  led_init();
	/*
    enable periodic interrupt
    Source: libTimer.h
  */
  enableWDTInterrupts();
	/*
    CPU off, GIE on
    0x18 = 0000 0000 0001 1000
    Source: libTimer.h / sr.h
  */
  or_sr(0x18);
}
