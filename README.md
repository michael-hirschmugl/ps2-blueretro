# PS2 BlueRetro Mod - BlueMoogle

![PS2 BlueMoogle Bluetooth Mod Logo](images/PS2-BlueMoogle-Logo.png)

This project adds Bluetooth connectivity for PlayStation 2 controllers, based on the BlueRetro project. The goal is to integrate this functionality directly into the PlayStation 2 as a hardware mod.

## Project Status

The project is currently in the **Prototype v1** phase, with the initial PCB design sent for manufacturing. This version serves to validate core functionalities, including:

- USB-C connection to the ESP32 (tested and working)
- Bluetooth pairing with controllers (tested successfully with a PS3 controller)
- Power supply circuits
- Global status LED
- Controller Port 1 detect LED
- Current mirror for controller detection (working; not tested with real controller)
- Detection of the PlayStation 2 console's power supply

### Future Development

The next steps, after testing Prototype v1, include:

- Connecting the board to Controller Port 1 on the PlayStation 2 and adding support for an optional external controller.
- Expanding the setup to Controller Port 2.
- Minimizing the hardware for integration within a PlayStation 2 Slim.
- Adjusting the firmware as needed based on test results.

### Hardware Version

This project modifies the [BlueRetro HW2](https://github.com/darthcloud/BlueRetro/wiki#2---building-hardware-hw2) design, adapted for integration as a PlayStation 2 mod with external controller detection capabilities.

## Firmware

Currently, the firmware is based on [BlueRetro](https://github.com/darthcloud/BlueRetro). No firmware is included in this repository at this time, but custom modifications may be made to accommodate the unique hardware setup.

### Flashing Instructions

To flash the firmware, follow these steps:

1. Install the USB UART bridge driver if necessary (available through Windows Update).
2. Press and hold the boot button on the board.
3. Briefly press the EN (Reset) button while still holding the boot button.
4. Continue holding the boot button for a moment longer, then release.

> Note: The boot button must be pressed when the board powers on or resets to enable flashing.

For detailed flashing instructions, refer to [Flashing Firmware on Windows 10](https://github.com/darthcloud/BlueRetro/wiki/Flashing-firmware-Windows-10). This guide provides important memory area configurations.

The latest firmware binary can be downloaded here: [BlueRetro Firmware](https://darthcloud.itch.io/blueretro). For this prototype, the **HW1 Universal** firmware was used.

## Controller Pairing

To pair a PS3 controller, follow the [PS3 Pairing Guide](https://github.com/darthcloud/BlueRetro/wiki/Controller-pairing-guide#2---ps3-pairing-guide). The **Sixaxis Pair Tool** is required to set the Bluetooth master for the controller. Download it here: [Sixaxis Pair Tool](https://sixaxispairtool.en.lo4d.com/windows#:~:text=The%20Sixaxis%20Pair%20Tool%20is,games%20with%20your%20PS3%20controller).

The Bluetooth MAC address of the BlueRetro board can be located in the advanced settings of the web configuration.

### BlueRetro Web Configuration

To access BlueRetro’s web configuration, a BLE-enabled Bluetooth adapter is required. You can access it here: [BlueRetro WebConfig](https://blueretro.io/).

For Brave browser users: Bluetooth web configuration may need to be enabled in the settings under `brave://flags`.

## Next Steps

1. Test and validate Prototype v1 functionality.
2. Adapt the hardware for PlayStation 2 Controller Port 2.
3. Shrink the hardware for PlayStation 2 Slim compatibility.
4. Continue with firmware development and testing.
5. Prepare for Prototype v2.

## Acknowledgments

This project is based on the [BlueRetro project](https://github.com/darthcloud/BlueRetro), which provides the foundation for Bluetooth connectivity with classic gaming consoles.
