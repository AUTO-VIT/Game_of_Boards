# Game of Boards: ESP Microcontroller Course Suite 🚀

Welcome to the **ESP Microcontroller (ESP32 / ESP8266) Coding Suite** for the *Game of Boards* course. This repository contains 7 clean, beginner-friendly Arduino sketches designed for students and freshers.

---

## 📂 Repository Structure & Sketches

Each sketch is located in its own directory matching Arduino IDE project conventions:

| # | Directory / Sketch Name | Description | GPIO Mapping |
|---|---|---|---|
| 1 | [`Task1_Basic_LED_Blink/`](./Task1_Basic_LED_Blink/Task1_Basic_LED_Blink.ino) | Turn an LED ON and OFF with 1-second delay | GPIO 2 |
| 2 | [`Task2_Serial_Controlled_Blink/`](./Task2_Serial_Controlled_Blink/Task2_Serial_Controlled_Blink.ino) | Read `'1'` or `'0'` from Serial Monitor to control LED | GPIO 2 |
| 3 | [`Task3_LED_PWM_Fading/`](./Task3_LED_PWM_Fading/Task3_LED_PWM_Fading.ino) | Fade LED bright and dim using `analogWrite()` | GPIO 4 |
| 4 | [`Task4_Pattern_Blink/`](./Task4_Pattern_Blink/Task4_Pattern_Blink.ino) | SOS Morse code blink pattern (`... --- ...`) | GPIO 2 |
| 5 | [`Task5_Servo_Motor_PWM/`](./Task5_Servo_Motor_PWM/Task5_Servo_Motor_PWM.ino) | Move servo to 0°, 90°, and 180° positions | GPIO 18 |
| 6 | [`Task6_Analog_Sensor_Read/`](./Task6_Analog_Sensor_Read/Task6_Analog_Sensor_Read.ino) | Read analog sensor value and print to Serial Monitor | GPIO 34 |
| 7 | [`Task7_Sensor_To_Servo_Mapping/`](./Task7_Sensor_To_Servo_Mapping/Task7_Sensor_To_Servo_Mapping.ino) | Map analog input ($0-4095$) directly to servo angle ($0-180^\circ$) | GPIO 34 $\rightarrow$ GPIO 18 |

---

## 💻 Beginner Code Snippets

### Task 1: Basic LED Blink
```cpp
int ledPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
}
```

### Task 2: Serial-Controlled LED
```cpp
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
```

### Task 3: LED PWM (Fading)
```cpp
int ledPin = 4;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for (int i = 0; i <= 255; i++) {
    analogWrite(ledPin, i);
    delay(10);
  }
  for (int i = 255; i >= 0; i--) {
    analogWrite(ledPin, i);
    delay(10);
  }
}
```

### Task 4: Pattern Blink (SOS)
```cpp
int ledPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // 3 short blinks
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
  }
  delay(500);

  // 3 long blinks
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(600);
    digitalWrite(ledPin, LOW);
    delay(200);
  }
  delay(500);

  // 3 short blinks
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
  }
  delay(2000);
}
```

### Task 5: Servo Motor Control
```cpp
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
```

### Task 6: Analog Sensor Read
```cpp
int sensorPin = 34;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  delay(200);
}
```

### Task 7: Sensor-to-Servo Mapping
```cpp
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
```

---

## 📜 License & Usage
This repository is created for educational purposes as part of the AutoVIT *Game of Boards* course curriculum.
