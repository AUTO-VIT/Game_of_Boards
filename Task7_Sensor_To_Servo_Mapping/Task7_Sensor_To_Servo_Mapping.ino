// Task 7: Sensor-to-Servo Mapping
#include <Servo.h>

int sensorPin = 34;
int servoPin = 18;
Servo myServo;

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  int angle = map(sensorValue, 0, 4095, 0, 180);
  
  myServo.write(angle);
  Serial.println(angle);
  delay(50);
}
