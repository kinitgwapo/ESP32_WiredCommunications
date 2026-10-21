#define RX2_PIN 32
#define TX2_PIN 33

void serial_Send();

void serial_Receive();

void setup() {
  Serial.begin(9600);

  Serial2.begin(
    9600,
    SERIAL_8N1,
    RX2_PIN,
    TX2_PIN
  );

  if(Serial && Serial2) {
    Serial.println("Serial initialization was successfull!");
  }
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