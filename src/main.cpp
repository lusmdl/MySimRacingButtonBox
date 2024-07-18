#include <Arduino.h>
#include "WheelButtons/Buttons.hpp"
#include "WheelButtons/ComI2C.hpp"


Buttons buttons;
ComI2C i2c(Wire, buttons);

void requestEvent();

void setup() {
  // put your setup code here, to run once:

  #ifdef LSMDL_DEBUGMODE
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

  i2c.event();
}