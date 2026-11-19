# Firmware Test Checklist — Battery Monitoring ECU

Use this checklist during a controlled bench test. Tick an item only after observing it. Attach serial logs, photos and instrument readings as evidence.

## Build and startup

- [ ] Correct board selected: Arduino Mega 2560 (confirm actual board).
- [ ] Required libraries installed.
- [ ] Firmware compiles without errors.
- [ ] Correct serial port selected and upload completes.
- [ ] Serial Monitor opens at 115200 baud.
- [ ] Startup output is observed and saved.

## Sensor and display checks

- [ ] INA219 is detected at the configured I2C address.
- [ ] Voltage reading is compared with a suitable reference meter.
- [ ] Current reading is checked using a known safe test load and suitable reference.
- [ ] DS18B20 returns a plausible temperature.
- [ ] OLED initializes and updates.
- [ ] Sensor disconnect/error behavior is recorded.

## Data logging

- [ ] Serial output columns are identified.
- [ ] Multiple consecutive records are captured.
- [ ] Units and numeric formatting are checked.
- [ ] Missing/invalid readings are noted.

## Evidence record

| Field | Record |
|---|---|
| Test date | |
| Board and module versions | |
| Supply and load conditions | |
| Reference instrument/model | |
| Measured voltage/current/temp | |
| Firmware version or commit | |
| Evidence file names | |
| Observed issues | |

**Do not claim SOC/SOH accuracy, protection functionality, or successful hardware validation unless those functions are implemented and independently tested.**
