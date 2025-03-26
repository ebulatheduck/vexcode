#ifndef MAIN_H
#define MAIN_H

#include "vex.h"
#include "display.h"
#include "controller.h"
#include "pid.h"
using namespace vex;

// Global instances of objects

extern competition Competition;
extern brain Brain;
extern controller Controller1;
extern controller Controller2;

extern motor FrontL;
extern motor BackL;
extern motor FrontR;
extern motor BackR;

extern motor_group LeftDriveSmart;
extern motor_group RightDriveSmart;
extern inertial TurnGyroSmart;
extern smartdrive Drivetrain;

#endif
