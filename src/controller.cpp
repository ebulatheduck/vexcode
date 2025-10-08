#include "main.h"
using namespace vex;

// File for controller callbacks
bool intakeState = false;

void intakeForward(void) {
  if (!intakeState) {
    Intake.spin(forward, 100, percent);
    intakeState = true;
  } else {
    Intake.stop();
    intakeState = false;
  }
}

void intakeBackward(void) {
  if (!intakeState) {
    Intake.spin(reverse, 100, percent);
    intakeState = true;
  } else {
    Intake.stop();
    intakeState = false;
  }
}

void usercontrol(void) {
  // Add controller callbacks here
  Controller1.ButtonR1.pressed(intakeForward);
  Controller1.ButtonR2.pressed(intakeBackward);

  while (true) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
    int LDriveSpeed = 0, RDriveSpeed = 0;

    if (Controller1.ButtonRight.pressing()) testauton();

    if (abs(Controller1.Axis3.position(percent)) > 15) {
      RDriveSpeed = Controller1.Axis3.position(percent);
    } else {
      RDriveSpeed = 0;
      RightDriveSmart.stop(brake);
    }

    if (abs(Controller1.Axis2.position(percent)) > 15) {
      LDriveSpeed = Controller1.Axis2.position(percent);
    } else {
      LDriveSpeed = 0;
      LeftDriveSmart.stop(brake);
    }

    LeftDriveSmart.spin(forward, LDriveSpeed, percent);
    RightDriveSmart.spin(forward, RDriveSpeed, percent);

    // Sleep the task for a short amount of time to prevent wasted resources.
    wait(20, msec);
  }
}

void testauton(void) {
  printf("Autonomous started\n");
  driveOdom(12, forward, 25, velocityUnits::pct);
  // turnPID(90);
  printf("Autonomous stopped\n");
}