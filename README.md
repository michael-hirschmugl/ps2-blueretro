# PS2 BlueRetro Mod

This project adds Bluetooth connectivity for PlayStation 2 controllers, based on the BlueRetro project. The goal is to integrate this functionality directly into the PlayStation 2 as a hardware mod.

## Project Status

Currently, the project is in the **Prototype v1** phase, with the first version of the PCB design sent for manufacturing. The following key functionalities will be tested with this prototype:

- USB-C connection to the ESP32
- Bluetooth connection with controllers
- All power supplies
- Global status LED
- Controller Port 1 detect LED
- Current mirror for controller detection
- Detection of the PlayStation 2 console's power supply

Additional testing will also include finalizing the pin assignments. This version (Prototype v1) serves to validate these basic functionalities.

### Future Development

After successfully testing this prototype, the next steps will include:

- Connecting the board to Controller Port 1 of the PlayStation 2 and an optional external controller.
- Duplicating the setup for Controller Port 2.
- Shrinking the hardware to fit inside a PlayStation 2 Slim.
- Potential firmware adjustments based on the test results.

### Hardware Version

This project aims to implement a modified version of the **BlueRetro HW2** hardware design. The main adaptation is to integrate the hardware as a mod into a console and to detect when an external controller is connected.

## Firmware

Currently, the firmware is based on the [BlueRetro](https://github.com/darthcloud/BlueRetro) project, but no firmware is included in this repository yet. In the future, the firmware might need to be adapted to match the custom hardware design.

## Next Steps

1. Test and validate Prototype v1 functionality.
2. Adapt the hardware for PlayStation 2 Controller Port 2.
3. Shrink the hardware for PlayStation 2 Slim compatibility.
4. Continue with firmware development and testing.
5. Prepare for Prototype v2.

## Acknowledgments

This project is based on the work of the [BlueRetro project](https://github.com/darthcloud/BlueRetro), which provides the foundation for Bluetooth connectivity with classic gaming consoles.
