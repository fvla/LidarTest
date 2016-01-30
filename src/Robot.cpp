#include "WPILib.h"

#define I2C_SLAVE_ADR 0x53

/**
 * This is a demo program showing how to use Mecanum control with the RobotDrive class.
 */
class Robot: public SampleRobot
{
   I2C * i2cChannel;

public:
  Robot()
  {
    SmartDashboard::init();
    i2cChannel = new I2C(I2C::kOnboard, I2C_SLAVE_ADR);
  }

  ~Robot() {
     delete i2cChannel;
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
