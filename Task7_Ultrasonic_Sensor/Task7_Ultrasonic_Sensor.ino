/*
  Task 7: HC-SR04 Ultrasonic Distance Sensor (ESP32)
  Triggers ultrasonic bursts and measures return pulse duration using pulseIn()
  to calculate distance in centimeters non-blockingly.
*/

#define TRIG_PIN 5
#define ECHO_PIN 18

const float SOUND_SPEED_CM_PER_US = 0.0343;

unsigned long lastSensorRead = 0;
const unsigned long sensorInterval = 100; // Sample every 100 ms

void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  digitalWrite(TRIG_PIN, LOW);

  Serial.println("Task 7 Initialized: HC-SR04 Ultrasonic Sensor on GPIO 5 (Trig) & GPIO 18 (Echo).");
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - lastSensorRead >= sensorInterval) {
    lastSensorRead = currentMillis;

    // Send 10 microsecond HIGH pulse to Trigger pin
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // Read pulse duration on Echo pin in microseconds
    long durationUs = pulseIn(ECHO_PIN, HIGH, 30000);

    if (durationUs == 0) {
      Serial.println("Distance: Out of range / Timeout");
    } else {
      float distanceCm = (durationUs * SOUND_SPEED_CM_PER_US) / 2.0;

      Serial.print("Distance: ");
      Serial.print(distanceCm, 1);
      Serial.println(" cm");
    }
  }
}
