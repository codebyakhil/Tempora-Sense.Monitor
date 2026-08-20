/*
  ===========================================================
  Arduino LM35 Temperature Monitor with LCD Display
  ===========================================================
  Description:
    Reads ambient temperature using the LM35 analog temperature
    sensor and displays the reading in real time on a 16x2 LCD.

  Hardware:
    - Arduino Uno (or compatible)
    - LM35 Temperature Sensor
    - 16x2 LCD Display (HD44780 compatible)
    - 10k Potentiometer (LCD contrast)
    - Breadboard + Jumper Wires

  Wiring:
    LM35:
      Pin 1 (VCC) -> Arduino 5V
      Pin 2 (OUT) -> Arduino A0
      Pin 3 (GND) -> Arduino GND

    LCD (16x2, 4-bit mode):
      RS -> D12
      E  -> D11
      D4 -> D5
      D5 -> D4
      D6 -> D3
      D7 -> D2
      VSS -> GND
      VDD -> 5V
      V0  -> Potentiometer wiper (contrast)
      RW  -> GND
      A (backlight +) -> 5V (through 220 ohm resistor)
      K (backlight -) -> GND

  Author: [Your Name]
  ===========================================================
*/

#include <LiquidCrystal.h>

// Initialize the LCD library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int sensorPin = A0;      // LM35 output connected to A0
const float referenceVoltage = 5.0;  // Arduino operating voltage
const int adcResolution = 1024;      // 10-bit ADC (0-1023)

// Number of samples to average for a more stable reading
const int numSamples = 10;

void setup() {
  lcd.begin(16, 2);              // Initialize 16x2 LCD
  Serial.begin(9600);            // For debugging via Serial Monitor

  lcd.setCursor(0, 0);
  lcd.print("Temp Monitor");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(1500);
  lcd.clear();
}

void loop() {
  float tempC = readTemperature();
  float tempF = (tempC * 9.0 / 5.0) + 32.0;

  // Display on LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(tempC, 1);
  lcd.print((char)223); // degree symbol
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("      ");
  lcd.print(tempF, 1);
  lcd.print((char)223);
  lcd.print("F");

  // Debug output on Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(tempC, 2);
  Serial.print(" C  |  ");
  Serial.print(tempF, 2);
  Serial.println(" F");

  delay(1000);
}

// Reads the LM35 sensor and returns temperature in Celsius
float readTemperature() {
  long total = 0;

  // Take multiple samples and average them to reduce noise
  for (int i = 0; i < numSamples; i++) {
    total += analogRead(sensorPin);
    delay(10);
  }

  float avgReading = total / (float)numSamples;

  // Convert ADC value to voltage
  float voltage = avgReading * (referenceVoltage / adcResolution);

  // LM35 outputs 10mV per degree Celsius
  float temperatureC = voltage * 100.0;

  return temperatureC;
}
