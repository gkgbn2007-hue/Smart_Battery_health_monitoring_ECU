# System Design — Smart Battery Health Monitoring ECU

## Intended architecture
Battery measurement points → INA219 and temperature sensor → Arduino Mega → OLED display. The controller may also send selected readings to Blynk or ThingSpeak if the final hardware includes a working network interface.

## Functional blocks
1. Measurement: INA219 measures voltage and current within its electrical limits. A separate temperature sensor measures the selected battery temperature point.
2. Controller: Arduino Mega samples sensors, checks validity, converts readings to engineering units, and updates outputs.
3. Display: OLED presents current readings. SOC should be displayed only after its estimation method is implemented and validated.
4. IoT: Selected readings are sent to a dashboard only if the final hardware has a working network path and valid configuration.

## Details to confirm from the actual build
- Battery chemistry, nominal voltage, capacity, and safe limits.
- INA219 breakout variant and shunt rating.
- Exact temperature sensor model and mounting location.
- OLED controller, resolution, and interface.
- Verified Arduino Mega pin map and circuit diagram.
- Dashboard platform and field/virtual-pin mapping.
- SOC/SOH equations and calibration procedure.

Do not infer pin numbers from this document. Verify them against the assembled circuit before powering it.
