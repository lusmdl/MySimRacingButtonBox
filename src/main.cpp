/**
 * @file main.cpp
 * @brief Main file for the project.
 */

#include <Arduino.h>
#include "ProjectConfig.hpp"
#include "WheelButtons/Buttons.hpp"
#include "WheelButtons/ComI2C.hpp"

/// @brief Manages button states
Buttons buttons;

/// @brief  Manages I2C communication
/// @param  Wire from Wire.h lib
/// @param  buttons has to be instaced
/// @return 
ComI2C i2c(Wire, buttons);

/// @brief I2C request event handler
void requestEvent();

void setup() {

  // put your setup code here, to run once:

  #ifdef LUSMDL_DEBUGMODE
  Serial.begin(9600);
  Serial.print("setup\n");
  #endif

  // init buttons
  buttons.begin();

  // init the I2C communication as a Slave
  // it is important to change the Address in the '\include\ProjectConfig.hpp' so that no slave have the same adress
  i2c.begin(I2C_ADDR,requestEvent);

}

void loop() {

  // put your main code here, to run repeatedly:
  // the only task is to listen for any buttons

  buttons.listener();
}

void requestEvent() {

  // get called every time the master requests data

  i2c.event();
}