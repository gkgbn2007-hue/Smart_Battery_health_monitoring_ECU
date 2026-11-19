# Bench Testing Procedure

> Perform tests on a low-voltage, current-limited bench setup first. Do not use an unknown or damaged battery. The starter firmware is not a certified battery-management or protection system.

## 1. Visual inspection

- Check module labels and voltage ratings.
- Check for shorts, loose wires and reversed polarity.
- Confirm a common ground where required.
- Confirm that the INA219 shunt path follows the breakout documentation.

## 2. Sensor detection

- Upload the firmware with the battery disconnected.
- Open Serial Monitor at 115200 baud.
- Confirm the INA219 is detected.
- Confirm the OLED displays the monitoring screen.
- Confirm the temperature sensor returns a plausible room-temperature reading.

## 3. Measurement checks

- Compare INA219 voltage with a suitable calibrated multimeter.
- Compare temperature with a trusted thermometer under stable conditions.
- Use a known, safe low-voltage test source and a suitable load within every component rating.
- Record measured and reference values, including instrument accuracy.

## 4. Fault checks

- Disconnect the temperature sensor and confirm the serial output reports `NA`.
- Disconnect the OLED and confirm the firmware reports the display issue (the current sketch halts if OLED initialization fails).
- Check I2C wiring and addresses if a sensor is not detected.

## 5. Test record

| Test | Expected observation | Actual result |
|---|---|---|
| INA219 startup | Sensor detected | To be recorded |
| OLED startup | Display initializes | To be recorded |
| Temperature | Plausible reading | To be recorded |
| Voltage comparison | Within instrument/module accuracy | To be recorded |
| Current comparison | Within instrument/module accuracy | To be recorded |
| Sensor disconnected | Error/NA is reported where implemented | To be recorded |

Do not mark tests as passed until they have actually been performed. Attach photographs, raw serial logs and instrument details when available.
