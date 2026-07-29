/*
  Task 1: Basic LED Blink
  Board: ESP32 / ESP8266
  Pin: GPIO 2 (Onboard LED on most ESP boards)
*/

#include <Arduino.h>

// GPIO Pin Definition
const uint8_t LED_PIN = 2; // Onboard LED on ESP32/ESP8266

void setup() {
  // Configure GPIO 2 as a digital output pin
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH); // Turn LED ON (3.3V)
  delay(1000);                 // Wait 1 second

  digitalWrite(LED_PIN, LOW);  // Turn LED OFF (0V)
  delay(1000);                 // Wait 1 second
}
