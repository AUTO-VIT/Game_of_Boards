// Task 6: Analog Sensor Read
int sensorPin = 34;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  delay(200);
}
