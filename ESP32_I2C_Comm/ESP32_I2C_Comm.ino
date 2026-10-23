#include <Wire.h>

/*
  External pull-up resistor is a must in I2C protocol because it allows devices to pull the current voltage level.
  The pull-Up resistor should allow 500uA+ to pass through easily, avoid using a high-resistance pull-up resistor.

  SDA and SCL must have their own external pull-up resistor.
*/

#define SDA_PIN 18
#define SCL_PIN 19

void setup() {
  Serial.begin(115200); // Set PC to ESP32 UART Communication

  /*
    For this scenario, internal pull-up resistors are used even though they have high resistance.
    (For testing and should not be done in production)
  */
  pinMode(SDA_PIN, INPUT_PULLUP);
  pinMode(SCL_PIN, INPUT_PULLUP);

  // Initialize Wire library protocols; Set as Controller; Set SDA & SCL Pins
  Wire.begin(SDA_PIN, SCL_PIN);
}

void loop() {
}
