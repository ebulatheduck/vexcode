#include "main.h"
using namespace vex;

void driveDistance(directionType direction, double distance, distanceUnits units) {
  Drivetrain.drive(direction, 25, velocityUnits::pct);
  do { wait(50, msec); } while (Distance.objectDistance(units) >= distance);
}

void unMatchLoad(void) {
  // waitUntil(Distance.objectDistance(distanceUnits::cm) <= 22);
  driveDistance(forward, 22, distanceUnits::cm);
  Drivetrain.stop(brake);
  wait(1.5, sec);
  Drivetrain.driveFor(-.5, inches, 25, velocityUnits::pct);
  wait(1.5, sec);
}

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
  // RightDriveSmart.stop(brake);
  // wait(.5, sec);
  RightDriveSmart.stop();
  wait(5, sec);
  Scraper.set(false);
  intakeStop();
}
void blank4Auton() {
  Scraper.set(true);
  Hood.set(true);
  // driveOdom(6, forward, 25, velocityUnits::pct);
  // turnPID(90);
  driveOdom(34, forward, 25, velocityUnits::pct);
  turnPID(90);
  // Scraper.set(false);

  Intake.spin(forward, 70, velocityUnits::pct);
  unMatchLoad();
  Intake.stop();

  // Drivetrain.driveFor(16.5, inches, 25, velocityUnits::pct, false);
  // wait(1.5, sec);
  // Drivetrain.driveFor(-.5, inches, 25, velocityUnits::pct);
  // wait(1.5, sec);

  // Scraper.set(false);
  // wait(3, sec);
  // Drivetrain.setStopping(coast);
  // Drivetrain.driveFor(-16, inches, 25, velocityUnits::pct);
  Drivetrain.driveFor(-32, inches, 25, velocityUnits::pct);
  Hood.set(false);
  Intake.spin(forward, 70, velocityUnits::pct);
  wait(3, sec);
  Drivetrain.driveFor(4, inches, 25, velocityUnits::pct);

  turnPID(180);
  driveOdom(84, forward, 36, velocityUnits::pct);
  turnPID(90);

  Intake.spin(forward, 70, velocityUnits::pct);
  Drivetrain.setStopping(brake);
  unMatchLoad();
  // Scraper.set(true);
  // wait(3, sec);
  Drivetrain.driveFor(-16, inches, 25, velocityUnits::pct);
  Intake.stop();
  // Scraper.set(true);
}
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
void BlueLeftAuton() {
  driveOdom(20, forward, 50, velocityUnits::pct);
  Scraper.set(true);
  Hood.set(true);
  turnPID(-90);
  intakeForward();
  Drivetrain.driveFor(16, inches, 25, velocityUnits::pct, false);
  // wait(1, sec);
  // Drivetrain.driveFor(-1, inches, 25, velocityUnits::pct);
  wait(3, sec);
  intakeStop();
  Drivetrain.driveFor(-30, inches, 25, velocityUnits::pct);
  Hood.set(false);
  Drivetrain.driveFor(-4, inches, 25, velocityUnits::pct);
  // driveOdom(24, reverse, 25, velocityUnits::pct);
  intakeForward();
  wait(3, sec);
  intakeStop();
}
void BlueRightAuton() {
  Hood.set(true);
  Intake.spin(forward, 75, percent);
  Drivetrain.driveFor(36, inches, 15, velocityUnits::pct);
  wait(1, sec);
  turnPID(-80);
  Drivetrain.driveFor(20, inches, 25, velocityUnits::pct);
  Intake.spin(reverse, 60, percent);
  wait(2, sec);
  Intake.stop();
  // stage 2
  // Drivetrain.driveFor(-8, inches, 25, velocityUnits::pct);
  // turnPID(115);
  // Scraper.set(true);
  // // Drivetrain.driveFor(42, inches, 25, velocityUnits::pct);
  // driveOdom(30, forward, 25, velocityUnits::pct);

  // turnPID(160);
  // Intake.spin(forward, 75, percent);
  // Drivetrain.driveFor(20, inches, 25, velocityUnits::pct, false);
  // wait(3, sec);
  // Intake.stop();
  // Drivetrain.driveFor(-32, inches, 25, velocityUnits::pct);
  // Hood.set(false);
  // Intake.spin(reverse, 75, percent);
  // wait(2, sec);
  // Intake.stop();

  // alt stage 2
  Drivetrain.driveFor(-24, inches, 25, velocityUnits::pct);
  turnPID(-125);
  intakeForward();
  driveOdom(35, forward, 40, velocityUnits::pct);
  turnPID(-160);
  intakeStop();
  Drivetrain.driveFor(-16, inches, 25, velocityUnits::pct);
  Hood.set(false);
  intakeForward();
  wait(2, sec);
  intakeStop();
}

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