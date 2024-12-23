/**
 * @file ComI2C.cpp
 * @brief Implementation file for the ComI2C class.
 */

#include "ComI2C.hpp"

/**
 * @brief  Constructs a `ComI2C` object to manage I2C communication with a Buttons instance.
 * 
 * This constructor initializes the I2C communication handler by associating it with a 
 * `TwoWire` instance for I2C operations and a `Buttons` instance for handling button events.
 * 
 * @param  wire Reference to the `TwoWire` instance used for I2C communication.
 * @param  buttons Reference to the `Buttons` instance to interact with the button matrix.
 */
ComI2C::ComI2C(TwoWire &wire, Buttons &buttons) :
    wire_(&wire),
    buttons_(&buttons)
{}

/**
 * @brief Destructor for ComI2C.
 */
ComI2C::~ComI2C() {
    
    // No need to delete wire_ and buttons_ as they are not dynamically allocated
    //delete wire_;
    //delete buttons_;
}

/**
 * @brief Initializes I2C communication.
 * @param addr I2C address.
 * @param requestEvent Function to call on I2C request. The function has to be static!!!
 */
void ComI2C::begin(uint8_t addr, void (*function)()) {

    wire_->begin(addr);
    wire_->onRequest(function);
}

/**
 * @brief Handles I2C events.
 */
void ComI2C::event() {

    // Create a 16-bit value to hold the state of all 16 buttons
    uint16_t payload = 0;

    for (uint8_t i = 0; i < 16; i++) {

        if (buttons_->getData(i).pushed) {
            
            payload |= (1 << i); // Set the corresponding bit if the button is pushed
        }
    }

    #ifdef LUSMDL_DEBUGMODE
        Serial.print("16 Bit I2C communication: " + String(payload, HEX) + " (HEX)\n");
    #endif

    // Send the 16-bit payload over I2C
    wire_->write(reinterpret_cast<uint8_t*>(&payload), sizeof(payload));
}