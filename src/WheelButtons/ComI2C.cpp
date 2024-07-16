#include "ComI2C.hpp"

ComI2C::ComI2C(TwoWire &wire, Buttons &buttons) :
    wire_(&wire),
    buttons_(&buttons)
{}

ComI2C::~ComI2C() {
    
    delete wire_;
    delete buttons_;
}

void ComI2C::begin(uint8_t addr, void (*function)()) {

    wire_->begin(addr);
    wire_->onRequest(function);
}

void ComI2C::event() {
    // Create a 16-bit value to hold the state of all 16 buttons
    uint16_t payload = 0;

    for (uint8_t i = 0; i < 16; i++) {
        if (buttons_->getData(i).pushed) {
            payload |= (1 << i); // Set the corresponding bit if the button is pushed
        }
    }

    // Send the 16-bit payload over I2C
    wire_->write(reinterpret_cast<uint8_t*>(&payload), sizeof(payload));
}