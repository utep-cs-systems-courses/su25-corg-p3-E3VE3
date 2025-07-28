// buzzer.c

#include <msp430.h>
#include "buzzer.h"
#include "tamagotchi.h"

void buzzer_init() {
  P2DIR |= BIT6;
  P2SEL |= BIT6;
  P2SEL2 &= ~BIT6;

  TACTL = TASSEL_2 + MC_1;
  CCR0 = 1000;
  CCTL1 = OUTMOD_7;
  CCR1 = 500;
}

void play_button_sound(int state) {
  switch (state) {
    case STATE_FEED:
      CCR0 = 1000;
      CCR1 = 500;
      break;
    case STATE_PLAY:
      CCR0 = 2000;
      CCR1 = 1000;
      break;
    case STATE_SLEEP:
      CCR0 = 1500;
      CCR1 = 750;
      break;
    default:
      CCR0 = 0;
      CCR1 = 0;
      break;
  }
}
