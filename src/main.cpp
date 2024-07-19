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

  buttons.begin();
  i2c.begin(8,requestEvent);
}

void loop() {

  // put your main code here, to run repeatedly:

  buttons.listener();
}

void requestEvent() {

  // get called every time the master requests data

  i2c.event();
}