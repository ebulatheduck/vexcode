#include "main.h"
using namespace vex;

competition Competition;
brain Brain;
controller Controller1(primary);
controller Controller2(partner);

motor DriveRF(PORT5, ratio6_1, true);
motor DriveRM(PORT2, ratio6_1, true);
motor DriveRB(PORT9, ratio6_1, true);
motor DriveLF(PORT11, ratio6_1, false);
motor DriveLM(PORT18, ratio6_1, false);
motor DriveLB(PORT19, ratio6_1, false);

motor_group LeftDriveSmart(DriveLF, DriveLM, DriveLB);
motor_group RightDriveSmart(DriveRF, DriveRM, DriveRB);
inertial TurnGyroSmart(PORT20);
smartdrive Drivetrain(LeftDriveSmart, RightDriveSmart, TurnGyroSmart);
rotation Front(PORT1);
rotation Right(PORT8);

void vexcodeInit(void) {}