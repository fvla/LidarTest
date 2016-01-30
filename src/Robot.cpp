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

  void OperatorControl()
  {
    SmartDashboard::PutString("DB/String 0", " ");
    SmartDashboard::PutString("DB/String 1", " ");
    while (IsOperatorControl() && IsEnabled())
      {
	SmartDashboard::PutString("DB/String 0", "Test");
	SmartDashboard::PutString("DB/String 1", "Test");
      }
  }

  void Test()
  {
    SmartDashboard::PutString("DB/String 0", " ");
    SmartDashboard::PutString("DB/String 1", " ");
    while (IsTest() && IsEnabled())
      {
	SmartDashboard::PutString("DB/String 0", "Test");
	SmartDashboard::PutString("DB/String 1", "Test");
      }
  }
};

START_ROBOT_CLASS(Robot)
