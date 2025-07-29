#include <msp430.h>
#include "globals.h"
#include "input.h"

#define BTN1 BIT1 // P1.1
#define BTN2 BIT2 // P1.2
#define BTN3 BIT5 // P2.5
#define BTN4 BIT7 // P1.7

void setupInputPins() {
    P1DIR &= ~(BTN1 | BTN2 | BTN4);
    P2DIR &= ~BTN3;

    P1REN |= BTN1 | BTN2 | BTN4;
    P2REN |= BTN3;

    P1OUT |= BTN1 | BTN2 | BTN4;
    P2OUT |= BTN3;
}

void pollButtons() {
    if (!(P1IN & BTN1)) {
        direction = DIR_UP;
        if (gameState == STATE_PAUSED) gameState = STATE_RUNNING;
    } else if (!(P1IN & BTN2)) {
        direction = DIR_RIGHT;
        if (gameState == STATE_PAUSED) gameState = STATE_RUNNING;
    } else if (!(P2IN & BTN3)) {
        direction = DIR_DOWN;
        if (gameState == STATE_PAUSED) gameState = STATE_RUNNING;
    } else if (!(P1IN & BTN4)) {
        direction = DIR_LEFT;
        if (gameState == STATE_PAUSED) gameState = STATE_RUNNING;
    }
}
