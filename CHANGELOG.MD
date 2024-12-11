# Changelog

## [Unreleased]

### Added
- Prototype PCB (v1) tested and validated:
  - USB-C connection to ESP32
  - Bluetooth connection to controllers (successfully paired with PS3 controller)
  - Power supplies, status LEDs, and controller detection

- Prototype v2:
  - Integration with PlayStation 2 Controller Ports
  - Buzzer added for user feedback
  - Final hardware functionalities implemented
  - Detection of console power supply
  - Reading and control of the boot (system reset) signal, including a buffer for optional signal reading by the firmware
  - LED control and buzzer functionality successfully tested

### Planned
- Correctly dimension the controller port detection circuitry
- Verify that controller signals are correctly forwarded to the console
- Complete PCB design for Prototype v2
- Test Prototype v2 functionality with external wiring
- Adapt BlueRetro firmware for v2 hardware setup, including buzzer functionality
- Prepare Prototype v3 for direct integration into PlayStation 2 Slim
- Produce the first production sample using a flex PCB for direct console integration
