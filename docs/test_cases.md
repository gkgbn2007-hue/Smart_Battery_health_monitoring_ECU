# Firmware Test Cases — Smart Battery Health Monitoring ECU

> Status: planned verification cases. These are not recorded hardware test results.

| ID | Test | Procedure | Expected observation | Result |
|---|---|---|---|---|
| BAT-01 | Sensor startup | Power the board with the approved, current-limited bench setup | Firmware starts and reports sensor status | Not run |
| BAT-02 | Voltage reading | Compare INA219 reading with a calibrated multimeter using a safe low-voltage source | Readings are reasonably close within sensor and meter tolerances | Not run |
| BAT-03 | Current reading | Use a known, safe test load within the sensor/module ratings | Current reading changes consistently with load | Not run |
| BAT-04 | Temperature reading | Compare DS18B20 reading with a reference thermometer | Stable temperature reading within sensor tolerance | Not run |
| BAT-05 | Sensor disconnected | Disconnect one sensor only while power is off, then restart | Missing-sensor condition is reported; no misleading valid reading | Not run |
| BAT-06 | Display output | Observe OLED during normal startup and sampling | Values/status are legible and update | Not run |

## Test safety
- Do not connect an unknown battery pack or high-current source directly.
- Confirm module voltage/current ratings, polarity, wiring, and fuse protection before powering.
- Use a current-limited, low-voltage bench supply and supervision.
- Do not interpret voltage/current measurements as validated State of Health (SOH) or State of Charge (SOC) without a defined, calibrated algorithm.

## Evidence to add after testing
Record board revision, sensor/module versions, supply voltage, reference instrument, measured values, tolerance, date, and a photograph or serial log. Change a result to **Pass** or **Fail** only after the test is actually performed.
