#include "globals.h"
#include "game_logic.h"
#include "display.h"
#include "utils.h"

volatile unsigned int gameState = STATE_INIT;
volatile unsigned int direction = DIR_RIGHT;
volatile unsigned int snakeLength = 1;
volatile unsigned int headX = 3, headY = 3;
volatile unsigned int tailX = 3, tailY = 3;
volatile unsigned int dirTail = DIR_RIGHT;
volatile unsigned int display_counter = 10;
volatile unsigned int randomInt = 0;
volatile unsigned int directionArr[64] = {0};
volatile unsigned int arr[8][8] = {0};
volatile unsigned int arrToPrint[8][8] = {0};

void generateInitial() {
    headX = 3;
    headY = 3;
    tailX = headX;
    tailY = headY;
    if (arr[headX][headY] == 0) {
        arr[headX][headY] = 2;
    }
}

void takeTurn() {
    updateDir();

    switch (direction) {
        case DIR_UP:
            if (headY == 0) gameState = STATE_GAME_OVER;
            else headY--;
            break;
        case DIR_RIGHT:
            if (headX == 7) gameState = STATE_GAME_OVER;
            else headX++;
            break;
        case DIR_DOWN:
            if (headY == 7) gameState = STATE_GAME_OVER;
            else headY++;
            break;
        case DIR_LEFT:
            if (headX == 0) gameState = STATE_GAME_OVER;
            else headX--;
            break;
    }

    if (gameState == STATE_RUNNING) {
        arr[headX][headY] = 2;
    }
}

void updateDir() {
    if (snakeLength > 1) {
        for (int i = snakeLength - 2; i >= 0; i--) {
            directionArr[i + 1] = directionArr[i];
        }
    }
    directionArr[0] = direction;
}
