#include "main.h"
using namespace vex;

// Button array definitions for each software button. The button data structure is defined in
// `display.h`. The array size can be extended, so you can have as many buttons as you wish as long
// as they fit on the screen.
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
void displayButtons(int index, bool pressed) {
  color c;
  Brain.Screen.setPenColor(color(0xe0e0e0));

  repeat(nButtons) {
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

// Check if touch is inside button
int findButton(int16_t xpos, int16_t ypos) {
  repeat(nButtons) {
    button* pButton = &buttons[i];

    if (xpos < pButton->xpos || xpos > (pButton->xpos + pButton->width)) continue;

    if (ypos < pButton->ypos || ypos > (pButton->ypos + pButton->height)) continue;

    return i;
  }

  return -1;
}

// Screen has been touched
void userTouchCallbackPressed() {
  int index;
  int xpos = Brain.Screen.xPosition();
  int ypos = Brain.Screen.yPosition();

  if ((index = findButton(xpos, ypos)) >= 0) { displayButtons(index, true); }
}

// Screen has been released
void userTouchCallbackReleased() {
  int index;
  int xpos = Brain.Screen.xPosition();
  int ypos = Brain.Screen.yPosition();

  if ((index = findButton(xpos, ypos)) >= 0) {
    // toggle button
    buttons[index].state = !buttons[index].state;

    displayButtons(index, false);
  }
}
