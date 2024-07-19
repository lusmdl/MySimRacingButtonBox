
# My Sim Racing Wheele Buttons

This project involves a PCB featuring an ATmega328P microcontroller with various connection possibilities for button matrices. It serves as a subproject to a larger project that manages the USB communication of a sim racing controller using an Arduino Micro. This ATmega328P project communicates over I2C with the Arduino Micro and delivers the states of 16 buttons in a 16-bit signal.

## Project Overview

### Hardware
- **Microcontroller**: ATmega328P
- **Button Matrix**: up to 16 buttons

### Software
- **Development Platform**: PlatformIO
- **Libraries**:
  - **Wire.h**: for I2C communication
- [**Platform IO**](https://platformio.org/install/ide?install=vscode): Used for programming the ATmega32u4 microcontroller.
- [**AVR Lib**](https://github.com/avrdudes/avr-libc.git): standard lib with platformIO.
- [**Keypad Library**](https://github.com/Chris--A/Keypad.git): Used for the 4x4 Matrix

### Functionality
The ATmega328P microcontroller reads the state of the button matrix and communicates the button states to an Arduino Micro via I2C. The state of the 16 buttons is packed into a 16-bit payload and sent over I2C when requested by the Arduino Micro.

## Code Structure

### Main Code (`main.ino`)
- Initializes the `Buttons` and `ComI2C` objects.
- Sets up serial communication (if in debug mode).
- Defines the `requestEvent` function to handle I2C requests.
- Contains the `setup()` and `loop()` functions for the Arduino environment.

### Project Configurations (`ProjectConfig.hpp`)
- Defines configuration macros, including button matrix definitions and I2C address.
- Contains optional debug mode setup.

### I2C Communication (`ComI2C.hpp` and `ComI2C.cpp`)
- `ComI2C` class handles I2C communication.
- Manages sending the state of the button matrix over I2C.

### Button Management (`Buttons.hpp` and `Buttons.cpp`)
- `Buttons` class manages the button matrix.
- Polls button states and updates internal data structures.

### Button Data Structure (`Button.h`)
- Defines the `pod_button` struct to store button states.

## Requirements


## Installation and Setup

1. **Install PlatformIO**:
   - Follow the [installation guide](https://platformio.org/install) to set up PlatformIO in your preferred environment (VSCode, Atom, etc.).

2. **Clone the Repository**:
   ```sh
   git clone https://github.com/lusmdl/MySimRacingWheeleButtons.git
   ```

3. **Open the Project**:
   - Open the cloned repository folder in your PlatformIO environment.

4. **Build and Upload**:
   - Connect your ATmega328P-based hardware.
   - Build and upload the code using PlatformIO:
     ```sh
     pio run --target upload
     ```

### Arduino Micro Setup
1. **I2C Communication**:
   - Ensure the Arduino Micro is set up to receive I2C data from the ATmega328P.
   - The Arduino Micro will request the 16-bit button state data from the ATmega328P.

## Usage

1. **Connecting the Hardware**:
   - Connect the button matrix to the ATmega328P as per your configuration.
   - Connect the ATmega328P to the Arduino Micro via I2C.

2. **Running the Code**:
   - Power up your setup.
   - The ATmega328P will continuously poll the button states and update the Arduino Micro via I2C.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contributing

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -am 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Create a new Pull Request.

## Contact

For any questions or suggestions, please feel free to [open an issue](https://github.com/lusmdl/MySimRacingWheeleButtons/issues).
