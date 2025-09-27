#include "main.h"
using namespace vex;

const double wheelDiameter = 2.00;
const double wheelCircumference = M_PI * wheelDiameter;

double absoluteAngle = 0;

void trackPosition() {
  Right.resetPosition();
  Front.resetPosition();

  while (1) { wait(100, msec); }
}
