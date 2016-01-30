/*
 * LidarHandler.h
 *
 *  Created on: Jan 30, 2016
 *      Author: Ian
 */

#include "WPILib.h"

#ifndef SRC_LIDARHANDLER_H_
#define SRC_LIDARHANDLER_H_

#define I2C_SLAVE_ADR 0x62
#define REGISTER_MEASURE 0x00
#define MEASURE_VALUE 0x04
#define REGISTER_HIGH_LOWB 0x8f

class LidarHandler {

   I2C * m_i2cChannel;

public:
   LidarHandler();

   void init();
   void loop();

   virtual ~LidarHandler();
};

#endif /* SRC_LIDARHANDLER_H_ */
