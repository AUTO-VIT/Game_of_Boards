# Plan: Simplify All 7 Arduino Sketches for Beginners / Freshers

## Objective
Simplify all 7 sketches to clean, minimal, beginner-friendly Arduino code modeled directly after standard starter tutorials and the reference examples in `D:/Ashwin/ardiuno code`.

## Proposed Simplifications

1. **`Task1_Basic_LED_Blink/Task1_Basic_LED_Blink.ino`**:
   - Simple `pinMode()`, `digitalWrite(ledPin, HIGH/LOW)`, `delay(1000)`.

2. **`Task2_Serial_Controlled_Blink/Task2_Serial_Controlled_Blink.ino`**:
   - `Serial.available()`, `Serial.read()`, `if (val == '1') digitalWrite(ledPin, HIGH)`, `if (val == '0') digitalWrite(ledPin, LOW)`.

3. **`Task3_LED_PWM_Fading/Task3_LED_PWM_Fading.ino`**:
   - Simple `for` loops from 0 to 255 with `analogWrite(ledPin, i)` and `delay(10)`.

4. **`Task4_Pattern_Blink/Task4_Pattern_Blink.ino`**:
   - Easy `for` loops for S (short), O (long), S (short) blinks with `delay()`.

5. **`Task5_Servo_Motor_PWM/Task5_Servo_Motor_PWM.ino`**:
   - Simple `#include <Servo.h>`, `myServo.attach(18)`, stepping between 0°, 90°, and 180° with `delay(1000)`.

6. **`Task6_Analog_Sensor_Read/Task6_Analog_Sensor_Read.ino`**:
   - Simple `analogRead(sensorPin)`, `Serial.println(sensorValue)`, `delay(200)`.

7. **`Task7_Sensor_To_Servo_Mapping/Task7_Sensor_To_Servo_Mapping.ino`**:
   - Direct `analogRead(sensorPin)`, `angle = map(sensorValue, 0, 4095, 0, 180)`, `myServo.write(angle)`, `delay(50)`.

8. **Update `README.md` & Git Sync**:
   - Update `README.md` code snippets to reflect the minimal beginner sketches.
   - Commit and push to GitHub (`https://github.com/AUTO-VIT/Game_of_Boards.git`).
