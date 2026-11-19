# Software and Library Requirements

## Hardware target

- Arduino Mega 2560
- INA219 current/voltage sensor breakout
- DS18B20 temperature sensor
- SSD1306 I2C OLED (128 × 64 assumed)

## Arduino IDE

Install the Arduino IDE and select **Arduino Mega or Mega 2560** with the correct processor option for your board.

## Required libraries

Install these through Arduino IDE → Library Manager:

1. **Adafruit INA219** — reads bus voltage, current and power.
2. **OneWire** — communication with the DS18B20.
3. **DallasTemperature** — temperature sensor interface.
4. **Adafruit GFX Library** — graphics support for the OLED.
5. **Adafruit SSD1306** — SSD1306 display driver.

Install any dependency requested by the Library Manager.

## Compile

1. Open `firmware/battery_health_monitor.ino`.
2. Select the correct Mega board and COM port.
3. Install all listed libraries.
4. Compile before connecting the battery.
5. Open Serial Monitor at **115200 baud**.

## Serial output

The firmware prints CSV columns:

`time_ms,voltage_V,current_mA,power_mW,temp_C`

A temperature reading of `NA` indicates that the sensor reading was invalid or unavailable.

## Scope

This starter firmware reports sensor measurements. It does not calculate a validated State of Charge (SOC), State of Health (SOH), remaining capacity, or battery-life prediction. Those features require a defined battery model, calibration and test data.
