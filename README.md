# Smart Battery Health Monitoring ECU

An embedded prototype intended to monitor battery voltage, current, and temperature, show readings on an OLED, and optionally publish data to Blynk or ThingSpeak.

## Project objectives
- Use an Arduino Mega as the main controller.
- Measure voltage and current with an INA219 module.
- Measure temperature with a suitable temperature sensor (exact model to be confirmed).
- Display readings locally on an OLED.
- Optionally publish selected readings to an IoT dashboard.
- Develop an SOC estimate only after selecting and validating a suitable battery-specific method.

## Hardware and tools
Arduino Mega, INA219 module, temperature sensor, OLED display, connecting wires, suitable protected power source, Arduino IDE, and optionally Blynk or ThingSpeak.

## Working principle
Sensors acquire battery readings. The Arduino Mega samples and converts the data using the correct calibration, updates the OLED, and optionally sends selected values to an IoT dashboard. Configured limits may be used for warnings.

SOC is an estimate and depends on battery chemistry, capacity, calibration, and the chosen method. SOH or predictive degradation claims require a defined method and repeatable validation.

## Repository
- docs/system_design.md — functional architecture and details to verify.
- docs/testing_and_validation.md — test plan and evidence checklist.

## Validation status
Original firmware, exact wiring, photographs, and measured test results were not supplied for this documentation update. No accuracy, lifecycle improvement, or predictive-performance figure is claimed here. Add actual measurements before publishing performance claims.

## Safety
Verify battery chemistry, voltage/current limits, sensor ratings, polarity, and wiring. Use correctly rated, protected test equipment. This educational prototype is not an automotive-qualified battery management system.

## Author
Gurubaran G K — B.E. Electronics and Communication Engineering.
