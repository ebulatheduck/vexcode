#pragma once

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

extern button buttons[];

void displayButtons(int index, bool pressed);
void initButtons(void);
int findButton(int16_t xpos, int16_t ypos);
void userTouchCallbackPressed(void);
void userTouchCallbackReleased(void);
