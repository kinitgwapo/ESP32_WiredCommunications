#ifndef SERIAL_READWRITE_H
#define SERIAL_READWRITE_H

#include <Arduino.h>

#define RX2_PIN 32
#define TX2_PIN 33

#define INTERVAL 1000

void serial_Setup();

void serial_Send();

void serial_Receive();

#endif