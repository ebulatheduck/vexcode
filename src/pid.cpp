#include "vex.h"
#include "main.h"
using namespace vex;

// Used to count the number of turns for output data only
int turnCount = 0;

// Weighted factor of proportion error
double kP = .16;
// Weighted factor of integral error
double kI = .01;
// Weighted factor of derivated error
double kD = 0;

// Max speed in volts for motors
double maxSpeed = 8;

// The angle difference from eror when integral adjustments turns on
int turnThreshold = 10;
// Tolerance for approximating the target angle
double turnTolerance = .7;

// Total number of iterations to exit while loop
int maxIter = 200;

// Turning Function
void turnPID(double angleTurn) {
  int loopCount = 0;

  while (loopCount < 2) {
    // Distance to target in degrees
    double error = 0;
    // Error degree from the last iteration
    double prevError = 0;
    // Derivative of the error. The slope between iterations
    double derivative = 0;
    // Accumulated error after threshold. Summing error
    double integral = 0;
    // Iterations of the loop. Counter used to exit loop if not converging
    double iter = 0;

    while (
      fabs(TurnGyroSmart.rotation(degrees) - angleTurn) > turnTolerance &&
      iter < maxIter
    ) {
      // Checking if error passes threshold to build the integral
      if (fabs(error) < turnThreshold && error != 0) {
        integral += error;
      } else {
        integral = 0;
      }

      // Voltage to use. PID calculation
      double powerDrive = error * kP + derivative * kD + integral * kI;

      // Capping voltage to max speed
      if (powerDrive > maxSpeed) {
        powerDrive = maxSpeed;
      } else if (powerDrive < -maxSpeed) {
        powerDrive = -maxSpeed;
      }

      LeftDriveSmart.spin(forward, powerDrive, voltageUnits::volt);
      RightDriveSmart.spin(forward, -powerDrive, voltageUnits::volt);

      this_thread::sleep_for(10);
    }

    // Turning data, output to screen
    turnCount += 1;
    error = angleTurn - TurnGyroSmart.rotation(degrees);
    derivative = error - prevError;
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1, 1);
    Controller1.Screen.print("Turn #: %d", turnCount);
    Controller1.Screen.setCursor(1, 13);
    Controller1.Screen.print("iter: %.0f", iter);
    Controller1.Screen.newLine();
    Controller1.Screen.print("error: %.5f", error);
    Controller1.Screen.newLine();
    Controller1.Screen.print("derivative: %.5f", derivative);
    Controller1.Screen.newLine();
    loopCount++;
  }
}
