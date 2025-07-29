#include <msp430.h>
#include "sound.h"

void sound_init() {
    P2DIR |= BIT5;     // Set P2.5 as output
    P2SEL |= BIT5;     // Select TA1.2 option
}

void play_tone(unsigned int freq, unsigned int duration_ms) {
    unsigned int period = 1000000 / freq;

    TA1CCR0 = period - 1;             // PWM Period
    TA1CCTL2 = OUTMOD_7;              // Reset/set
    TA1CCR2 = period / 2;             // 50% duty cycle
    TA1CTL = TASSEL_2 + MC_1;         // SMCLK, up mode

    __delay_cycles(1000 * duration_ms);

    TA1CCTL2 = 0;                     // Stop PWM
    P2OUT &= ~BIT5;                   // Ensure buzzer is low
}

void play_gameover_sound() {
    play_tone(400, 300);
    __delay_cycles(100000);
    play_tone(300, 300);
    __delay_cycles(100000);
    play_tone(200, 500);
}

void play_apple_sound() {
    play_tone(880, 100);
    __delay_cycles(10000);
    play_tone(660, 100);
}
