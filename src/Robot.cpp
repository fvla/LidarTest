#include "WPILib.h"
#include "LidarHandler.h"

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
    lidarHandler.init();
  }

  ~Robot() {

  }

  void Test()
  {
    while (IsTest() && IsEnabled())
      {
       SmartDashboard::PutString("DB/String 0", "Test");
       lidarHandler.loop();
      }
  }
};

START_ROBOT_CLASS(Robot)
