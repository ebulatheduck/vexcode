#pragma once

#include "vex.h"
using namespace vex;

void trackPosition(void);
void driveOdom(double inches, directionType direction, double velocity, velocityUnits units);