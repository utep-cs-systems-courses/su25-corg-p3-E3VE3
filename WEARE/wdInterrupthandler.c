#include <msp430.h>
#include "statemachines.h"


void __interrupt_vec(WDT_VECTOR) WDT() { // WatchDog Timer
  // many times interrupts have been triggered
  static char blink_count = 0;
  if (++blink_count == 125) {
    blink_count = 0;
    }
}
