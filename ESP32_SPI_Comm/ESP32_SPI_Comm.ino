#include "spi_module.h"

void setup() {
  spi_Setup();
}

void loop() {
  spi_sendreceive();
  delay(1000);
}
