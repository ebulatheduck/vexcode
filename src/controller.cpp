#include "main.h"
using namespace vex;

// File for controller callbacks

void usercontrol(void) {
  // Add controller callbacks here
  if (!Competition.isEnabled()) Controller1.ButtonRight.pressed(testauton);

  while (true) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
    int LDriveSpeed = 0, RDriveSpeed = 0;

    if (abs(Controller1.Axis3.position(percent)) > 15) {
      LDriveSpeed = Controller1.Axis3.position(percent);
    } else {
      LDriveSpeed = 0;
    }

    if (abs(Controller1.Axis2.position(percent)) > 15) {
      RDriveSpeed = Controller1.Axis2.position(percent);
    } else {
      RDriveSpeed = 0;
    }

    LeftDriveSmart.spin(forward, LDriveSpeed, percent);
    RightDriveSmart.spin(forward, RDriveSpeed, percent);

    // Sleep the task for a short amount of time to prevent wasted resources.
    wait(20, msec);
  }
}

void testauton(void) {
  printf("Autonomous started");
  driveOdom(12, forward, 50, velocityUnits::pct);
}