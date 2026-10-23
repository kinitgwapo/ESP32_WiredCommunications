#include <Wire.h>

/*
  External pull-up resistor is a must in I2C protocol because it allows devices to pull the current voltage level.
  The pull-Up resistor should allow 500uA+ to pass through easily, avoid using a high-resistance pull-up resistor.

  SDA and SCL must have their own external pull-up resistor.
*/

#define SDA_PIN 18
#define SCL_PIN 19

void i2c_address_scan();

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

void i2c_address_scan() {
  bool result;

  // Sends 7-bit Addresses except value 0:127 because they are reserved
  for (uint8_t address = 1; address < 127; address++) {
    Wire.beginTransmission(address); // Queue bytes/addresses
    result = Wire.endTransmission(); // Sends bytes/addresses and returns a status code (ACK - Acknowledgement from peripheral)

    if(result == 0) { // Status code (0) indicates as address sent acknowledged by a peripheral device
      Serial.println("Peripheral device acknowledged on address " + String(address, HEX));
    }
  }

  if(result == 2) {
    Serial.println("No peripheral device address was acknowledged!");
  }

  Serial.println("Scanning Complete.");
}