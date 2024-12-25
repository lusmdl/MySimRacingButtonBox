
# Sim Racing Button Box

Welcome to the Sim Racing Button Controller repository! This project focuses on programming an ATmega328P microcontroller to manage a button matrix for sim racing setups. The controller communicates with an Arduino Micro via I2C, providing the states of 16 buttons in a 16-bit signal for an enhanced racing experience.

## Features

- 16 buttons
- I2C communication with Arduino Micro
- Efficient button state management

## Getting Started

You can use the pre compiled hex file. Or you use compile it yourself.

### Hardware Requirements

- **ATmega328P Microcontroller**
- 16 Mhz Oscilator
- 12..22 pF Condansator
- 100 µF Condansator for supply stability
- **Button Matrix**: Up to 16 buttons

> Example PCB for the project
![PCBA](https://github.com/lusmdl/MySimRacingButtonBox/blob/main/doc/hardware/pictures/pcba.png)

### Software Requirements

- [**PlatformIO**](https://platformio.org/install/ide?install=vscode): Used for programming the ATmega328P microcontroller.
- [**Wire.h**](https://www.arduino.cc/en/Reference/Wire): for I2C communication
- [**AVR Lib**](https://github.com/avrdudes/avr-libc.git): standard lib with PlatformIO.
- [**Keypad Library**](https://github.com/Chris--A/Keypad.git): Used for the 4x4 Matrix

## Installation and Setup

1. **Install PlatformIO**:
   - Follow the [installation guide](https://platformio.org/install) to set up PlatformIO in your preferred environment (VSCode, Atom, etc.).

2. **Clone the Repository**:

   ```sh
   git clone https://github.com/lusmdl/MySimRacingButtonBox.git
   ```

3. **Open the Project**:
   - Open the cloned repository folder in your PlatformIO environment.

4. **Build and Upload**:
   - Connect your ATmega328P-based hardware.
   - Build and upload the code using PlatformIO:

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

## Documentation
The detailed documentation for this project can be found under [doc/software/html/index.html](doc/software/html/index.html)

## Contributing

We welcome contributions from the community!

First, read the [general contributing conventions for projects from me](CONTRIBUTING.md).

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -am 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Create a new Pull Request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
