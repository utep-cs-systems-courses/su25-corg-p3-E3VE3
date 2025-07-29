#include <msp430.h>
#include "globals.h"
#include "display.h"

#define DATA BIT0
#define CLOCK BIT4
#define LATCH BIT5
#define ENABLE BIT6

void setupDisplayPins() {
    P1DIR |= DATA | CLOCK | LATCH | ENABLE;
}

void enableDisplay() {
    P1OUT &= ~ENABLE;
}

void disableDisplay() {
    P1OUT |= ENABLE;
}

void pulseClock() {
    P1OUT |= CLOCK;
    P1OUT &= ~CLOCK;
}

void latchOn() {
    P1OUT |= LATCH;
    P1OUT &= ~LATCH;
}

void latchOff() {
    P1OUT &= ~LATCH;
}

void pinWrite(unsigned int bit, unsigned char val) {
    if (val) P1OUT |= bit;
    else P1OUT &= ~bit;
}

void shiftOut(unsigned char val) {
    for (int i = 0; i < 8; i++) {
        pinWrite(DATA, (val >> i) & 0x01);
        pulseClock();
    }
}

void updateDisplay() {
    latchOff();
    for (int i = 7; i >= 0; i--) {
        shiftOut(concatenateRow(arrToPrint[i]));
    }
    latchOn();
}

int concatenateRow(unsigned int *row) {
    int result = 0;
    for (int i = 0; i < 8; i++) {
        result = (result << 1) | (row[i] ? 1 : 0);
    }
    return result;
}
