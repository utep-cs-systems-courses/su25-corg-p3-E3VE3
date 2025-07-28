#include "lcdutils.h"
#include "lcddraw.h"
#include "tamagotchi.h"
#include "display.h"
#include <stdio.h>

void update_display(enum State state, unsigned char points) {
  clearScreen(COLOR_WHITE);

  // Speech bubble
  drawString5x7(20, 20, "  ______", COLOR_BLACK, COLOR_WHITE);
  drawString5x7(20, 30, " /      \\", COLOR_BLACK, COLOR_WHITE);
  drawString5x7(20, 40, "|        |", COLOR_BLACK, COLOR_WHITE);

  switch (state) {
    case STATE_IDLE:
      drawString5x7(22, 50, "|   :)   |", COLOR_BLACK, COLOR_WHITE);
      break;
    case STATE_FEED:
      drawString5x7(22, 50, "|   :P   |", COLOR_BLACK, COLOR_WHITE);
      break;
    case STATE_PLAY:
      drawString5x7(22, 50, "|  ^_^   |", COLOR_BLACK, COLOR_WHITE);
      break;
    case STATE_SLEEP:
      drawString5x7(22, 50, "|  -_-z  |", COLOR_BLACK, COLOR_WHITE);
      break;
  }

  drawString5x7(20, 60, " \\______//", COLOR_BLACK, COLOR_WHITE);

  // Cow
  drawString5x7(30, 70,  "   \\   ^__^", COLOR_BLACK, COLOR_WHITE);
  drawString5x7(30, 80,  "    \\  (oo)\\_______", COLOR_BLACK, COLOR_WHITE);
  drawString5x7(30, 90,  "       (__)\\       )\\/\\", COLOR_BLACK, COLOR_WHITE);
  drawString5x7(30, 100, "           ||----w |", COLOR_BLACK, COLOR_WHITE);
  drawString5x7(30, 110, "           ||     ||", COLOR_BLACK, COLOR_WHITE);

  char buffer[20];
  sprintf(buffer, "Points: %d", points);
  drawString5x7(10, 130, buffer, COLOR_RED, COLOR_WHITE);
}