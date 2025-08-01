#include "notes.h"
#include <msp430.h>
#include <libTimer.h>
#include "buzzer.h"
#include "led.h"

// Forward declaration for legacy playTone usage (if needed elsewhere)
extern void playTone(unsigned int freq, unsigned int duration_ms);

// Initialize the buzzer pin P2.6 with TimerA in up-mode
void buzzer_init(void) {
    timerAUpmode();          // drive speaker on TA0.1 / P2.6
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL  &= ~BIT7;
    P2SEL  |=  BIT6;
    P2DIR  |=  BIT6;
}

// Set PWM period (speaker frequency) for TimerA
void buzzer_set_period(short cycles) {
    CCR0 = cycles;
    CCR1 = cycles >> 1;
}

// Play a tune: sequences of notes & durations, with LED feedback
void playTune(const int *notes, const int *tempo, int count) {
    for (int i = 0; i < count; i++) {
        // alternate LEDs on/off
        if ((i & 1) == 0) red_led_on();
        else              green_led_on();

        // set buzzer frequency
        buzzer_set_period(1000000 / notes[i]);

        // duration in loop iterations
        int dur = tempo[i];
        while (dur--) __delay_cycles(10000);

        leds_off();
    }
    // ensure buzzer and LEDs are off at the end
    buzzer_set_period(0);
    leds_off();
}

// Play the One Piece “We Are!” Luffy theme using playTune()
void oot(void) {
    static const int notes[] = {
        F2,  F3,  A3,  D4,  E4,  C2,  G3,  B3,
        D4,  E4,  F2,  C3,  F3,  A3,  D4,  E4,
        C2,  G2,  E3,  B3,  D4,  E4,  D5,  D6,
        F2,  C3,  F3,  A3,  D4
    };
    static const int tempo[] = {
        1276, 300,  300,  300, 1276, 1276, 300,  300,
        300,  1276, 1276, 600,  500,  500,  500,  1276,
        600,  500,  500,  500,  400,  500,  500,  1276,
        600,  300,  300,  300,  300
    };
    const int numNotes = sizeof(notes) / sizeof(*notes);
    playTune(notes, tempo, numNotes);
}
