#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);   // Start Serial
  SPI.begin();          // Start SPI bus
  mfrc522.PCD_Init();   // Init MFRC522 reader
  Serial.println("Scan an RFID card...");
}

void loop() {
  // Look for new cards
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  // Select one of the cards
  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Print UID
  Serial.print("UID Tag: ");
  String uidStr = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    if (mfrc522.uid.uidByte[i] < 0x10) {
      Serial.print("0");
      uidStr += "0";
    }
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    uidStr += String(mfrc522.uid.uidByte[i], HEX);
  }
  uidStr.toUpperCase();
  Serial.println();
  Serial.print("UID String: ");
  Serial.println(uidStr);

  delay(1000);
}