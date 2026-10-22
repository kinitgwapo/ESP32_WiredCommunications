#include "spi_module.h"

void spi_Setup() {
  SPI.begin( // Set ESP32 SPI Pins (SCK, MISO, MOSI, CS)
    SCK,
    MISO,
    MOSI,
    CS
  );
}