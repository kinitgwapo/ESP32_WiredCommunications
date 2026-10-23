#ifndef I2C_LIB_H
#define I2C_LIB_H

#include <Arduino.h>
#include <Wire.h>

/*
  External pull-up resistor is a must in I2C protocol because it allows devices to pull the current voltage level.
  The pull-Up resistor should allow 500uA+ to pass through easily, avoid using a high-resistance pull-up resistor.

  SDA and SCL must have their own external pull-up resistor.
*/

#define SDA_PIN 18
#define SCL_PIN 19

void i2c_Setup();
void i2c_address_scan();

#endif