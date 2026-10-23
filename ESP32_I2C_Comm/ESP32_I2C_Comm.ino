#include "i2c_lib.h"

void setup() {
  i2c_Setup();
  i2c_address_scan();
}

void loop() {
}