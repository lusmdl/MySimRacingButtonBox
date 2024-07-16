#ifndef COM_I2C_HPP
#define COM_I2C_HPP

#include <Wire.h>
#include "Buttons.hpp"

class ComI2C
{

    public:
        ComI2C(TwoWire &wire, Buttons &buttons);
        ~ComI2C();
        void begin(uint8_t addr, void (*requestEvent)());
        void event();
    
    private:
        TwoWire *wire_;
        Buttons *buttons_;

};


#endif