/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       rhime                                                     */
/*    Created:      3/9/2025, 8:42:11 AM                                      */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "main.h"
using namespace vex;

int main(void) {
  printf("\033[H\033[J");  // Clear console

  vexcodeInit();
  printf("Initialized devices\n");

  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  printf("Registered auton and driver control methods\n");

  // Set up brain touch callbacks
  Brain.Screen.pressed(userTouchCallbackPressed);
  Brain.Screen.released(userTouchCallbackReleased);
  printf("Registered brain touch callbacks\n");

  // thread TrackPosThread(trackPosition);
  // printf("Registered odometry methods\n");

  initButtons(3, testMode());

  printf("Competition mode %d\n", Competition.isEnabled());
  printf("Competition switch %d\n", Competition.isCompetitionSwitch());
  printf("Field control %d\n", Competition.isFieldControl());

  printf("Ready\n");

  // Prevent main from exiting with an infinite loop
  while (true) wait(10, msec);
}

bool testMode(void) { return !Competition.isCompetitionSwitch() && !Competition.isFieldControl(); }
