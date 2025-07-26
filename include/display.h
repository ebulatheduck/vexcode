#ifndef DISPLAY_H
#define DISPLAY_H

#include "vex.h"
using namespace vex;

typedef struct _button {
  int xpos;
  int ypos;
  int width;
  int height;
  bool state;
  color offColor;
  color onColor;
  const char* label;
} button;

void displayButtonControls(int index, bool pressed);
void initButtons(void);
int findButton(int16_t xpos, int16_t ypos);
void userTouchCallbackPressed(void);
void userTouchCallbackReleased(void);

#endif
