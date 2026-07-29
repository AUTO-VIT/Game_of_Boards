/*
  Task 3: LED PWM (Fading)
  Board: ESP32 / ESP8266
  Pin: GPIO 4
  Fading using ESP32 LEDC Peripheral / analogWrite
*/

#include <Arduino.h>

const uint8_t LED_PIN = 4; // External LED on GPIO 4

// PWM Configuration Parameters
const uint32_t PWM_FREQ = 5000;    // 5 kHz PWM frequency
const uint8_t  PWM_RES_BITS = 10;   // 10-bit resolution (0 - 1023 steps)
const uint32_t MAX_DUTY = (1 << PWM_RES_BITS) - 1; // 1023 for 10-bit

// Non-blocking timing variables
unsigned long prevFadeMillis = 0;
const unsigned long FADE_INTERVAL = 5; // Step duty every 5 ms

int currentDuty = 0;
int fadeDirection = 1; // +1 for fading up, -1 for fading down

void setup() {
  Serial.begin(115200);

#if defined(ESP32)
  #if defined(ESP_ARDUINO_VERSION_MAJOR) && (ESP_ARDUINO_VERSION_MAJOR >= 3)
    // ESP32 Core v3.x API: Automatically assigns channel to pin
    ledcAttach(LED_PIN, PWM_FREQ, PWM_RES_BITS);
    Serial.println("ESP32 LEDC PWM initialized using Core v3.x API");
  #else
    // ESP32 Core v2.x API: Manual channel assignment (Channel 0)
    ledcSetup(0, PWM_FREQ, PWM_RES_BITS);
    ledcAttachPin(LED_PIN, 0);
    Serial.println("ESP32 LEDC PWM initialized using Core v2.x API");
  #endif
#else
  pinMode(LED_PIN, OUTPUT);
  Serial.println("Initialized standard analogWrite PWM");
#endif
}

void setPwmDuty(uint8_t pin, uint32_t duty) {
#if defined(ESP32)
  #if defined(ESP_ARDUINO_VERSION_MAJOR) && (ESP_ARDUINO_VERSION_MAJOR >= 3)
    ledcWrite(pin, duty);
  #else
    ledcWrite(0, duty);
  #endif
#else
  analogWrite(pin, duty);
#endif
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - prevFadeMillis >= FADE_INTERVAL) {
    prevFadeMillis = currentMillis;

    setPwmDuty(LED_PIN, currentDuty);

    currentDuty += fadeDirection * 5;

    if (currentDuty >= (int)MAX_DUTY) {
      currentDuty = MAX_DUTY;
      fadeDirection = -1;
    } else if (currentDuty <= 0) {
      currentDuty = 0;
      fadeDirection = 1;
    }
  }
}
