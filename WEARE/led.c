#include <msp430.h>
#include "led.h"
#include "switches.h"

// flags to check states
unsigned char led_altered = 0;
unsigned char r_led_on = 0, g_led_on = 0;
static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};

// states of leds
void led_init() {
  P1DIR |= LEDS;          // sets a bit in P1DIR (port 1) to 1 configuring it as an output
  led_altered = 1;        // state of leds have been altered so update char to 1
  led_update();           // call on led_update function
}

// updates the led states 
void led_update() {
  // check if the leds need to be updated (they have been altered)
  if (led_altered) {
    char ledFlags = redVal[r_led_on] | greenVal[g_led_on];     // find the desired state for the leds (0 or 1)
    // apply the ledFlags values without changing the other pins to output (leds)
    P1OUT &= (0xff^LEDS) | ledFlags;                           // 0xff^LEDS - 1111 1111 XOR 0100 0001 = 1011 1110
    P1OUT |= ledFlags;                                         // update the leds to their new state (on or off)
    led_altered = 0;                                           // reset the state
  }
}

// turns on the green led
void green_led_on() {
  P1OUT |= LED_RED;                     // set bit for the green led (turning it on)
  __delay_cycles(500000);               // delay of 500000 clock cycles
}

// turns on the red led
void red_led_on() {
  P1OUT |= LED_GREEN;                   // set bit for the red led (turning it on)
  __delay_cycles(500000);               // delay of 500000 clock cycles
}

// turns off both leds
void leds_off() {
  // turn off the green led without changing the other pins
  P1OUT &= ~LED_GREEN;                  // ~LED_GREEN inverts bits
  __delay_cycles(500000);               // delay of 500000 clock cycles
  P1OUT &= ~LED_RED;
}

// flashes the leds
void led_flash(int n) {
  // flash leds until n
  for (int i = 0; i < n; i++) {
    P1OUT |= LED_GREEN;                 // turn the gren led on
    __delay_cycles(1500000);            // delay
    P1OUT &= ~LED_RED;                  // turn off the red led
    __delay_cycles(500000);             // delay
    P1OUT &= ~LED_GREEN;                // turn off the green led
    __delay_cycles(500000);             // delay
    P1OUT |= LED_RED;                   // turn the green led on
    __delay_cycles(1500000);            // delay
  }
  leds_off();                           // turn off the leds
}