#include "main.h"
using namespace vex;

competition Competition;
brain Brain;
controller Controller1 = controller(primary);
controller Controller2 = controller(partner);

// fake values, configure later
motor FrontL = motor(PORT1, ratio18_1, false);
motor BackL = motor(PORT2, ratio18_1, false);
motor FrontR = motor(PORT3, ratio18_1, false);
motor BackR = motor(PORT4, ratio18_1, false);

motor_group LeftDriveSmart = motor_group(FrontL, BackL);
motor_group RightDriveSmart = motor_group(FrontR, BackR);
inertial TurnGyroSmart = inertial(PORT1);
smartdrive Drivetrain = smartdrive(LeftDriveSmart, RightDriveSmart, TurnGyroSmart);
