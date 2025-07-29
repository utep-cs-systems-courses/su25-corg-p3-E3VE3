#include <msp430.h>
#include "globals.h"
#include "game_logic.h"
#include "display.h"
#include "input.h"
#include "sound.h"

void setup() {
    WDTCTL = WDTPW | WDTTMSEL | WDTCNTCL | WDTSSEL_0 | WDTIS0;
    IE1 |= WDTIE;

    CCTL0 = CCIE;
    TACTL = TASSEL_2 + MC_2;

    setupDisplayPins();
    setupInputPins();
    enableDisplay();
    sound_init();

    gameState = STATE_PAUSED;
    snakeLength = 1;
    generateInitial();
    createNewApple();
    direction = DIR_RIGHT;
    display_counter = 10;
}

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;
    setup();
    __enable_interrupt();

    while (1) {
        __bis_SR_register(LPM0_bits + GIE);
    }
}
