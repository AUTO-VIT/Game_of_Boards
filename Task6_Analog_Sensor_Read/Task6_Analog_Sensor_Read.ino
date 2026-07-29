/*
  Task 6: Analog Sensor Read (ESP32)
  Continuously reads a 12-bit ADC value from GPIO 34, calculates voltage (0-3.3V),
  and outputs results non-blockingly to the Serial Monitor at 115200 baud.
*/

#define ANALOG_PIN 34 // ADC1 Channel 6 pin

unsigned long lastReadTime = 0;
const unsigned long readInterval = 200; // Read interval in ms

void setup() {
  Serial.begin(115200);
  
  // Set ADC resolution to 12-bit (0-4095)
  analogReadResolution(12);

  Serial.println("Task 6 Initialized: Reading Analog Input on GPIO 34.");
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - lastReadTime >= readInterval) {
    lastReadTime = currentMillis;

    // Read raw 12-bit ADC value (0 to 4095)
    int rawADC = analogRead(ANALOG_PIN);

    // Calculate voltage: (rawADC / 4095.0) * 3.3V
    float voltage = (rawADC / 4095.0) * 3.3;

    Serial.print("Raw ADC: ");
    Serial.print(rawADC);
    Serial.print(" | Calculated Voltage: ");
    Serial.print(voltage, 3);
    Serial.println(" V");
  }
}
