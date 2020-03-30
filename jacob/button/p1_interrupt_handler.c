#include <msp430.h>
#include "switches.h"

/* Switch on P1 (S2) */
void
__interrupt_vec(PORT1_VECTOR) Port_1(){
  /*
 P1IFG is the Port 1 Interrupt Flag Register and it's value is determined by the
 hardware that triggered the interrupt. Im the case of the switches, the value if P1IFG
 will be equal to the value of the switch, and can therefore be checked with &. If it is
 not a switch that caused the interrupt, the & operation will return 0 and the if
 statement will fail to execute
  */
  if (P1IFG & SWITCHES) {	      /* did a button cause this interrupt? */
    P1IFG &= ~SWITCHES;		      /* clear pending sw interrupts */
    switch_interrupt_handler();	/* single handler for all switches */
  }
}

