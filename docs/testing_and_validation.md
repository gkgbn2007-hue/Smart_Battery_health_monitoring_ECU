# Testing and Validation — Smart Battery Health Monitoring ECU

This is a test plan, not a report of completed tests. Enter only measurements obtained from the actual hardware.

| Test | Procedure | Record |
|---|---|---|
| Voltage | Compare INA219 reading with a suitable reference meter at safe test points. | Reference, measured value, error |
| Current | Compare against a suitable reference under a current-limited load. | Reference, measured value, error |
| Temperature | Compare with a reference thermometer. | Reference, measured value, error |
| OLED | Check that configured readings update and remain legible. | Pass/fail, observations |
| IoT | Confirm the dashboard receives correctly mapped values. | Timestamp and values |
| Warning | Test configured limits using safe simulated values or controlled conditions. | Threshold and response |
| Sensor fault | Check error handling under a safe bench setup. | Fault indication and recovery |

## Evidence checklist
- [ ] Actual circuit photograph
- [ ] Verified circuit diagram and pin map
- [ ] Firmware source and library versions
- [ ] Reference instrument details
- [ ] Raw readings and error calculations
- [ ] Dashboard screenshot, if implemented
- [ ] Known limitations

Define acceptance limits before testing. Do not invent results.
