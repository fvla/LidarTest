/*
 * LidarHandler.cpp
 *
 *  Created on: Jan 30, 2016
 *      Author: Ian
 */

#include "LidarHandler.h"

LidarHandler::LidarHandler() {
   m_i2cChannel = new I2C(I2C::kMXP, I2C_SLAVE_ADR);
}

LidarHandler::~LidarHandler() {
   delete m_i2cChannel;
}

void LidarHandler::init() {
   counter = 0;
   successCounter = 0;
}

void LidarHandler::loop() {
   m_i2cChannel->Write(REGISTER_MEASURE, MEASURE_VALUE);

   std::stringstream ss2;
   ss2 << counter;
   std::stringstream ss3;
   if(counter == 0)
      ss3 << 0;
   else
      ss3 << ((double) successCounter / counter) * 100;

   SmartDashboard::PutString("DB/String 5","Lidar call # = " + ss2.str());
   SmartDashboard::PutString("DB/String 6","Successes " + ss3.str());

   Wait(0.05); //in between write and read requests

   byte high;
   byte low;

   m_i2cChannel->Read(REGISTER_HIGHB, 1, &high);
   m_i2cChannel->Read(REGISTER_LOWB, 1, &low);

   int distance = (high << 8) + low;

   if(distance != 0) {
      successCounter++;
   }
   counter++;
   if(counter == 50) {
      init();
   }

   std::stringstream ss;
   ss << distance;
   SmartDashboard::PutString("DB/String 0", "Lidar Distance = " + ss.str());
}

