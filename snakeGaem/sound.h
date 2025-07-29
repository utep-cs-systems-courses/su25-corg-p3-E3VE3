#ifndef SOUND_H
#define SOUND_H

void sound_init();
void play_tone(unsigned int freq, unsigned int duration_ms);
void play_gameover_sound();
void play_apple_sound();

#endif
