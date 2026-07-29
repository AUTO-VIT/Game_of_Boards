/*
  Task 7: Sensor-to-Servo Mapping with Noise Filtering
  Reads ADC input on GPIO 34, applies an Exponential Moving Average (EMA) filter
  to eliminate jitter, maps the smoothed 0-4095 range to 0-180 degrees, and controls
  a servo motor on GPIO 18 using standard Servo.h.
*/

#include <Servo.h>

#define ANALOG_PIN 34
#define SERVO_PIN  18

Servo myServo;

// Noise Filtering Parameters
float filteredADC = 0.0;
const float alpha = 0.15; // Smoothing factor (0.01 = heavy smoothing, 1.0 = no smoothing)

// Threshold / Deadband setting to eliminate servo jitter
int lastServoAngle = -1;
const int ANGLE_THRESHOLD = 1; 

unsigned long lastUpdateTime = 0;
const unsigned long updateInterval = 20; // 50 Hz update rate (20 ms interval)

void setup() {
  Serial.begin(115200);

#if defined(ESP32)
  analogReadResolution(12);
#endif

  myServo.attach(SERVO_PIN, 500, 2400);

  filteredADC = analogRead(ANALOG_PIN);

  Serial.println("Task 7 Initialized: Smoothed Sensor-to-Servo Mapping using Servo.h.");
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - lastUpdateTime >= updateInterval) {
    lastUpdateTime = currentMillis;

    // Read raw analog input
    int rawADC = analogRead(ANALOG_PIN);

    // Apply Exponential Moving Average (EMA) filter
    filteredADC = (alpha * rawADC) + ((1.0 - alpha) * filteredADC);

    // Map filtered ADC value (0-4095 for ESP32 12-bit) to Servo Angle (0-180 degrees)
#if defined(ESP32)
    int targetAngle = map((int)filteredADC, 0, 4095, 0, 180);
#else
    int targetAngle = map((int)filteredADC, 0, 1023, 0, 180);
#endif
    targetAngle = constrain(targetAngle, 0, 180);

    // Deadband threshold logic
    if (abs(targetAngle - lastServoAngle) >= ANGLE_THRESHOLD) {
      myServo.write(targetAngle);
      lastServoAngle = targetAngle;

      Serial.print("Raw ADC: ");
      Serial.print(rawADC);
      Serial.print(" | Filtered ADC: ");
      Serial.print((int)filteredADC);
      Serial.print(" -> Servo Angle: ");
      Serial.print(targetAngle);
      Serial.println(" deg");
    }
  }
}
