// tamagotchi.h

#ifndef tamagotchi_included
#define tamagotchi_included

enum State {
  STATE_IDLE,
  STATE_FEED,
  STATE_PLAY,
  STATE_SLEEP
};

extern volatile enum State state;
extern volatile unsigned char points;

void init_buttons();
void update_state_machine();

#endif
