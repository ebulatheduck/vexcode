#include "main.h"
using namespace vex;

competition Competition;
brain Brain;
controller Controller1(primary);
controller Controller2(partner);

motor DriveRF(PORT20, ratio6_1, true);
motor DriveRM(PORT19, ratio6_1, true);
motor DriveRB(PORT18, ratio6_1, true);
motor DriveLF(PORT11, ratio6_1, false);
motor DriveLM(PORT12, ratio6_1, false);
motor DriveLB(PORT13, ratio6_1, false);

motor_group LeftDriveSmart(DriveLF, DriveLM, DriveLB);
motor_group RightDriveSmart(DriveRF, DriveRM, DriveRB);
inertial TurnGyroSmart(PORT15);
smartdrive Drivetrain(LeftDriveSmart, RightDriveSmart, TurnGyroSmart);
// rotation Front(PORT20);
// rotation Right(PORT1);

motor Intake1(PORT1);
motor Intake2(PORT2);
motor_group Intake(Intake1, Intake2);
digital_out Scraper(Brain.ThreeWirePort.A);
digital_out Hood(Brain.ThreeWirePort.B);

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