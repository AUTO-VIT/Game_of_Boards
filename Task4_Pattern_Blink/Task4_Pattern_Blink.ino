/*
  Task 4: Structured Pattern Blink (SOS Morse Code)
  Board: ESP32 / ESP8266
  Pin: GPIO 2
*/

#include <Arduino.h>

const uint8_t LED_PIN = 2;

// Timing constants for SOS Pattern (in ms)
const uint16_t DOT_TIME   = 150; // Short pulse (.)
const uint16_t DASH_TIME  = 450; // Long pulse (-)
const uint16_t GAP_TIME   = 150; // Gap between elements
const uint16_t LETTER_GAP = 500; // Gap between letters
const uint16_t WORD_GAP   = 2000;// Pause before repeat

inline void setLed(bool state) {
  digitalWrite(LED_PIN, state ? HIGH : LOW);
}

void pulse(uint16_t onDuration, uint16_t offDuration) {
  setLed(true);
  delay(onDuration);
  setLed(false);
  delay(offDuration);
}

void playSOSPattern() {
  // 'S': Three dots (...)
  for (int i = 0; i < 3; i++) {
    pulse(DOT_TIME, GAP_TIME);
  }
  delay(LETTER_GAP - GAP_TIME);

  // 'O': Three dashes (---)
  for (int i = 0; i < 3; i++) {
    pulse(DASH_TIME, GAP_TIME);
  }
  delay(LETTER_GAP - GAP_TIME);

  // 'S': Three dots (...)
  for (int i = 0; i < 3; i++) {
    pulse(DOT_TIME, GAP_TIME);
  }

  delay(WORD_GAP);
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  setLed(false);
  
  Serial.begin(115200);
  Serial.println("Pattern Generator Started: Playing SOS Morse Code");
}

void loop() {
  playSOSPattern();
}
