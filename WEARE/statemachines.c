#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "statemachines.h"
#include "buzzer.h"
#include "lcddraw.h"
#include "song_images.h"

// Draw a filled circle in COLOR_GOLD with text background
static void drawCircle(u_int color) {
    clearScreen(color);
    drawString5x7(10, 15, "ONE PIECE", COLOR_GOLD, color);

    const int radius = 20;
    const int cx = screenWidth  / 2;
    const int cy = screenHeight / 4;

    for (int dy = -radius; dy <= radius; dy++) {
        for (int dx = -radius; dx <= radius; dx++) {
            if (dx*dx + dy*dy <= radius*radius) {
                drawPixel(cx + dx, cy + dy, COLOR_GOLD);
            }
        }
    }
}

void next_state(int s) {
    leds_off();
    white_led_off();

    // flash then draw + play
    led_flash(3);
    red_led_on();

    switch (s) {
    case 1:
        drawCircle(COLOR_GRAY);
        oot();
        break;
    case 2:
        drawCircle(COLOR_BLUE);
        oot();
        break;
    case 3:
        drawCircle(COLOR_RED);
        oot();
        break;
    case 4:
        drawCircle(COLOR_GREEN);
        oot();
        break;
    default:
        green_led_on();
        return;
    }

    leds_off();
    green_led_on();
    drawCircle(COLOR_WHITE);
}