#include "main.h"
using namespace vex;

void blank1Auton() {}
void blank2Auton() {}
void blank3Auton() {}
void blank4Auton() {}
void RedLeftAuton() {}
void RedRightAuton() {}
void BlueLeftAuton() {}
void BlueRightAuton() {}

void autonomous(void) {
  bool blank1 = buttons[0].state;
  bool blank2 = buttons[1].state;
  bool blank3 = buttons[2].state;
  bool blank4 = buttons[3].state;
  bool RedLeft = buttons[4].state;
  bool RedRight = buttons[5].state;
  bool BlueLeft = buttons[6].state;
  bool BlueRight = buttons[7].state;

  if (blank1) blank1Auton();
  if (blank2) blank2Auton();
  if (blank3) blank3Auton();
  if (blank4) blank4Auton();
  if (RedLeft) RedLeftAuton();
  if (RedRight) RedRightAuton();
  if (BlueLeft) BlueLeftAuton();
  if (BlueRight) BlueRightAuton();
}