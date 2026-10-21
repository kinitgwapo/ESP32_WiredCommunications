#include "serial_readwrite.h"

void setup() {
  serial_Setup();
}

void loop() {
  serial_Send();
  serial_Receive();

  delay(1);
}

