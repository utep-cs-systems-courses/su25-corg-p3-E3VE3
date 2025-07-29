#include <msp430.h>
#include "sound.h"

// Assuming SMCLK = 1 MHz
#define SMCLK_HZ       1000000UL
#define CYCLES_PER_MS  (SMCLK_HZ / 1000)

static void delay_ms(unsigned int ms) {
    while (ms--) {
        __delay_cycles(CYCLES_PER_MS);
    }
}

void sound_init(void) {
    P2DIR |= BIT5;     // Set P2.5 as output
    P2SEL |= BIT5;     // Select TA1.2 option (Timer1_A3 channel 2)
}

void play_tone(unsigned int freq, unsigned int duration_ms) {
    unsigned int period = SMCLK_HZ / freq;

    TA1CCR0  = period - 1;        // PWM period
    TA1CCTL2 = OUTMOD_7;          // Reset/set mode
    TA1CCR2  = period / 2;        // 50% duty cycle
    TA1CTL   = TASSEL_2 | MC_1;   // SMCLK, up mode

    delay_ms(duration_ms);        // Variable delay in ms

    TA1CCTL2 = 0;                 // Stop PWM
    P2OUT   &= ~BIT5;             // Ensure buzzer is low
}

void play_gameover_sound(void) {
    play_tone(400, 300);
    delay_ms(100);
    play_tone(300, 300);
    delay_ms(100);
    play_tone(200, 500);
}

void play_apple_sound(void) {
    play_tone(880, 100);
    delay_ms(10);
    play_tone(660, 100);
}
