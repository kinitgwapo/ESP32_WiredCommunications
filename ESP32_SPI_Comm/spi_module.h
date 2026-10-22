#ifndef SPI_MODULE_H
#define SPI_MODULE_H

#define SCK 19
#define MISO 21
#define MOSI 22
#define CS 23

#include <Arduino.h>
#include <SPI.h>

void spi_Setup();

#endif