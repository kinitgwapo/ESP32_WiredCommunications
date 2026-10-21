#define RX2_PIN 32
#define TX2_PIN 33

unsigned long previousTick_Ref = 0;
#define INTERVAL 1000

void serial_Send();

void serial_Receive();

void setup() {
  Serial.begin(115200); // Sets PC to ESP32 UART Communication

  pinMode(RX2_PIN, INPUT_PULLUP); // Set RX Pin to Pull-Up to filter out noise
  Serial2.begin( // Sets ESP32 UART's TX Pin to its own RX Pin
    9600,
    SERIAL_8N1,
    RX2_PIN,
    TX2_PIN
  );

  while(!(Serial && Serial2));
  Serial.println("Serial initialization was successful!");
}

void loop() {
  serial_Send();
  serial_Receive();

  delay(1);
}

void serial_Send() {
  if(Serial.available()) { // Check once if PC Serial Monitor Command is sending data to ESP32
    String text = Serial.readStringUntil('\n'); // Stores the entire incoming String
    Serial.println("Command sent (Serial Monitor Command): " + text);
    Serial2.println(text); // Let TX2_PIN send data
  }
}

void serial_Receive() {
  unsigned long currentTick_Ref = millis();

  if(currentTick_Ref - previousTick_Ref >= INTERVAL) { // Executes block of code only if the current time surpasses the interval
    previousTick_Ref = currentTick_Ref;

    if(Serial2.available()) { // Check once if there is an incoming data received by RX
      Serial.println("Command received (Serial2): ");

      while(Serial2.available()) { // Checks incoming data received by RX again, but now in loop
        char text = Serial2.read();

        if(text != '\r' && text != '\n') { // Ignore printing unnecessary characters
          Serial.println(text);
        }
      }
    }
  }
}