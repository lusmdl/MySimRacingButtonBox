
# Sim Racing Button Box

Welcome to the Sim Racing Button Controller repository!  

This project is built around an ATmega328P microcontroller, which is configured to manage a button matrix tailored for sim racing setups. The system uses I2C communication, where the Arduino Micro acts as the **master** and the ATmega328P functions as the **slave**. This ensures precise control and synchronization between the components.  

The ATmega328P transmits a 16-bit signal representing the states of up to 16 buttons **only when requested by the Arduino Micro**. This on-demand communication minimizes latency and ensures efficient data transfer. Additionally, the PCB includes support for a joystick connection, expanding its versatility.  

This project complements [MySimRacingCore](https://github.com/lusmdl/MySimRacingCore), which serves as the brain of the entire sim racing system. Together, they deliver a modular and high-performance solution for sim racing enthusiasts.

## Features

- Support for up to 16 buttons in a matrix configuration
- Seamless I2C communication with the Arduino Micro for precise control
- Fast and effective button state management with Keypad Library
- Joystick integration via the PCB's RJ45 jack, reducing wiring complexity

## Getting Started

You can use the pre compiled hex file. Or you use compile it yourself.

### Hardware Requirements

- **ATmega328P Microcontroller**
- 16 Mhz Oscilator
- 12..22 pF Condansator
- 100 µF Condansator for supply stability
- **Button Matrix**: Up to 16 buttons
- **The PCBA from master project**: [MySimRacingCore](https://github.com/lusmdl/MySimRacingCore)

> Example PCB for this project
![PCBA](/doc/hardware/pictures/pcba.png)

### Software Requirements

- [**PlatformIO**](https://platformio.org/install/ide?install=vscode): Used for programming the ATmega328P microcontroller.
- [**Wire.h**](https://www.arduino.cc/en/Reference/Wire): for I2C communication
- [**AVR Lib**](https://github.com/avrdudes/avr-libc.git): standard lib with PlatformIO.
- [**Keypad Library**](https://github.com/Chris--A/Keypad.git): Used for the 4x4 Matrix


### Software Installation and Setup

You can either use the precompiled HEX file or compile the firmware yourself. Follow the steps below for a smooth setup:

1. **Install PlatformIO**  
   - Set up PlatformIO in your preferred development environment (e.g., VSCode or Atom) by following the official [installation guide](https://platformio.org/install).  

2. **Clone the Repository**  

   ```sh
   git clone https://github.com/lusmdl/MySimRacingButtonBox.git
   ```  

3. **Open the Project**  
   - Open the cloned repository in your PlatformIO environment.  

4. **Build and Upload**  
   - Prepare your ATmega328P-based PCB for flashing. It’s recommended to first flash the firmware onto an Arduino Uno and then transfer the chip to your custom environment.  
   - Build and upload the code using PlatformIO:  

   ```sh
   pio run --target upload
   ```  


### Hardware Setup

1. Assemble the PCB according to the provided design.  
2. Ensure all components, such as the button matrix and joystick, are correctly connected.

## Usage

1. **Hardware Connection**  
   - Connect the button matrix to the ATmega328P as per the configuration.  
   - Establish an I2C connection between the ATmega328P and the Arduino Micro.  

2. **Running the Firmware**  
   - Power on your system.  
   - The ATmega328P will only send a 16-bit signal to the Arduino Micro when requested over I2C, ensuring efficient communication.

## Documentation

- **Software**: [doc/software/html/index.html](doc/software/html/index.html)

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
