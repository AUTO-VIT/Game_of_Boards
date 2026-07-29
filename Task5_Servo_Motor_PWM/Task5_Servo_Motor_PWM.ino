/*
  Task 5: Servo Motor PWM Control
  Sweeps a servo motor from 0 to 180 degrees non-blockingly using standard Servo.h on GPIO 18.
*/

#include <Servo.h>

#define SERVO_PIN 18

Servo myServo;

unsigned long previousMillis = 0;
const unsigned long stepInterval = 15; // Time in ms between 1-degree steps

int currentAngle = 0;
int sweepDirection = 1; // 1 = moving up (0->180), -1 = moving down (180->0)

void setup() {
  Serial.begin(115200);

  // Attach servo pin with standard pulse width limits (500us=0 deg, 2400us=180 deg)
  myServo.attach(SERVO_PIN, 500, 2400);

  Serial.println("Task 5 Initialized: Sweeping Servo 0 to 180 degrees using Servo.h.");
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= stepInterval) {
    previousMillis = currentMillis;

    myServo.write(currentAngle);

    currentAngle += sweepDirection;
    if (currentAngle >= 180 || currentAngle <= 0) {
      sweepDirection = -sweepDirection;
    }
  }
}
