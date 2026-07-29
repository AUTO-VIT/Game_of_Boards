// Task 2: Serial-Controlled LED
int ledPin = 2;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char val = Serial.read();

    if (val == '1') {
      digitalWrite(ledPin, HIGH);
    }
    if (val == '0') {
      digitalWrite(ledPin, LOW);
    }
  }
}
