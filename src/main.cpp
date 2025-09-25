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
  printf(
      "\033[H"
      "\033[J"
  );  // Clear console

  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  printf("Registered auton and driver control methods\n");

  // Set up brain touch callbacks
  Brain.Screen.pressed(userTouchCallbackPressed);
  Brain.Screen.released(userTouchCallbackReleased);
  printf("Registered brain touch callbacks\n");

  // initOdometry();
  thread TrackPosThread(trackPosition);
  printf("Registered odometry methods\n");

  // Make nice background
  Brain.Screen.setFillColor(color(0x404040));
  Brain.Screen.setPenColor(color(0x404040));
  Brain.Screen.drawRectangle(0, 0, 480, 120);
  Brain.Screen.setFillColor(color(0x808080));
  Brain.Screen.setPenColor(color(0x808080));
  Brain.Screen.drawRectangle(0, 120, 480, 120);

  // Initial button display
  displayButtons(0, false);

  Brain.Screen.setFont(fontType::mono20);
  Brain.Screen.setFillColor(color(0xFFFFFF));
  Brain.Screen.setPenColor(color(0xc11f27));
  Brain.Screen.printAt(0, 135, "Cibola Robotics");

  printf("Ready\n");

  // Prevent main from exiting with an infinite loop
  while (true) wait(10, msec);
}
