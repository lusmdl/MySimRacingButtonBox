/**
 * @file Buttons.cpp
 * @brief Implementation of the Buttons class.
 */

#include "Buttons.hpp"

/**
 * @brief  Initializes the Buttons class.
 * 
 * The constructor sets up the button matrix with specified row and column pins, 
 * and initializes the keymap for detecting button presses. The key names are 
 * derived using the `getmap` method to ensure correctness.
 * 
 * @details
 * - `rowpins_`: Array of GPIO pins corresponding to the button matrix rows.
 * - `columnspins_`: Array of GPIO pins corresponding to the button matrix columns.
 * - `keyarray_`: A 2D array representing the button layout. Each key is mapped using `getmap`.
 * - `keys_`: Handles key events using the mapped key array, row pins, and column pins.
 * - `lasteventkey_`: Tracks the last key event (initialized to '\0').
 */
Buttons::Buttons() :
    rowpins_{BTN_MATRIX_R1, BTN_MATRIX_R2, BTN_MATRIX_R3, BTN_MATRIX_R4},
    columnspins_{BTN_MATRIX_L1, BTN_MATRIX_L2, BTN_MATRIX_L3, BTN_MATRIX_L4},
    keyarray_{ // The getmap method ensures the key names are correct
        {getmap(0),     getmap(1),  getmap(2),      getmap(3)},
        {getmap(4),     getmap(5),  getmap(6),      getmap(7)},
        {getmap(8),     getmap(9),  getmap(10),     getmap(11)},
        {getmap(12),    getmap(13), getmap(14),     getmap(15)}
    },
    keys_(makeKeymap(keyarray_), rowpins_, columnspins_, BTN_MATRIX_R, BTN_MATRIX_L),
    lasteventkey_('\0')
{}

/**
 * @brief  Destructor for the Buttons class.
 * 
 * Cleans up resources used by the Buttons class. Since no dynamic memory 
 * allocation is performed, no specific cleanup operations are required.
 */
Buttons::~Buttons() {

    // No dynamic memory allocation required
}

/**
 * @brief  Initializes the Buttons instance for operation.
 * 
 * This method configures the debounce and hold times for the button matrix.
 * It prepares the `keys_` object to handle button presses with minimal delay.
 * 
 * @details
 * - `setDebounceTime`: Sets the debounce time to 1 ms to filter out spurious presses.
 * - `setHoldTime`: Sets the hold time to 1 ms to detect long presses quickly.
 */
void Buttons::begin() {

    keys_.setDebounceTime(1);
    keys_.setHoldTime(1);
}

/**
 * @brief  Polls and processes key press events for the button matrix.
 * 
 * This method continuously checks the state of keys, processes events such as 
 * presses and releases, and updates the corresponding data. Debug information 
 * is logged if debug mode is enabled.
 * 
 * @details
 * - `getKey`: Retrieves the currently pressed key, if any.
 * - `keyStateChanged`: Checks if the state of any key has changed.
 * - `getState`: Determines the current state of the key (e.g., PRESSED or RELEASED).
 * - Debug output includes the key events and their data before and after updates.
 * 
 * @note Debug mode (`LUSMDL_DEBUGMODE`) must be enabled to see the debug logs.
 */
void Buttons::listener() {

    // Poll and process key presses
    
    char eventKey = keys_.getKey(); // Necessary to get the data for the other methods
    
    if (eventKey) {

        #ifdef LUSMDL_DEBUGMODE
        Serial.print("Key Pressed Event at key " + String(eventKey) + "\n");
        #endif
        lasteventkey_ = eventKey;
    }

    #ifdef LUSMDL_DEBUGMODE
    if (keys_.keyStateChanged()) {

        Serial.print("Key state change at key " + String(lasteventkey_) + "\n");
    }
    #endif


    switch (keys_.getState()) { // Only one key can be pressed at each cycle!!

        case PRESSED:

            // Handle pressed event
            
            #ifdef LUSMDL_DEBUGMODE
            Serial.print("key state PRESSED at key " + String(lasteventkey_) + " old value was " + String(data_[getmap(lasteventkey_)].pushed));
            #endif

            data_[getmap(lasteventkey_)].pushed++; 
            
            #ifdef LUSMDL_DEBUGMODE
            Serial.print(" and the new value is " + String(data_[getmap(lasteventkey_)].pushed) + "\n");
            #endif

            break;
            
        case RELEASED:

            // Handle released event

            #ifdef LUSMDL_DEBUGMODE
            Serial.print("key state RELEASED at key " + String(lasteventkey_) + " old value was " + String(data_[getmap(lasteventkey_)].pushed));
            #endif

            data_[getmap(lasteventkey_)].pushed = 0; 

            #ifdef LUSMDL_DEBUGMODE
            Serial.print(" and the new value is " + String(data_[getmap(lasteventkey_)].pushed) + "\n");
            #endif

            break;
    }
}

/**
 * @brief  Retrieves the data associated with a specific button.
 * 
 * This method returns the `pod_button` data for the button identified by the 
 * specified index in the button matrix.
 * 
 * @param  button The index of the button in the matrix (0-based).
 * @return The `pod_button` data structure containing the button's state and related information.
 */
pod_button Buttons::getData(uint8_t button) {

    return data_[button];
}

/**
 * @brief  Maps a character key to its corresponding index in the button matrix.
 * 
 * This method converts a key character (e.g., 'A', 'B', etc.) to a 0-based index 
 * used in the button matrix. If the key is not defined, it returns `255` to 
 * indicate an invalid key.
 * 
 * @param  key The character key to be mapped (e.g., 'A', 'B', ..., 'P').
 * @return The corresponding index (0-15) for valid keys, or `255` for invalid keys.
 */
int Buttons::getmap(char key) {

    switch (key) {
        case 'A': return 0;
        case 'B': return 1;
        case 'C': return 2;
        case 'D': return 3;
        case 'E': return 4;
        case 'F': return 5;
        case 'G': return 6;
        case 'H': return 7;
        case 'I': return 8;
        case 'J': return 9;
        case 'K': return 10;
        case 'L': return 11;
        case 'M': return 12;
        case 'N': return 13;
        case 'O': return 14;
        case 'P': return 15;
        default: return 255; // Return an invalid value for undefined keys
    }
}

/**
 * @brief  Maps an index to its corresponding character key in the button matrix.
 * 
 * This method converts a 0-based index (e.g., 0, 1, ..., 15) into its 
 * corresponding character key (e.g., 'A', 'B', ..., 'P'). If the index is 
 * invalid, it returns a null character (`'\0'`).
 * 
 * @param  key The index to be mapped (0-15).
 * @return The corresponding character key for valid indices, or `'\0'` for invalid indices.
 */
char Buttons::getmap(int key) {

    switch (key) {
        case 0: return 'A';
        case 1: return 'B';
        case 2: return 'C';
        case 3: return 'D';
        case 4: return 'E';
        case 5: return 'F';
        case 6: return 'G';
        case 7: return 'H';
        case 8: return 'I';
        case 9: return 'J';
        case 10: return 'K';
        case 11: return 'L';
        case 12: return 'M';
        case 13: return 'N';
        case 14: return 'O';
        case 15: return 'P';
        default: return '\0'; // Return a null character for invalid indices
    }
}
