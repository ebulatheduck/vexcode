#include "main.h"
using namespace vex;

competition Competition;
brain Brain;
controller Controller1(primary);
controller Controller2(partner);

motor DriveRF(PORT11, ratio6_1, true); //2
motor DriveRM(PORT12, ratio6_1, true); //3
motor DriveRB(PORT13, ratio6_1, true); //4
motor DriveLF(PORT2, ratio6_1, false); //11
motor DriveLM(PORT3, ratio6_1, false); //12
motor DriveLB(PORT4, ratio6_1, false); //13

motor_group LeftDriveSmart(DriveLF, DriveLM, DriveLB);
motor_group RightDriveSmart(DriveRF, DriveRM, DriveRB);
inertial TurnGyroSmart(PORT18);
smartdrive Drivetrain(LeftDriveSmart, RightDriveSmart, TurnGyroSmart);
rotation Front(PORT20);
rotation Right(PORT19);

motor Intake(PORT1);

void vexcodeInit(void) {
  Brain.Screen.print("Device initialization...");
  Brain.Screen.setCursor(2, 1);
  // calibrate the drivetrain gyro
  wait(200, msec);
  TurnGyroSmart.calibrate();
  Brain.Screen.print("Calibrating Gyro for Drivetrain");
  // wait for the gyro calibration process to finish
  waitUntil(!TurnGyroSmart.isCalibrating());
  // reset the screen now that the calibration is complete
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1, 1);
  wait(50, msec);
  Brain.Screen.clearScreen();
}