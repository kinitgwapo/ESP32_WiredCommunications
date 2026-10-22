#include "spi_module.h"

SPIClass spi(VSPI);

void spi_Setup() {
  SPI.begin( // Set ESP32 SPI Pins (SCK, MISO, MOSI, CS)
    SCK_PIN,
    MISO_PIN,
    MOSI_PIN,
    CS_PIN
  );
}