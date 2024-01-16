#include "vex.h"
#include "robutDriver.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain Brain;

// define your global instances of motors and other devices here
int turnDir = 0;
int cycleNum = 0;

// const int left = 1;
// const int right = -1;
motor motor0 = motor(PORT1, ratio18_1, false);
motor motor1 = motor(PORT2, ratio18_1, false);
motor motor2 = motor(PORT3, ratio18_1, false);
bumper buton = bumper(Brain.ThreeWirePort.A);
robutMovement robut = robutMovement(motor0, motor1, motor2);

int main()
{
    Brain.Screen.printAt(10, 50, "Hello V5");

    while (cycleNum < 5)
    {
        waitUntil(buton.pressing());
        robut.moveDistance(100, 0, 15);
    }
}
