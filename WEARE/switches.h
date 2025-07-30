#ifndef switches_included
#define switches_included

// define references to switches
#define SW1 BIT0 //  P2.0 BIT0
#define SW2 BIT1 //  P2.1 BIT1
#define SW3 BIT2 //  P2.2 BIT2
#define SW4 BIT3 //  P2.3 BIT3

#define SWITCHES (SW1 | SW2 | SW3 | SW4) 

// function prototypes
void switch_init();                       // initializes the switches
void switch_interrupt_handler();          // handles interruptions
char switch_update_interrupt_sense();     // updates the interruptions sense

// flag to check switch states
extern char switch_state_down;            // 0 if up, 1 if down

#endif
