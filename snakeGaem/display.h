#ifndef DISPLAY_H
#define DISPLAY_H

#include "globals.h"

// Set up and drive the shift‑register display
void setupDisplayPins(void);
void enableDisplay(void);
void disableDisplay(void);
void updateDisplay(void);

// Assembly‑optimized row packer
extern unsigned char fast_concatenate(unsigned int *row);

#endif // DISPLAY_H
