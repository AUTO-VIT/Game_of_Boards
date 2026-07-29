# Plan: Remove Ultrasonic Sensor & Re-number Sensor-to-Servo Task

## Proposed Changes
1. **Remove Task 7 (Ultrasonic Sensor)**:
   - Delete directory `D:/Ashwin/VIT/AutoVIT/Game of Boards/Task7_Ultrasonic_Sensor`.

2. **Re-number Task 8 as Task 7**:
   - Rename directory `Task8_Sensor_To_Servo_Mapping` to `Task7_Sensor_To_Servo_Mapping`.
   - Rename file `Task7_Sensor_To_Servo_Mapping/Task8_Sensor_To_Servo_Mapping.ino` to `Task7_Sensor_To_Servo_Mapping/Task7_Sensor_To_Servo_Mapping.ino`.
   - Update header comments inside `Task7_Sensor_To_Servo_Mapping.ino` to reference "Task 7".

3. **Update Documentation**:
   - Update `README.md` to reflect a total of 7 tasks (removing ultrasonic section and updating table/links).

4. **Git Sync**:
   - Commit file removals, renames, and documentation updates.
   - Push updated state to GitHub (`https://github.com/AUTO-VIT/Game_of_Boards.git`).
