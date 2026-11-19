/*
 * Smart Battery Health Monitoring ECU - starter firmware
 * Target: Arduino Mega 2560
 *
 * Assumed parts (verify against your actual build):
 * - INA219 current/voltage sensor at I2C address 0x40
 * - DS18B20 temperature sensor on pin 7
 * - I2C SSD1306 128x64 OLED at address 0x3C
 *
 * Libraries: Adafruit INA219, OneWire, DallasTemperature,
 * Adafruit GFX, Adafruit SSD1306.
 *
 * Educational bench prototype only. Check battery chemistry, sensor
 * ratings, polarity and protection before connecting a battery.
 * No SOC/SOH estimate is made by this starter firmware.
 */

#include <Wire.h>
#include <Adafruit_INA219.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define TEMP_PIN 7
#define OLED_WIDTH 128
#define OLED_HEIGHT 64
#define OLED_RESET -1
#define OLED_ADDRESS 0x3C

Adafruit_INA219 ina219;
OneWire oneWire(TEMP_PIN);
DallasTemperature tempSensor(&oneWire);
Adafruit_SSD1306 display(OLED_WIDTH, OLED_HEIGHT, &Wire, OLED_RESET);

const unsigned long SAMPLE_INTERVAL_MS = 1000;
unsigned long lastSampleMs = 0;

void showStatus(float busVoltage, float current_mA, float temperatureC,
                bool tempValid) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("Battery Monitor ECU"));

  display.setCursor(0, 16);
  display.print(F("Voltage: "));
  display.print(busVoltage, 2);
  display.println(F(" V"));

  display.setCursor(0, 29);
  display.print(F("Current: "));
  display.print(current_mA, 1);
  display.println(F(" mA"));

  display.setCursor(0, 42);
  display.print(F("Temp: "));
  if (tempValid) {
    display.print(temperatureC, 1);
    display.println(F(" C"));
  } else {
    display.println(F("Sensor error"));
  }

  display.display();
}

void setup() {
  Serial.begin(115200);
  Wire.begin(); // Mega 2560: SDA=20, SCL=21

  if (!ina219.begin()) {
    Serial.println(F("ERROR: INA219 not detected. Check I2C wiring."));
    while (true) delay(100);
  }

  tempSensor.begin();
  // Start DS18B20 conversion without blocking the main loop.
  tempSensor.setWaitForConversion(false);
  tempSensor.requestTemperatures();

  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
    Serial.println(F("ERROR: OLED not detected. Check address/wiring."));
    while (true) delay(100);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println(F("Battery ECU starting"));
  display.display();

  Serial.println(F("time_ms,voltage_V,current_mA,power_mW,temp_C"));
}

void loop() {
  const unsigned long now = millis();
  if (now - lastSampleMs < SAMPLE_INTERVAL_MS) return;
  lastSampleMs = now;

  const float busVoltage = ina219.getBusVoltage_V();
  const float current_mA = ina219.getCurrent_mA();
  const float power_mW = ina219.getPower_mW();

  // Read the conversion started during the previous cycle, then start
  // the next conversion. This avoids waiting for DS18B20 conversion time.
  const float temperatureC = tempSensor.getTempCByIndex(0);
  const bool tempValid =
      (temperatureC != DEVICE_DISCONNECTED_C && temperatureC > -55.0f &&
       temperatureC < 125.0f);
  tempSensor.requestTemperatures();

  showStatus(busVoltage, current_mA, temperatureC, tempValid);

  Serial.print(now);
  Serial.print(',');
  Serial.print(busVoltage, 3);
  Serial.print(',');
  Serial.print(current_mA, 2);
  Serial.print(',');
  Serial.print(power_mW, 2);
  Serial.print(',');
  if (tempValid) Serial.println(temperatureC, 2);
  else Serial.println(F("NA"));
}
