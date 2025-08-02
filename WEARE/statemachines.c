This would be better, no? // smiley_bounce_main.c
#include <msp430.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

// Global state
int smileyX = 64, smileyY = 80;
int dx = 2, dy = 2;
char redrawSmiley = 0;
char state = 0;
u_int bgColor = COLOR_BLACK;

extern void updateSmiley(); // from assembly

// Draw the smiley face at (cx, cy)
void drawSmiley(int cx, int cy) {
  const int r = 10;
  for (int dy = -r; dy <= r; dy++)
    for (int dx = -r; dx <= r; dx++)
      if (dx*dx + dy*dy <= r*r)
        drawPixel(cx + dx, cy + dy, COLOR_YELLOW);

  for (int dx = -4; dx <= -1; dx++)
    for (int dy = -3; dy <= -1; dy++)
      drawPixel(cx + dx, cy + dy, COLOR_BLACK);

  for (int dx = 1; dx <= 4; dx++)
    for (int dy = -3; dy <= -1; dy++)
      drawPixel(cx + dx, cy + dy, COLOR_BLACK);

  for (int dx = -4; dx <= 4; dx++) {
    int dy = (dx*dx)/6;
    drawPixel(cx + dx, cy + 4 + dy, COLOR_BLACK);
  }
}

// WDT interrupt: trigger redraw every 100ms
void wdt_c_handler() {
  static int count = 0;
  if (++count == 10) {
    if (state == 3) {
      updateSmiley();
      redrawSmiley = 1;
    }
    count = 0;
  }
}

// next_state selects animation or image
void next_state(int s) {
  leds_off();
  led_flash(3);
  red_led_on();
  state = s;

  switch (s) {
      case 1:
      clearScreen(COLOR_GRAY);
      normalSkull(COLOR_GRAY);
      oot();
      break;
    case 2:
      clearScreen(COLOR_BLUE);
      skullLarge(COLOR_BLUE);
      oot();
      break;
    case 3:
      smileyX = screenWidth / 2;
      smileyY = screenHeight / 2;
      dx = 2;
      dy = 2;
      bgColor = COLOR_RED;
      redrawSmiley = 1;
      break;
        case 4:
      clearScreen(COLOR_GREEN);
      drawCircle(COLOR_GREEN);
      oot();
      break;
    default:
      drawString5x7(10, 10, "Other state", COLOR_WHITE, COLOR_BLACK);
  }
}

void main() {
  configureClocks();
  lcd_init();
  switch_init();
  led_init();
  buzzer_init();
  enableWDTInterrupts();
  or_sr(0x8); // GIE

  clearScreen(COLOR_BLACK);
  next_state(3);

  while (1) {
    if (redrawSmiley && state == 3) {
      redrawSmiley = 0;
      clearScreen(bgColor);
      drawSmiley(smileyX, smileyY);
    }
  }
}

