/**
 * @file ComI2C.hpp
 * @brief Header file for the ComI2C class.
 */

#ifndef COM_I2C_HPP
#define COM_I2C_HPP

#include <Wire.h>
#include "Buttons.hpp"


/// @brief Handles I2C communication for the button matrix.
class ComI2C {

    public:

        ComI2C(TwoWire &wire, Buttons &buttons);
        ~ComI2C();
        void begin(uint8_t addr, void (*requestEvent)());
        void event();
    
    private:

        TwoWire *wire_; // Pointer to the TwoWire object.
        Buttons *buttons_; // Pointer to the Buttons object.
};

#endif 