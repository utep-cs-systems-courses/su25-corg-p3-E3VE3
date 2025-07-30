#include "lcdutils.h"
#include "lcddraw.h"

void drawDefault() {
  // background + title
  clearScreen(COLOR_BROWN);
  drawString5x7(10, 15, "ONE PIECE", COLOR_YELLOW, COLOR_BLUE);

  // center point for skull & bones
  u_char width = screenWidth, height = screenHeight;
  int centerCol = width  / 2;
  int centerRow = height / 2 + 10;

  // skull & bones sizing
  int radius     = 20;
  int boneLength = radius * 2;
  int boneWidth  = 3;

  // --- draw crossed bones behind the skull ---
  for (int i = -boneLength; i <= boneLength; i++) {
    for (int w = -boneWidth; w <= boneWidth; w++) {
      // '\' bone
      drawPixel(centerCol + i, centerRow + i + w, COLOR_WHITE);
      // '/' bone
      drawPixel(centerCol + i, centerRow - i + w, COLOR_WHITE);
    }
  }

  // --- draw skull (filled circle) ---
  for (int dy = -radius; dy <= radius; dy++) {
    for (int dx = -radius; dx <= radius; dx++) {
      if (dx*dx + dy*dy <= radius*radius) {
        drawPixel(centerCol + dx, centerRow + dy, COLOR_WHITE);
      }
    }
  }

  // --- draw eye sockets ---
  int eyeRad     = 4;
  int eyeOffsetX = 8;
  int eyeOffsetY = -6;
  for (int y = -eyeRad; y <= eyeRad; y++) {
    for (int x = -eyeRad; x <= eyeRad; x++) {
      if (x*x + y*y <= eyeRad*eyeRad) {
        drawPixel(centerCol - eyeOffsetX + x, centerRow + eyeOffsetY + y, COLOR_BLACK);
        drawPixel(centerCol + eyeOffsetX + x, centerRow + eyeOffsetY + y, COLOR_BLACK);
      }
    }
  }

  // --- draw a few teeth ---
  int toothY = centerRow + radius/2;
  for (int x = -6; x <= 6; x += 4) {
    drawPixel(centerCol + x, toothY, COLOR_BLACK);
  }
}
}
