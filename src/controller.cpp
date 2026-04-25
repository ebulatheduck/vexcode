#include "main.h"
using namespace vex;

// File for controller callbacks

enum motorState { back, forth, stop };
motorState intakeState = stop;

void intakeForward(void) {
  Intake.spin(forward, 100, percent);
  intakeState = forth;
}

void intakeBackward(void) {
  Intake.spin(reverse, 100, percent);
  intakeState = back;
}

void intakeStop(void) {
  Intake.stop();
  intakeState = stop;
}

void intakeToggleForward(void) {
  if (intakeState != forth) {
    intakeForward();
  } else {
    intakeStop();
  }
}

void intakeToggleBackward(void) {
  if (intakeState != back) {
    intakeBackward();
  } else {
    intakeStop();
  }
}

void usercontrol(void) {
  // Add controller callbacks here
  Controller1.ButtonR1.pressed(intakeToggleForward);
  Controller1.ButtonR2.pressed(intakeToggleBackward);

  while (true) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
    int LDriveSpeed = 0, RDriveSpeed = 0;

    if (Controller1.ButtonRight.pressing() && !Competition.isCompetitionSwitch() &&
        !Competition.isFieldControl())
      autonomous();
    if (Controller1.ButtonLeft.pressing() && !Competition.isCompetitionSwitch() &&
        !Competition.isFieldControl()) {
      vexcodeInit();
      initButtons(0, false);
    }

    if (abs(Controller1.Axis3.position(percent)) > 15) {
      RDriveSpeed = Controller1.Axis3.position(percent) * .8;
    } else {
      RDriveSpeed = 0;
      RightDriveSmart.stop(brake);
    }

    if (abs(Controller1.Axis2.position(percent)) > 15) {
      LDriveSpeed = Controller1.Axis2.position(percent) * .8;
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