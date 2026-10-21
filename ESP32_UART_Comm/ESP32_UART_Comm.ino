#define RX2_PIN 32
#define TX2_PIN 33

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
  if(Serial.available()) {
    String text = Serial.readStringUntil('\n');
    Serial.println("Command sent (Serial Monitor Command): " + text);
    Serial2.println(text);
  }
}

void serial_Receive() {
  if(Serial2.available()) {
    String text = Serial2.readStringUntil('\n');
    Serial.println("Command received (Serial2): " + text);
  }
}