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

void LidarHandler::init() {
   m_i2cChannel->Write(ADXL_CONFIG_PORT, 0);
   m_i2cChannel->Write(ADXL_CONFIG_PORT, 16);
   m_i2cChannel->Write(ADXL_CONFIG_PORT, 8);
}

void LidarHandler::loop() {

}

