#include <msp430.h>
#include "tamagotchi.h"
#include "display.h"
#include "buzzer.h"

#define BUTTONS (BIT0 | BIT1 | BIT2) // P2.0–P2.2
#define MAX_POINTS 10

volatile enum State state = STATE_IDLE;
volatile unsigned char points = 5;
unsigned int tick_counter = 0;

void init_buttons() {
  P2REN |= BUTTONS;
  P2OUT |= BUTTONS;
  P2DIR &= ~BUTTONS;
  P2IE |= BUTTONS;
  P2IES |= BUTTONS;
  P2IFG &= ~BUTTONS;
}

void update_state_machine() {
  switch (state) {
    case STATE_FEED:
    case STATE_PLAY:
    case STATE_SLEEP:
      if (points < MAX_POINTS) points++;
      break;
    default: break;
  }
}

void __interrupt_vec(PORT2_VECTOR) Port_2() {
  if (P2IFG & BIT0) {
    state = STATE_FEED;
    update_state_machine();
  } else if (P2IFG & BIT1) {
    state = STATE_PLAY;
    update_state_machine();
  } else if (P2IFG & BIT2) {
    state = STATE_SLEEP;
    update_state_machine();
  }
  P2IFG &= ~BUTTONS;
  play_button_sound(state);
  update_display(state, points);
}

void __interrupt_vec(WDT_VECTOR) WDT() {
  if (++tick_counter >= 2500) { // 1 tick = 1/250s, 2500 ticks = 10s
    tick_counter = 0;
    if (points > 0) points--;
    update_display(state, points);
  }
}

int main() {
  WDTCTL = WDTPW | WDTHOLD;
  configureClocks();
  enableWDTInterrupts();
  lcd_init();
  init_buttons();
  buzzer_init();

  update_display(state, points);

  __bis_SR_register(GIE);
  while (1) __low_power_mode_0();
}
