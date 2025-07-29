#include "globals.h"
#include "utils.h"
#include "sound.h"

void createNewApple() {
    unsigned int i, j;
    unsigned int available = 0;

    // Count available spaces
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (arr[i][j] == 0) available++;
        }
    }

    if (available == 0) return;

    unsigned int target = randomInt % available;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (arr[i][j] == 0 && target-- == 0) {
                arr[i][j] = 4;      // place apple
                play_apple_sound(); // ← Valid function call
                return;
            }
        }
    }
}
