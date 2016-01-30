/*
 * LidarHandler.cpp
 *
 *  Created on: Jan 30, 2016
 *      Author: Ian
 */

#include <LidarHandler.h>

LidarHandler::LidarHandler() {
   m_i2cChannel = new I2C(I2C::kOnboard, I2C_SLAVE_ADR);
}

LidarHandler::~LidarHandler() {
   delete m_i2cChannel;
}

