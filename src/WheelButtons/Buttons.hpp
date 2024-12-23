/**
 * @file Buttons.hpp
 * @brief Definition of the Buttons class.
 */

#ifndef BUTTONS_HPP
#define BUTTONS_HPP

#include <Keypad.h>
#include "ProjectConfig.hpp"
#include "Button.h"


/// @brief Manages the button matrix.
class Buttons {

    public:
    
        Buttons();
        ~Buttons();
        void begin();
        void listener();
        pod_button getData(uint8_t button);

    private:

        pod_button data_[BTN_NUMBER]; // Array to store button data
        uint8_t rowpins_[BTN_MATRIX_R]; // Array to store row pins.
        uint8_t columnspins_[BTN_MATRIX_L]; // Array to store column pins.
        char keyarray_[BTN_MATRIX_R][BTN_MATRIX_L]; // Array to store key mappings.
        Keypad keys_; // Keypad object.
        char lasteventkey_; // store the Last event key -> otherwise we get in trouble

        int getmap(char key);
        char getmap(int key);
};


#endif // BUTTONS_HPP