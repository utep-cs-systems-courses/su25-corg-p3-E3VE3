#ifndef GLOBALS_H
#define GLOBALS_H

#define DIR_UP 1
#define DIR_RIGHT 2
#define DIR_DOWN 3
#define DIR_LEFT 4

#define STATE_INIT 0
#define STATE_RUNNING 1
#define STATE_PAUSED 2
#define STATE_GAME_OVER 3

extern volatile unsigned int gameState;
extern volatile unsigned int direction;
extern volatile unsigned int snakeLength;
extern volatile unsigned int display_counter;
extern volatile unsigned int headX, headY;
extern volatile unsigned int tailX, tailY;
extern volatile unsigned int dirTail;
extern volatile unsigned int randomInt;
extern volatile unsigned int arr[8][8];
extern volatile unsigned int arrToPrint[8][8];
extern volatile unsigned int directionArr[64];

#endif
