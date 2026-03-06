// Global instances of objects
#include "vex.h"

using namespace vex;

extern competition Competition;
extern brain Brain;
extern controller Controller1;
extern controller Controller2;

extern motor FrontL;
extern motor BackL;
extern motor FrontR;
extern motor BackR;

extern motor_group LeftDriveSmart;
extern motor_group RightDriveSmart;
extern inertial TurnGyroSmart;
extern smartdrive Drivetrain;
extern rotation Front;
extern rotation Right;
extern distance Distance;

extern motor_group Intake;
extern digital_out Hood;
extern digital_out Scraper;
extern digital_out Wing;

void vexcodeInit(void);