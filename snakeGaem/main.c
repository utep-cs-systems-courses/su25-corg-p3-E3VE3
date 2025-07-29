#include <msp430.h>
#include "globals.h"
#include "game_logic.h"
#include "display.h"
#include "input.h"
#include "sound.h"
#include "utils.h"        // <-- for createNewApple()

void setup(void) {
    // Configure WDT as interval timer: SMCLK/8K, interval ~7.4ms
    WDTCTL = WDTPW    |  // (bits 15-8) password
             WDTTMSEL |  // (bit 4) select timer mode
             WDTCNTCL |  // (bit 3) clear counter
             WDTIS0;     // (bits 1–0 = 01) divide by 8K

    IE1 |= WDTIE;      // enable WDT interrupt

    CCTL0 = CCIE;      
    TACTL = TASSEL_2 | MC_2;  // Timer_A: SMCLK, continuous mode

    setupDisplayPins();
    setupInputPins();
    enableDisplay();
    sound_init();

    gameState       = STATE_PAUSED;
    snakeLength     = 1;
    generateInitial();
    createNewApple();       // now properly declared
    direction       = DIR_RIGHT;
    display_counter = 10;
}

int main(void) {
    WDTCTL = WDTPW | WDTHOLD; // stop WDT for setup
    setup();
    __enable_interrupt();
    for (;;) {
        __bis_SR_register(LPM0_bits | GIE);
    }
}
