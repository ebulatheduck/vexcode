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

    // Sleep the task for a short amount of time to prevent wasted resources.
    wait(20, msec);
  }
}

void testauton(void) { printf("Autonomous started\n"); }
