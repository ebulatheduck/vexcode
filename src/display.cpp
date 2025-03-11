#include "vex.h"
#include "main.h"
#include "display.h"
using namespace vex;

int autonomousSelection = -1;

// Button array definitions for each software button. The purpose of each button
// data structure is defined above. The array size can be extended, so you can
// have as many buttons as you wish as long as it fits.
button buttons[] = {
  {30, 30, 60, 60, false, 0x64846A, 0x00E000, ""},
  {150, 30, 60, 60, false, 0x64846A, 0x00E000, ""},
  {270, 30, 60, 60, false, 0x64846A, 0x00E000, ""},
  {390, 30, 60, 60, false, 0x64846A, 0x00E000, ""},
  {30, 150, 60, 60, false, 0xE00000, 0x00E000, "RedLeft"},
  {150, 150, 60, 60, false, 0xE00000, 0x00E000, "RedRight"},
  {270, 150, 60, 60, false, 0x0000E0, 0x00E000, "BlueLeft"},
  {390, 150, 60, 60, false, 0x0000E0, 0x00E000, "BlueRight"}
};

// Draw all buttons
void displayButtonControls(int index, bool pressed) {
  color c;
  Brain.Screen.setPenColor(color(0xe0e0e0));

  for (int i = 0; i < sizeof(buttons) / sizeof(button); i++) {
    if (buttons[i].state) c = buttons[i].onColor;
    else c = buttons[i].offColor;

    Brain.Screen.setFillColor(c);

    // button fill
    if (i == index && pressed == true) Brain.Screen.drawRectangle(
      buttons[i].xpos, buttons[i].ypos,
      buttons[i].width, buttons[i].height, c
    );
    else Brain.Screen.drawRectangle(
      buttons[i].xpos, buttons[i].ypos,
      buttons[i].width, buttons[i].height
    );

    // outline
    Brain.Screen.drawRectangle(
      buttons[i].xpos, buttons[i].ypos,
      buttons[i].width, buttons[i].height,
      color::transparent
    );

    // draw label
    if (buttons[i].label != NULL) Brain.Screen.printAt(
      buttons[i].xpos + 8,
      buttons[i].ypos + buttons[i].height - 8,
      buttons[i].label
    );
  }
}

// Init button states
void initButtons() {
  int nButtons = sizeof(buttons) / sizeof(button);

  for (int index = 0; index < nButtons; index++) {
    buttons[index].state = false;
  }
}

// Check if touch is inside button
int findButton(int16_t xpos, int16_t ypos) {
  int nButtons = sizeof(buttons) / sizeof(button);

  for (int index = 0; index < nButtons; index++) {
    button *pButton = &buttons[index];

    if (
      xpos < pButton -> xpos ||
      xpos > (pButton -> xpos + pButton -> width)
    ) continue;

    //  if (xpos < pButton->xpos || xpos > (pButton->xpos + pButton->height))
    // continue;

    if (ypos < pButton->ypos || ypos > (pButton->ypos + pButton->height))
      continue;
    return index;
  }

  return -1;
}

// Screen has been touched
void userTouchCallbackPressed() {
  int index;
  int xpos = Brain.Screen.xPosition();
  int ypos = Brain.Screen.yPosition();

  if ((index = findButton(xpos, ypos)) >= 0) {
    displayButtonControls(index, true);
  }
}

// Screen has been released
void userTouchCallbackReleased() {
  int index;
  int xpos = Brain.Screen.xPosition();
  int ypos = Brain.Screen.yPosition();

  if ((index = findButton(xpos, ypos)) >= 0) {
    // clear all buttons to false, ie. unselected
    //      initButtons();

    // now set this one as true
    if (buttons[index].state == true) buttons[index].state = false;
    else buttons[index].state = true;

    // save as auton selection
    autonomousSelection = index;

    displayButtonControls(index, false);
  }
}
