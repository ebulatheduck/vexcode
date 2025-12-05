#include "main.h"
using namespace vex;

void autonomous(void) {}

bool a = false, b = false;
void usercontrol(void) {
  // Add controller callbacks here
  if (!Competition.isEnabled()) Controller1.ButtonRight.pressed(testauton);

  Controller1.ButtonA.pressed([] {
    a = !a;
    ThreeWireA.set(a);
    printf("a%d", a);
  });

  Controller1.ButtonB.pressed([] {
    b = !b;
    ThreeWireA.set(b);
    printf("b%d", b);
  });

  while (true) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // Sleep the task for a short amount of time to prevent wasted resources.
    wait(20, msec);
  }
}

int main(void) {
  printf("\033[H\033[J");  // Clear console

  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  printf("Registered auton and driver control methods\n");

  // Prevent main from exiting with an infinite loop
  while (true) { wait(10, msec); }
}
