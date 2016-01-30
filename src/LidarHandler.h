/*
 * LidarHandler.h
 *
 *  Created on: Jan 30, 2016
 *      Author: Ian
 */

#include "WPILib.h"

#ifndef SRC_LIDARHANDLER_H_
#define SRC_LIDARHANDLER_H_

#define I2C_SLAVE_ADR 0x53
#define ADXL_CONFIG_PORT 0x2d

class LidarHandler {

   I2C * m_i2cChannel;

public:
   LidarHandler();

   void init();
   void loop();

   virtual ~LidarHandler();
};

#endif /* SRC_LIDARHANDLER_H_ */
