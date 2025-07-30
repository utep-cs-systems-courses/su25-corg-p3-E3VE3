#include <msp430.h>
#include "switches.h"

void __interrupt_vec(PORT2_VECTOR) Port2() {
  if(P2IFG & SWITCHES){            // check if an interrupt has been triggered by a switch
    P2IFG &= ~SWITCHES;            // reset the bits in SWITCHES
    switch_interrupt_handler();
  }
}