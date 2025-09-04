#include "main.h"
using namespace vex;

competition Competition;
brain Brain;
controller Controller1(primary);
controller Controller2(partner);

// fake values, configure later
motor DriveRF(PORT8, ratio6_1, false);
motor DriveRM(PORT3, ratio6_1, false);
motor DriveRB(PORT6, ratio6_1, false);
motor DriveLF(PORT15, ratio6_1, true);
motor DriveLM(PORT17, ratio6_1, true);
motor DriveLB(PORT18, ratio6_1, true);

motor_group LeftDriveSmart(DriveLF, DriveLM, DriveLB);
motor_group RightDriveSmart(DriveRF, DriveRM, DriveRB);
inertial TurnGyroSmart(PORT1);
smartdrive Drivetrain(LeftDriveSmart, RightDriveSmart, TurnGyroSmart);

void vexcodeInit(void) {}