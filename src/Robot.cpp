#include "WPILib.h"

#define I2C_SLAVE_ADR 0x53

/**
 * This is a demo program showing how to use Mecanum control with the RobotDrive class.
 */
class Robot: public SampleRobot
{
   LidarHandler lidarHandler;

public:
  Robot():
     lidarHandler()
  {
    SmartDashboard::init();
  }

  ~Robot() {

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
