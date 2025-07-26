#include "main.h"
using namespace vex;

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

int nButtons = sizeof(buttons) / sizeof(button);

// Draw all buttons
void displayButtonControls(int index, bool pressed) {
  color c;
  Brain.Screen.setPenColor(color(0xe0e0e0));

  for (int i = 0; i < nButtons; i++) {
    c = buttons[i].state ? buttons[i].onColor : buttons[i].offColor;

    Brain.Screen.setFillColor(c);

    // button fill
    Brain.Screen.drawRectangle(
        buttons[i].xpos, buttons[i].ypos, buttons[i].width, buttons[i].height
    );

    // draw label
    if (buttons[i].label != NULL)
      Brain.Screen.printAt(
          buttons[i].xpos + 8, buttons[i].ypos + buttons[i].height - 8, buttons[i].label
      );
  }
}

// Init button states
void initButtons() {
  for (int index = 0; index < nButtons; index++) { buttons[index].state = false; }
}

// Check if touch is inside button
int findButton(int16_t xpos, int16_t ypos) {
  for (int index = 0; index < nButtons; index++) {
    button* pButton = &buttons[index];

    if (xpos < pButton->xpos || xpos > (pButton->xpos + pButton->width)) continue;

    if (ypos < pButton->ypos || ypos > (pButton->ypos + pButton->height)) continue;

    return index;
  }

  return -1;
}

// Screen has been touched
void userTouchCallbackPressed() {
  int index;
  int xpos = Brain.Screen.xPosition();
  int ypos = Brain.Screen.yPosition();

  if ((index = findButton(xpos, ypos)) >= 0) { displayButtonControls(index, true); }
}

// Screen has been released
void userTouchCallbackReleased() {
  int index;
  int xpos = Brain.Screen.xPosition();
  int ypos = Brain.Screen.yPosition();

  if ((index = findButton(xpos, ypos)) >= 0) {
    // toggle button
    buttons[index].state = !buttons[index].state;

    displayButtonControls(index, false);
  }
}
