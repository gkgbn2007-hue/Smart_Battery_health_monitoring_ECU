# Project Documentation — Smart Battery Health Monitoring ECU

## 1. Abstract

The Smart Battery Health Monitoring ECU is an embedded monitoring prototype designed to acquire basic battery-related electrical and temperature measurements. An Arduino Mega reads voltage and current information from an INA219 sensor and temperature information from a DS18B20 sensor. The measurements are presented on an OLED display and sent to a computer through USB serial for recording and analysis.

The prototype demonstrates sensor interfacing, periodic data acquisition, display control and serial communication. It is a monitoring demonstration, not a complete battery management or protection system.

## 2. Problem Statement

Battery operation is influenced by electrical load and temperature. Without measurements, a user may not have a convenient way to observe these parameters during a controlled test. This project provides a low-cost embedded prototype for displaying and recording selected measurements.

## 3. Objectives

- Measure bus voltage and current using an INA219 module.
- Measure temperature using a DS18B20 sensor.
- Display readings on an OLED.
- Send timestamped/periodic readings over serial for logging.
- Provide a foundation for future battery-specific analysis after calibration and validation.

## 4. Existing System

A basic manual monitoring approach may require separate instruments and manual recording. This can make it harder to observe several measurements together over time.

## 5. Proposed System

The proposed prototype combines sensors with a microcontroller. The Arduino periodically reads the sensors, updates the display and prints CSV-style records to a connected computer.

## 6. Hardware Requirements

| Component | Role |
|---|---|
| Arduino Mega 2560 | Main controller |
| INA219 module | Voltage/current/power measurement |
| DS18B20 | Temperature measurement |
| SSD1306 OLED | Local display |
| USB cable | Programming and serial data |
| Breadboard and jumper wires | Prototype assembly |

The list reflects the uploaded starter firmware assumptions. Confirm it against the actual hardware before assembly.

## 7. Software Requirements

- Arduino IDE
- Adafruit INA219 library
- OneWire library
- DallasTemperature library
- Adafruit GFX library
- Adafruit SSD1306 library
- Serial terminal or data-logging software

## 8. Working Principle

1. The INA219 measures bus voltage and current through its measurement circuit.
2. The DS18B20 measures temperature.
3. The Arduino Mega samples the sensors at a periodic interval.
4. The OLED presents the latest readings.
5. The controller sends CSV-style measurement records over USB serial.
6. A computer can store the records for later analysis.

## 9. Applications

- Embedded systems learning and demonstrations.
- Controlled low-voltage battery measurement experiments.
- Sensor interfacing and serial data-logging practice.
- Educational demonstrations of voltage, current and temperature monitoring.

## 10. Advantages

- Combines multiple measurements in one embedded prototype.
- Provides both local display and serial output.
- Uses commonly available development modules.
- Supports later analysis using recorded data.

## 11. Limitations

- No validated State of Charge (SOC) or State of Health (SOH) calculation is included.
- Sensor accuracy depends on module quality, calibration and wiring.
- The prototype does not provide cell balancing or battery cutoff protection.
- It is not an automotive-qualified battery management system.

## 12. Future Enhancements

- Add calibration routines and measurement uncertainty analysis.
- Develop a battery-chemistry-specific SOC method and validate it with reference measurements.
- Add a properly designed protection stage using appropriately rated hardware.
- Add IoT dashboard publishing after reliable local measurements are established.
- Build a test dataset and report repeatability and measurement error.

## 13. Testing and Validation

Follow [the bench testing procedure](testing_procedure.md). Record actual measured values, reference instrument readings, module versions and test conditions. Do not mark a test as passed until it has been performed.

## 14. Conclusion

The project demonstrates an embedded approach to monitoring selected battery parameters using sensor modules and a microcontroller. It provides a base for further work in data logging, calibration and battery-specific analysis. Its current scope is limited to measurement and display.

## 15. References

- Arduino documentation: https://docs.arduino.cc/
- Adafruit INA219 guide: https://learn.adafruit.com/adafruit-ina219-current-sensor-breakout
- Analog Devices DS18B20 product information: https://www.analog.com/en/products/ds18b20.html
- Adafruit SSD1306 library: https://github.com/adafruit/Adafruit_SSD1306
