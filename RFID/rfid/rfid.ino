#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 9
#define SS_1_PIN 10
#define SS_2_PIN 8
byte red = 1;
byte yellow = 2;
byte green = 3;
#define NR_OF_READERS 2

byte ssPins[] = {SS_1_PIN, SS_2_PIN};

MFRC522 mfrc522[NR_OF_READERS];

// Desired UID to detect
byte desiredUID[] = {0x59, 0xDA, 0xB5, 0x98};

void setup() {
  Serial.begin(115200);
  pinMode(red,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(green,OUTPUT);
  while (!Serial);
  SPI.begin();
  for (uint8_t reader = 0; reader < NR_OF_READERS; reader++) {
    mfrc522[reader].PCD_Init(ssPins[reader], RST_PIN);
    Serial.print(F("Reader "));
    Serial.print(reader);
    Serial.print(F(": "));
    mfrc522[reader].PCD_DumpVersionToSerial();
  }
}
void loop(){
  READ();
digitalWrite(red, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  Serial.println("15s.........red.............");
if(READ()){

}else{
  delay(1000);
  }
READ();
  digitalWrite(red, LOW);
  digitalWrite(yellow, HIGH);
  digitalWrite(green, LOW);
  Serial.println("5s...........yellow..........");
if(READ()){

}else{
  delay(1000);
  }
delay(1000);
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, HIGH);
  Serial.println("30s............green........");
  READ();
  if(READ()){

}else{
  delay(1000);
  }
delay(1000);

    }
char READ() {
  for (uint8_t reader = 0; reader < NR_OF_READERS; reader++) {
    if (mfrc522[reader].PICC_IsNewCardPresent() && mfrc522[reader].PICC_ReadCardSerial()) {
      Serial.print(F("Reader "));
      Serial.print(reader);
      Serial.print(F(": Card UID:"));
      if (checkUID(mfrc522[reader].uid.uidByte, mfrc522[reader].uid.size)) {
        // Card UID matches desired UID
        dump_byte_array(mfrc522[reader].uid.uidByte, mfrc522[reader].uid.size);
        Serial.println();
        Serial.print(F("PICC type: "));
        MFRC522::PICC_Type piccType = mfrc522[reader].PICC_GetType(mfrc522[reader].uid.sak);
        Serial.println(mfrc522[reader].PICC_GetTypeName(piccType));
        // Proceed with desired actions
  digitalWrite(red, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  Serial.println("hold position");
  delay(5000);
      } else {
        // Card UID does not match desired UID
        Serial.println(F("Card rejected."));
      }
      mfrc522[reader].PICC_HaltA();
      mfrc522[reader].PCD_StopCrypto1();
    }
  }
}

bool checkUID(byte *buffer, byte bufferSize) {
  if (bufferSize != sizeof(desiredUID))
    return false;
  for (byte i = 0; i < bufferSize; i++) {
    if (buffer[i] != desiredUID[i])
      return false;
  }
  return true;
}

void dump_byte_array(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}
