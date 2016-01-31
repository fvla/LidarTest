#include "WPILib.h"
#include "LidarHandler.h"

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
     lidarHandler.~LidarHandler();
  }

  void Test()
  {
    while (IsTest() && IsEnabled())
      {
       lidarHandler.loop();
       if(SmartDashboard::GetBoolean("DB/Button 1", false)) {
          SmartDashboard::PutBoolean("DB/Button 1", false);
          lidarHandler.init();
       }
      }
  }
};

START_ROBOT_CLASS(Robot)
