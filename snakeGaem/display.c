#include <msp430.h>
#include "display.h"

#define DATA   BIT0
#define CLOCK  BIT4
#define LATCH  BIT5
#define ENABLE BIT6

void setupDisplayPins(void) {
    P1DIR |= DATA | CLOCK | LATCH | ENABLE;
}

void enableDisplay(void) {
    P1OUT &= ~ENABLE;
}

void disableDisplay(void) {
    P1OUT |= ENABLE;
}

static void pulseClock(void) {
    P1OUT |= CLOCK;
    P1OUT &= ~CLOCK;
}

static void latchOff(void) {
    P1OUT &= ~LATCH;
}

static void latchOn(void) {
    P1OUT |= LATCH;
    P1OUT &= ~LATCH;
}

static void pinWrite(unsigned int bit, unsigned char val) {
    if (val) P1OUT |= bit;
    else     P1OUT &= ~bit;
}

static void shiftOut(unsigned char val) {
    for (int i = 0; i < 8; i++) {
        pinWrite(DATA, (val >> i) & 0x01);
        pulseClock();
    }
}

void updateDisplay(void) {
    latchOff();
    for (int row = 7; row >= 0; row--) {
        // Call your fast assembly routine here:
        shiftOut( fast_concatenate(arrToPrint[row]) );
    }
    latchOn();
}
