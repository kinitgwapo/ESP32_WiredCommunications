#include "spi_module.h"

SPIClass spi(VSPI);

void spi_Setup() {
  Serial.begin(115200); // Sets PC to ESP32 UART Communication

  pinMode(CS_PIN, OUTPUT); // Set CS_PIN to Output mode
  digitalWrite(CS_PIN, LOW); // Set CS_PIN Initial state as Low

  spi.begin( // Set ESP32 SPI Pins (SCK, MISO, MOSI, CS)
    SCK_PIN,
    MISO_PIN,
    MOSI_PIN,
    CS_PIN
  );
}

void spi_sendreceive() {
  SPISettings SPIConfig(ONE_MHZ, MSBFIRST, SPI_MODE0); // Configure SPI Settings (Clock, bit Order, Data Mode)
  uint8_t txValue = 0xA5;
  uint8_t rxValue = 0;

  spi.beginTransaction(SPIConfig); // Initialize SPI Transaction with SPIConfig

  digitalWrite(CS_PIN, LOW); // Set CS_PIN state to Low
  Serial.println("Current CS State: " + String(digitalRead(CS_PIN)));

  rxValue = spi.transfer(txValue); // Outputs data to MOSI Pin (In this scenario, MOSI pin connects to MISO pin, which simply uses the same value to return the data sent from MOSI to MISO)

  digitalWrite(CS_PIN, HIGH); // Set CS_PIN state to High
  Serial.println("Current CS State: " + String(digitalRead(CS_PIN)));

  spi.endTransaction(); // End SPI Transaction

  Serial.println(
    "Sent: " + String(txValue) +
    "\nReceived: " + String(rxValue)
  );
}