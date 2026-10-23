#include "i2c_lib.h"

void i2c_Setup() {
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

void i2c_address_scan() {
  bool acknowledged = false;

  // Sends 7-bit Addresses except value 0:127 because they are reserved
  for (uint8_t address = 1; address < 127; address++) {
    Wire.beginTransmission(address); // Queue bytes/addresses
    uint8_t result = Wire.endTransmission(); // Sends bytes/addresses and returns a status code (ACK - Acknowledgement from peripheral)

    if(result == 0) { // Status code (0) indicates as address sent acknowledged by a peripheral device
      Serial.println("Peripheral device acknowledged on address " + String(address, HEX));
      acknowledged = true;
    }
  }

  if(acknowledged == false) { // Status code (2) indicates as address sent not acknowledged by any peripheral device
    Serial.println("No peripheral device(s) address was acknowledged!");
  }

  Serial.println("Scanning Complete.");
}
