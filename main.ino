#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
#define BUZZER 6
#define GREEN_LED 7
#define RED_LED 8

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();

  pinMode(BUZZER, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  digitalWrite(BUZZER, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);

  Serial.println("READY");
}

void loop() {
  // Detect RFID card
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    // Convert UID to string
    String uidStr = "";
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      if (mfrc522.uid.uidByte[i] < 0x10) uidStr += "0";
      uidStr += String(mfrc522.uid.uidByte[i], HEX);
    }
    uidStr.toUpperCase();

    Serial.println(uidStr); // Send UID to PC

    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
    delay(500);
  }

  // Listen for Python feedback
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();

    if (cmd == "VALID") {
      digitalWrite(GREEN_LED, HIGH);
      tone(BUZZER, 1000);
      delay(200);
      noTone(BUZZER);
      delay(800);
      digitalWrite(GREEN_LED, LOW);
    }
    else if (cmd == "INVALID") {
      digitalWrite(RED_LED, HIGH);
      tone(BUZZER, 500);
      delay(3000);
      noTone(BUZZER);
      digitalWrite(RED_LED, LOW);
    }
  }
}