#include <msp430.h>
#include <libTimer.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "song_images.h"
#include "statemachines.h"

int main(void) {
    configureClocks();
    lcd_init();
    switch_init();
    led_init();
    buzzer_init();

    green_led_on();
    enableWDTInterrupts();
    or_sr(0x18);    // CPU off, GIE on
}
