#include "main.h"
using namespace vex;

void blank1Auton() { Drivetrain.driveFor(12, inches, 50, velocityUnits::pct); }
void blank2Auton() {
  Drivetrain.driveFor(20, inches);
  intakeForward();
  wait(2, seconds);
  intakeStop();
}
void blank3Auton() {
  intakeForward();
  RightDriveSmart.spin(forward, 100, velocityUnits::pct);
  wait(0.75, sec);
  Scraper.set(true);
  //  RightDriveSmart.stop(brake);
  //  wait(.5, sec);
  RightDriveSmart.stop();
  wait(5, sec);
  Scraper.set(false);
  intakeStop();
}
void blank4Auton() {}
void RedLeftAuton() {}
void RedRightAuton() {
  Hood.set(true);
  Intake.spin(forward, 75, percent);
  Drivetrain.driveFor(36, inches, 15, velocityUnits::pct);
  wait(1, sec);
  turnPID(-80);
  Drivetrain.driveFor(20, inches, 25, velocityUnits::pct);
  Intake.spin(reverse, 75, percent);
  wait(2, sec);
  Intake.stop();
  // Drivetrain.driveFor(-8, inches, 25, velocityUnits::pct);
  // turnPID(115);
  // Scraper.set(true);
  // Drivetrain.driveFor(42, inches, 25, velocityUnits::pct);
  // turnPID(180);
  // Intake.spin(forward, 75, percent);
  // Drivetrain.driveFor(20, inches, 25, velocityUnits::pct, false);
  // Drivetrain.driveFor(5, inches, 50, velocityUnits::pct);
  // Drivetrain.driveFor(5, inches, 50, velocityUnits::pct);
  // Intake.stop();
  // Drivetrain.driveFor(-32, inches, 25, velocityUnits::pct);
  // Hood.set(false);
  // Intake.spin(reverse, 75, percent);
  // wait(2, sec);
  // Intake.stop();
}
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

  printf("Autonomous started\n");

  if (blank1) blank1Auton();
  if (blank2) blank2Auton();
  if (blank3) blank3Auton();
  if (blank4) blank4Auton();
  if (RedLeft) RedLeftAuton();
  if (RedRight) RedRightAuton();
  if (BlueLeft) BlueLeftAuton();
  if (BlueRight) BlueRightAuton();

  printf("Autonomous stopped\n");
}