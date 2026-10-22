#ifndef SPI_MODULE_H
#define SPI_MODULE_H

#define SCK_PIN 19
#define MISO_PIN 21
#define MOSI_PIN 22
#define CS_PIN 23

#define ONE_MHZ 1000000

#include <Arduino.h>
#include <SPI.h>

void spi_Setup();

void spi_sendreceive();

#endif