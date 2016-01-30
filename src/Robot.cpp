#include "WPILib.h"

/**
 * This is a demo program showing how to use Mecanum control with the RobotDrive class.
 */
class Robot: public SampleRobot
{
public:
  Robot()
  {
    SmartDashboard::init();
  }

  void Test()
  {
    while (IsTest() && IsEnabled())
      {
	SmartDashboard::PutString("DB/String 0", "Test");
      }
  }
};

START_ROBOT_CLASS(Robot)
