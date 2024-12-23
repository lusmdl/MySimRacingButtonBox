/**
 * @file main.cpp
 * @brief Demonstrates I2C communication with a button matrix using the `Buttons` and `ComI2C` classes.
 * 
 * This program initializes a button matrix and configures I2C communication to send the state of 
 * the buttons to an I2C master device. The button matrix is continuously monitored, and the state 
 * is sent whenever the master requests data.
 * 
 * @details
 * - `Buttons`: Manages the button matrix.
 * - `ComI2C`: Handles I2C communication.
 * - The I2C address is defined in the `\include\ProjectConfig.hpp` file to avoid conflicts with other devices.
 */

#include <Arduino.h>
#include "ProjectConfig.hpp"
#include "WheelButtons/Buttons.hpp"
#include "WheelButtons/ComI2C.hpp"

// Global instances for the button matrix and I2C communication.

Buttons buttons;
ComI2C i2c(Wire, buttons);

void requestEvent();

/**
 * @brief  Arduino setup function. Runs once at startup.
 * 
 * This function initializes the Serial debug output (if enabled), the button 
 * matrix, and the I2C communication. It ensures that the `Buttons` and `ComI2C` 
 * classes are properly configured.
 */
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

/**
 * @brief  Arduino loop function. Runs continuously after setup.
 * 
 * This function continuously listens for button events by calling the 
 * `Buttons::listener` method.
 */
void loop() {

  // put your main code here, to run repeatedly:
  // the only task is to listen for any buttons

  buttons.listener();
}

/**
 * @brief  Handles I2C data requests from the master.
 * 
 * This function is called whenever the I2C master requests data. It retrieves 
 * the state of all buttons from the `Buttons` class and sends it over I2C 
 * using the `ComI2C` class.
 */
void requestEvent() {

  // get called every time the master requests data

  i2c.event();
}