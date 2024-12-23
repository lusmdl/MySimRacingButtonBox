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
 * @brief  Destructor for the `ComI2C` class.
 * 
 * Cleans up resources used by the `ComI2C` instance. Since the `wire_` and `buttons_` 
 * members are not dynamically allocated, no explicit deletion is necessary.
 */
ComI2C::~ComI2C() {
    
    // No need to delete wire_ and buttons_ as they are not dynamically allocated
    //delete wire_;
    //delete buttons_;
}

/**
 * @brief  Initializes the I2C communication for the `ComI2C` instance.
 * 
 * This method sets up the I2C address and assigns a callback function to be 
 * executed when an I2C request is received.
 * 
 * @param  addr The I2C address to be used by the device.
 * @param  function Pointer to the callback function to handle I2C requests.
 */
void ComI2C::begin(uint8_t addr, void (*function)()) {

    wire_->begin(addr);
    wire_->onRequest(function);
}

/**
 * @brief  Handles I2C communication events by sending the state of all buttons.
 * 
 * This method creates a 16-bit payload representing the state of all 16 buttons 
 * in the button matrix. Each bit corresponds to a button, and the bit is set if 
 * the button is pressed. The payload is sent over I2C.
 * 
 * @details
 * - Each button's state is checked using `Buttons::getData`.
 * - A bitwise operation sets the corresponding bit in the 16-bit payload for each pressed button.
 * - Debug output (if enabled) shows the payload in hexadecimal format.
 * - The payload is sent over I2C using `wire_->write`.
 * 
 * @note Ensure that `LUSMDL_DEBUGMODE` is defined to enable debug logs.
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