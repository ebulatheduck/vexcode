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

competition Competition;
brain Brain;
controller Controller1 = controller(primary);
controller Controller2 = controller(partner);

// fake values, configure later
motor FrontL = motor(PORT1, ratio18_1, false);
motor BackL = motor(PORT2, ratio18_1, false);
motor FrontR = motor(PORT3, ratio18_1, false);
motor BackR = motor(PORT4, ratio18_1, false);

motor_group LeftDriveSmart = motor_group(FrontL, BackL);
motor_group RightDriveSmart = motor_group(FrontR, BackR);
inertial TurnGyroSmart = inertial(PORT1);
smartdrive Drivetrain = smartdrive(LeftDriveSmart, RightDriveSmart, TurnGyroSmart);

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
void pre_auton(void) {}

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
  if (!Competition.isEnabled()) Controller1.ButtonRight.pressed(testauton);

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
  printf("Registered auton and driver control methods\n");

  // Set up brain touch callbacks
  Brain.Screen.pressed(userTouchCallbackPressed);
  Brain.Screen.released(userTouchCallbackReleased);
  printf("Registered brain touch callbacks\n");

  // Make nice background
  Brain.Screen.setFillColor(color(0x404040));
  Brain.Screen.setPenColor(color(0x404040));
  Brain.Screen.drawRectangle(0, 0, 480, 120);
  Brain.Screen.setFillColor(color(0x808080));
  Brain.Screen.setPenColor(color(0x808080));
  Brain.Screen.drawRectangle(0, 120, 480, 120);

  // Initial button display
  displayButtons(0, false);

  printf("Ready\n");

  // Prevent main from exiting with an infinite loop
  if (!Competition.isEnabled()) {
    Brain.Screen.setFont(fontType::mono40);
    Brain.Screen.setFillColor(color(0xFFFFFF));
    Brain.Screen.setPenColor(color(0xc11f27));
    Brain.Screen.printAt(0, 135, "Cibola Robotics");
  }

  while (true) { wait(10, msec); }
}
