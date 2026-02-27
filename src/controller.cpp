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

void scraperPistonToggle(void) { Scraper.set(!Scraper.value()); }
void hoodPistonToggle(void) { Hood.set(!Hood.value()); }
void wingPistonToggle(void) { Wing.set(!Wing.value()); }

void usercontrol(void) {
  printf("Driver Control Started\n");

  // Add controller callbacks here
  Controller1.ButtonR1.pressed(intakeToggleForward);
  Controller1.ButtonR2.pressed(intakeToggleBackward);
  Controller1.ButtonL1.pressed(wingPistonToggle);
  Controller1.ButtonL2.pressed(hoodPistonToggle);
  Controller1.ButtonDown.pressed([] { Drivetrain.setStopping(brake); });
  Controller1.ButtonB.pressed([] { Drivetrain.setStopping(coast); });
  Controller1.ButtonY.pressed(scraperPistonToggle);
  while (true) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
    int LDriveSpeed = 0, RDriveSpeed = 0;

    if (Controller1.ButtonRight.pressing() && testMode()) autonomous();
    if (Controller1.ButtonLeft.pressing() && testMode()) {
      vexcodeInit();
      initButtons(0, false);
    }

    if (abs(Controller1.Axis3.position(percent)) > 15) {
      RDriveSpeed = Controller1.Axis3.position(percent) * .8;
    } else {
      RDriveSpeed = 0;
      // RightDriveSmart.stop(brake);
    }

    if (abs(Controller1.Axis2.position(percent)) > 15) {
      LDriveSpeed = Controller1.Axis2.position(percent) * .8;
    } else {
      LDriveSpeed = 0;
      // LeftDriveSmart.stop(brake);
    }

    LeftDriveSmart.spin(forward, LDriveSpeed, percent);
    RightDriveSmart.spin(forward, RDriveSpeed, percent);

    // Sleep the task for a short amount of time to prevent wasted resources.
    wait(20, msec);
  }
}