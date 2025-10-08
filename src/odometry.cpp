#include "main.h"
using namespace vex;

const double wheelDiameter = 2.00;
const double wheelCircumference = M_PI * wheelDiameter;
const double ticksPerRev = 360.0;
const double ticksPerInch = ticksPerRev / wheelCircumference;

double xPos = 0.0;
double zPos = 0.0;

double lastFrontTicks = 0.0;
double lastRightTicks = 0.0;

void trackPosition(void) {
  Front.resetPosition();
  Right.resetPosition();

  double lastFrontTicks = Front.position(degrees);
  double lastRightTicks = Right.position(degrees);

  while (1) {
    double frontTicks = Front.position(degrees);
    double rightTicks = Right.position(degrees);

    double deltaFront = frontTicks - lastFrontTicks;
    double deltaRight = rightTicks - lastRightTicks;

    lastFrontTicks = frontTicks;
    lastRightTicks = rightTicks;

    double deltaFrontInches = deltaFront / ticksPerInch;
    double deltaRightInches = deltaRight / ticksPerInch;

    zPos += deltaFrontInches;
    xPos += deltaRightInches;

    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1, 1);
    Controller1.Screen.print("X: %.2f Z: %.2f", xPos, zPos);

    wait(100, msec);
  }
}

void driveOdom(double inches, directionType direction, double velocity, velocityUnits units) {
  double targetTicks = inches * ticksPerInch;
  Front.resetPosition();
  Right.resetPosition();

  printf("Position reset\n");

  // Start moving both drive motors forward
  LeftDriveSmart.spin(direction, velocity, units);
  RightDriveSmart.spin(direction, velocity, units);

  printf("Motors started\n");

  while (Front.position(degrees) + 20 < targetTicks) {
    Controller1.Screen.setCursor(1, 1);
    Controller1.Screen.print(Front.position(degrees));
    if (Controller1.ButtonLeft.pressing()) break;  // manual stop
    wait(10, msec);
  }

  // Stop the drive motors
  LeftDriveSmart.stop(brake);
  RightDriveSmart.stop(brake);

  printf("Error: %.2f inches\n", (Front.position(degrees) - targetTicks) / ticksPerInch);

  printf("Motors stopped\n");
}