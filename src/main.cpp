/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       rhime                                                     */
/*    Created:      3/9/2025, 8:42:11 AM                                      */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "main.h"
#include "display.h"
#include "controller.h"
#include "pid.h"
using namespace vex;

competition Competition;
brain Brain;
controller Controller1;
controller Controller2;

// motor_group LeftDriveSmart = motor_group(NULL, NULL);
// motor_group RightDriveSmart = motor_group(NULL, NULL);
// smartdrive Drivetrain = smartdrive(LeftDriveSmart, RightDriveSmart);

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
void pre_auton(void) {
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
void autonomous(void) {}

// For testing auton
void testauton(void) {}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
void usercontrol(void) {
  // Add controller callbacks here
  Controller1.ButtonRight.pressed(testauton);

  while (true) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // Sleep the task for a short amount of time to prevent wasted resources.
    wait(20, msec);
  }
}

int main(void) {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Set up brain touch callbacks
  Brain.Screen.pressed(userTouchCallbackPressed);
  Brain.Screen.released(userTouchCallbackReleased);

  // Make nice background
  Brain.Screen.setFillColor(vex::color(0x404040));
  Brain.Screen.setPenColor(vex::color(0x404040));
  Brain.Screen.drawRectangle(0, 0, 480, 120);
  Brain.Screen.setFillColor(vex::color(0x808080));
  Brain.Screen.setPenColor(vex::color(0x808080));
  Brain.Screen.drawRectangle(0, 120, 480, 120);

  // Initial button display
  displayButtonControls(0, false);

  // Run the pre-autonomous function
  pre_auton();

  // Prevent main from exiting with an infinite loop
  while (true) {
    if (!Competition.isEnabled()) {
      Brain.Screen.setFont(fontType::mono40);
      Brain.Screen.setFillColor(vex::color(0xFFFFFF));
      Brain.Screen.setPenColor(vex::color(0xc11f27));
      Brain.Screen.printAt(0, 135, "Cibola Robotics");
    }

    this_thread::sleep_for(10);
  }
}
