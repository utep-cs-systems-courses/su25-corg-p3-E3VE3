#ifndef led_included
#define led_included

#include <msp430.h>

// define references to the led pins
#define LED_RED BIT0          // P1.0        
#define LED_GREEN BIT6        // P1.6    
#define LEDS (BIT0 | BIT6)

// function prototypes
void led_init();              // initializes led 
void led_update();            // updates the led status based on r_on/g_on flags
void green_led_on();          // turns on green 
void red_led_on();            // turns on red 
void leds_off();              // turns off both leds
void led_flash(int n);        // flashes the leds

// flags to check states
extern unsigned char r_led_on, g_led_on;          // indicates states of red and green leds
extern unsigned char led_changed;                 // tracks changes in led status

#endif // included
