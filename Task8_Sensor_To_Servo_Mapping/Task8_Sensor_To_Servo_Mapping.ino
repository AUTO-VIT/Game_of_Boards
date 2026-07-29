/*
  Task 8: Sensor-to-Servo Mapping with Noise Filtering (ESP32)
  Reads ADC input on GPIO 34, applies an Exponential Moving Average (EMA) filter
  to eliminate jitter, maps the smoothed 0-4095 range to 0-180 degrees, and controls
  a servo motor on GPIO 18.
*/

#include <ESP32Servo.h>

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

  analogReadResolution(12);

  ESP32PWM::allocateTimer(0);
  myServo.setPeriodHertz(50);
  myServo.attach(SERVO_PIN, 500, 2400);

  filteredADC = analogRead(ANALOG_PIN);

  Serial.println("Task 8 Initialized: Smoothed Sensor-to-Servo Mapping.");
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - lastUpdateTime >= updateInterval) {
    lastUpdateTime = currentMillis;

    // Read raw 12-bit analog input (0 to 4095)
    int rawADC = analogRead(ANALOG_PIN);

    // Apply Exponential Moving Average (EMA) filter
    filteredADC = (alpha * rawADC) + ((1.0 - alpha) * filteredADC);

    // Map filtered ADC value (0-4095) to Servo Angle (0-180 degrees)
    int targetAngle = map((int)filteredADC, 0, 4095, 0, 180);
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
