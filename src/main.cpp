#include "main.h"
using namespace vex;

int main(void) {
  printf("\033[H\033[J");  // Clear console

  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  printf("Registered auton and driver control methods\n");

  // Prevent main from exiting with an infinite loop
  while (true) { wait(10, msec); }
}
