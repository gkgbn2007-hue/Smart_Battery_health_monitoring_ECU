# Embedded Systems & Firmware Portfolio

This portfolio brings together three educational embedded-systems projects. Each repository contains its own firmware, architecture notes, connection assumptions, setup guidance, and planned verification cases.

## Projects

### 1. Smart Battery Health Monitoring ECU
**Repository:** [Smart Battery Health Monitoring ECU](https://github.com/gkgbn2007-hue/Smart_Battery_health_monitoring_ECU)

- **Platform:** Arduino Mega 2560
- **Main components described:** INA219 voltage/current monitor, DS18B20 temperature sensor, OLED display
- **Focus:** Embedded sensor acquisition, monitoring, display output, and firmware structure
- **Firmware:** [battery_health_monitor.ino](../blob/main/firmware/battery_health_monitor.ino)
- **Documentation:** [System architecture](system_architecture.md) · [Circuit assumptions](circuit_diagram.md) · [Test cases](test_cases.md)

### 2. CAN Bus Intrusion Detection System
**Repository:** [CAN Bus Intrusion Detection System](https://github.com/gkgbn2007-hue/Can_bus_intrusion_system-)

- **Platform:** ESP32 with MCP2515 CAN controller; Python serial logging tool
- **Focus:** Passive defensive monitoring, identifier classification, and message-rate observation on an isolated lab setup
- **Firmware:** [esp32_can_receive_monitor.ino](https://github.com/gkgbn2007-hue/Can_bus_intrusion_system-/blob/main/firmware/esp32_can_receive_monitor.ino)
- **Python tool:** [can_serial_logger.py](https://github.com/gkgbn2007-hue/Can_bus_intrusion_system-/blob/main/tools/can_serial_logger.py)
- **Documentation:** [Test cases](https://github.com/gkgbn2007-hue/Can_bus_intrusion_system-/blob/main/docs/test_cases.md)

**Safety boundary:** This is for passive monitoring of an isolated bench/lab network or offline traces only. Do not connect it to a road vehicle or transmit/inject disruptive traffic.

### 3. Driver Drowsiness Alert ECU
**Repository:** [Driver Drowsiness Alert ECU](https://github.com/gkgbn2007-hue/driver-drowsiness-alert-ecu)

- **Platform:** Arduino UNO prototype
- **Main components described:** IR eye-state sensor, buzzer, optional OLED
- **Focus:** Sensor-state sampling, time-based alert logic, and output control
- **Firmware:** [driver_drowsiness_alert.ino](https://github.com/gkgbn2007-hue/driver-drowsiness-alert-ecu/blob/main/firmware/driver_drowsiness_alert.ino)
- **Documentation:** [System architecture](https://github.com/gkgbn2007-hue/driver-drowsiness-alert-ecu/blob/main/docs/system_architecture.md) · [Test cases](https://github.com/gkgbn2007-hue/driver-drowsiness-alert-ecu/blob/main/docs/test_cases.md)

**Limitation:** This is an educational prototype, not a certified automotive safety system and must not be relied on while driving.

## Technologies represented

- Embedded C/C++ and Arduino-style firmware
- Arduino Mega, Arduino UNO, and ESP32 platforms
- Sensor interfacing and serial communication
- INA219, DS18B20, OLED, IR sensor, and MCP2515 modules
- CAN bus receive-side monitoring concepts
- Python tooling and dependency management
- Git, GitHub, and GitHub Actions CI workflows

## Verification status

Automated build workflows are configured in the individual repositories. At the time this portfolio page was prepared, the Arduino Mega and Arduino UNO workflows had successful runs; the ESP32 workflow had been triggered and was still awaiting its final result.

The documented test cases are **planned test procedures**, not claimed physical test results. Hardware validation, measured results, and prototype photographs should be added only after they are genuinely captured. Build success confirms compilation in CI, not correct operation on physical hardware.

## Suggested reviewer path

1. Read the project README.
2. Review the architecture and circuit assumptions.
3. Inspect the firmware source.
4. Review the test cases and CI workflow.
5. Check for future commits containing actual bench-test evidence.

---
*Maintained as a learning and project portfolio. Hardware configurations and component choices should be confirmed against the actual prototype before assembly or use.*
