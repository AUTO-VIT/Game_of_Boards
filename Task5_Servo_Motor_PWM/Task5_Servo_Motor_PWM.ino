// Task 5: Servo Motor Control
#include <Servo.h>

int servoPin = 18;
Servo myServo;

void setup() {
  myServo.attach(servoPin);
}

void loop() {
  myServo.write(0);
  delay(1000);

  myServo.write(90);
  delay(1000);

  myServo.write(180);
  delay(1000);
}
