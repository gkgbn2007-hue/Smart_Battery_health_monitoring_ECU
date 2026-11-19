# Pin Connections — Smart Battery Health Monitoring ECU

> **Important:** These are proposed connections for the starter firmware, not verified details of a completed circuit. Confirm the exact module versions, voltage levels, sensor ratings, and battery protection before wiring.

## Arduino Mega 2560

| Module | Module pin | Arduino Mega pin | Notes |
|---|---|---|---|
| INA219 | SDA | 20 (SDA) | I2C data |
| INA219 | SCL | 21 (SCL) | I2C clock |
| INA219 | GND | GND | Common ground |
| INA219 | VCC | 3.3 V or 5 V as supported by the breakout | Check board documentation |
| DS18B20 | DATA | D7 | Add a 4.7 kΩ pull-up from DATA to the sensor supply if required |
| DS18B20 | VDD | 3.3 V or 5 V per sensor specification | Check sensor version |
| DS18B20 | GND | GND | Common ground |
| OLED SSD1306 | SDA | 20 (SDA) | I2C |
| OLED SSD1306 | SCL | 21 (SCL) | I2C |
| OLED SSD1306 | VCC | Per module specification | Check whether 3.3 V or 5 V is supported |
| OLED SSD1306 | GND | GND | Common ground |

## Before connecting a battery

- Identify the battery chemistry and nominal/maximum voltage.
- Verify the INA219 breakout's voltage and current limits.
- Use an appropriately rated fuse and a protected test setup.
- Never connect a battery directly to Arduino power pins.
- Follow the INA219 breakout manufacturer's shunt and high-side measurement wiring.
- Begin with a current-limited bench supply where possible.

## I2C address assumptions

The firmware expects INA219 at its default address (commonly 0x40) and OLED at 0x3C. Actual addresses can differ. Use an I2C scanner and update the firmware if needed.
