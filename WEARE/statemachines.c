#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "statemachines.h"
#include "buzzer.h"
#include "lcddraw.h"
#include "song_images.h"

// Draw a filled circle in COLOR_GOLD with text background
static void normalSkull(u_int color) {
    clearScreen(color);
    drawString5x7(10, 15, "ONE PIECE", COLOR_GOLD, color);
     int cx = screenWidth/2;
    int cy = screenHeight/3;
    int r  = 15;
    for (int dy = -r; dy <= r; dy++)
        for (int dx = -r; dx <= r; dx++)
            if (dx*dx + dy*dy <= r*r)
                drawPixel(cx + dx, cy + dy, COLOR_WHITE);
    for (int dx = -4; dx <= -1; dx++)
        for (int dy = -2; dy <= 2; dy++)
            drawPixel(cx + dx, cy - 3 + dy, COLOR_BLACK);
    for (int dx = 1; dx <= 4; dx++)
        for (int dy = -2; dy <= 2; dy++)
            drawPixel(cx + dx, cy - 3 + dy, COLOR_BLACK);
    for (int dx = -3; dx <= 3; dx++)
        drawPixel(cx + dx, cy + 5, COLOR_BLACK);
    for (int i = -20; i <= 20; i++) {
        drawPixel(cx - 20 + i, cy + 20 + i, COLOR_WHITE);
        drawPixel(cx + 20 - i, cy + 20 + i, COLOR_WHITE);
    }
}

static void skullLarge(u_int bg) {
    clearScreen(bg);
    int cx = screenWidth/2;
    int cy = screenHeight/3;
    int r  = 30;
    for (int dy = -r; dy <= r; dy++)
        for (int dx = -r; dx <= r; dx++)
            if (dx*dx + dy*dy <= r*r)
                drawPixel(cx + dx, cy + dy, COLOR_WHITE);
    for (int dx = -8; dx <= -2; dx++)
        for (int dy = -4; dy <= 4; dy++)
            drawPixel(cx + dx, cy - 6 + dy, COLOR_BLACK);
    for (int dx = 2; dx <= 8; dx++)
        for (int dy = -4; dy <= 4; dy++)
            drawPixel(cx + dx, cy - 6 + dy, COLOR_BLACK);
    for (int dx = -6; dx <= 6; dx++)
        drawPixel(cx + dx, cy + 10, COLOR_BLACK);
    for (int i = -40; i <= 40; i++) {
        drawPixel(cx - 40 + i, cy + 40 + i, COLOR_WHITE);
        drawPixel(cx + 40 - i, cy + 40 + i, COLOR_WHITE);
    }
}

static void drawCircle(u_int bg) {
    clearScreen(bg);
    int cx = screenWidth/2;
    int cy = screenHeight/4;
    int r = 20;
    for (int dy = -r; dy <= r; dy++)
        for (int dx = -r; dx <= r; dx++)
            if (dx*dx + dy*dy <= r*r)
                drawPixel(cx + dx, cy + dy, COLOR_WHITE);
    for (int dx = -2; dx <= 2; dx++)
        for (int dy = -2; dy <= 2; dy++) {
            drawPixel(cx - 6 + dx, cy - 6 + dy, COLOR_BLACK);
            drawPixel(cx + 6 + dx, cy - 6 + dy, COLOR_BLACK);
        }
    for (int dx = -8; dx <= 8; dx++) {
        int dy = (dx*dx)/16;
        drawPixel(cx + dx, cy + 8 + dy, COLOR_BLACK);
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
        normalSkull(COLOR_GRAY);
        oot();
        break;
    case 2:
        skullLarge(COLOR_BLUE);
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
