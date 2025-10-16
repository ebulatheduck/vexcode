#include "main.h"
using namespace vex;

competition Competition;
brain Brain;
controller Controller1(primary);
controller Controller2(partner);

motor DriveRF(PORT5, ratio6_1, true);
motor DriveRM(PORT2, ratio6_1, true);
motor DriveRB(PORT6, ratio6_1, true);
motor DriveLF(PORT9, ratio6_1, false);
motor DriveLM(PORT8, ratio6_1, false);
motor DriveLB(PORT7, ratio6_1, false);

motor_group LeftDriveSmart(DriveLF, DriveLM, DriveLB);
motor_group RightDriveSmart(DriveRF, DriveRM, DriveRB);
inertial TurnGyroSmart(PORT1);
smartdrive Drivetrain(LeftDriveSmart, RightDriveSmart, TurnGyroSmart);
rotation Front(PORT20);
rotation Right(PORT1);

motor Intake(PORT20);

void vexcodeInit(void) {}