# Plan: Switch Servo Sketches from ESP32Servo to Standard Servo.h

## Proposed Changes
1. **Update `Task5_Servo_Motor_PWM/Task5_Servo_Motor_PWM.ino`**:
   - Replace `#include <ESP32Servo.h>` with standard `#include <Servo.h>`.
   - Remove `ESP32PWM::allocateTimer()` configuration lines.
   - Retain non-blocking sweep logic (`myServo.attach(SERVO_PIN)` / `myServo.write()`).

2. **Update `Task7_Sensor_To_Servo_Mapping/Task7_Sensor_To_Servo_Mapping.ino`**:
   - Replace `#include <ESP32Servo.h>` with standard `#include <Servo.h>`.
   - Remove `ESP32PWM::allocateTimer()` configuration lines.
   - Retain EMA filtering, 12-bit ADC mapping, and deadband threshold logic.

3. **Update Documentation (`README.md`)**:
   - Update library prerequisites from `ESP32Servo` to standard `Servo.h`.

4. **Git Sync**:
   - Commit and push updated code to GitHub (`https://github.com/AUTO-VIT/Game_of_Boards.git`).
