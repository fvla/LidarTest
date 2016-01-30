/*
 * LidarHandler.cpp
 *
 *  Created on: Jan 30, 2016
 *      Author: Ian
 */

#include "LidarHandler.h"

LidarHandler::LidarHandler() {
   m_i2cChannel = new I2C(I2C::kOnboard, I2C_SLAVE_ADR);
}

LidarHandler::~LidarHandler() {
   delete m_i2cChannel;
}

void LidarHandler::init() {

}

void LidarHandler::loop() {
   short response = 100;
   while(response != 0) {
      response = m_i2cChannel->Write(REGISTER_MEASURE, MEASURE_VALUE);
      Wait(0.001);
   }

   unsigned char distanceArray[2];

   response = 100;
   while(response != 0) {
      response = m_i2cChannel->Read(REGISTER_MEASURE, REGISTER_HIGH_LOWB, distanceArray);
      Wait(0.001);
   }

   int distance = (distanceArray[0] << 8) + distanceArray[1];

   std::stringstream ss;
   ss << distance;
   SmartDashboard::PutString("DB/String 1", ss.str());
}

