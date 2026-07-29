/*
  Task 2: Serial-Controlled Blink (Non-Blocking)
  Board: ESP32 / ESP8266
  Pin: GPIO 2
  Serial Speed: 115200 baud
  Commands:
    '1' -> Turn LED ON
    '0' -> Turn LED OFF
    'b' / 'B' -> Enable Blink Mode
*/

#include <Arduino.h>

const uint8_t LED_PIN = 2;

enum LedMode {
  MODE_OFF,
  MODE_ON,
  MODE_BLINK
};

LedMode currentMode = MODE_OFF;

// Non-blocking timing variables
unsigned long previousMillis = 0;
const unsigned long BLINK_INTERVAL = 500; // Blink toggle interval in ms
bool ledState = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Serial.begin(115200);
  delay(500);
  
  Serial.println("\n=== ESP Serial LED Controller ===");
  Serial.println("Send commands via Serial Monitor (115200 Baud):");
  Serial.println("  '1' -> Turn LED ON");
  Serial.println("  '0' -> Turn LED OFF");
  Serial.println("  'b' -> Start Blink Mode");
  Serial.println("=================================");
}

void loop() {
  // Read Serial Commands
  if (Serial.available() > 0) {
    char command = Serial.read();

    switch (command) {
      case '1':
        currentMode = MODE_ON;
        digitalWrite(LED_PIN, HIGH);
        Serial.println("Command Received: LED Turned ON");
        break;

      case '0':
        currentMode = MODE_OFF;
        digitalWrite(LED_PIN, LOW);
        Serial.println("Command Received: LED Turned OFF");
        break;

      case 'b':
      case 'B':
        currentMode = MODE_BLINK;
        previousMillis = millis();
        Serial.println("Command Received: LED Blink Mode Activated");
        break;

      case '\n':
      case '\r':
        break;

      default:
        Serial.print("Unknown command: ");
        Serial.println(command);
        break;
    }
  }

  // Execute Blink Mode non-blockingly using millis()
  if (currentMode == MODE_BLINK) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= BLINK_INTERVAL) {
      previousMillis = currentMillis;
      ledState = !ledState;
      digitalWrite(LED_PIN, ledState ? HIGH : LOW);
    }
  }
}
