#include "spi_module.h"

#define SCK 19
#define MISO 21
#define MOSI 22
#define CS 23

void spi_Setup() {
  SPI.begin()
}