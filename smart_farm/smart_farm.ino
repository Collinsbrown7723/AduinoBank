#include <SoftwareSerial.h>
SoftwareSerial mySerial(8, 7);

int sensor_1 = 0;
int sensor_2 = 0;
int sensor_3 = 0;
int sensor_4 = 0;

int pir_1 = 10;
int pir_2 = 9;
int pir_3 = 11;
int pir_4 = 2;

byte buzzer = 6;


void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  delay(1000);
  pinMode(pir_1, INPUT);
  pinMode(pir_2, INPUT);
  pinMode(pir_3, INPUT);
  pinMode(pir_4, INPUT);
  // pinMode(pir_2, INPUT);
  // pinMode(pir_3, INPUT);
  // pinMode(pir_4, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  sensor_1 = digitalRead(pir_1);
  sensor_2 = digitalRead(pir_2);
  sensor_3 = digitalRead(pir_3);
  sensor_4 = digitalRead(pir_4);
  //sensor_1 = digitalRead(pir_1);
  //Serial.println(sensor_1);
   digitalWrite(buzzer, HIGH);
  Serial.println(sensor_1);
  Serial.println(sensor_2);
  Serial.println(sensor_3);
  Serial.println(sensor_4);
  //delay(1000);

  if (sensor_1 == HIGH || sensor_2 == HIGH || sensor_3 == HIGH || sensor_4 == HIGH) {
    digitalWrite(buzzer, LOW);
    delay(5000);
    Serial.print("sensor 1 state = ");
    Serial.println(sensor_1);
    Serial.print("sensor 2 state = ");
    Serial.println(sensor_2);
    Serial.print("sensor 3 state = ");
    Serial.println(sensor_3);
    Serial.print("sensor 4 state = ");
    Serial.println(sensor_4);

    Serial.println();
   // delay(1000);
    digitalWrite(buzzer, HIGH);
    //  digitalWrite(sensor_1,LOW);
    //gsm funtion
    send1();
  }
}

void send1() {
  mySerial.println("AT");
  updateSerial();

  mySerial.println("AT+CMGF=1");

  updateSerial();
  mySerial.println("AT+CMGS=\"+233205055229\"");
  updateSerial();
  delay(2000);
  mySerial.println("My name is placeholder.");
  mySerial.println("disturbance in farm");
  updateSerial();
  mySerial.write(26);
  mySerial.write("disturbance in farm");
  delay(5000);
}

void updateSerial() {
  delay(500);
  while (Serial.available()) {
    mySerial.write(Serial.read());  //Forward what Serial received to Software Serial Port
  }
  while (mySerial.available()) {
    Serial.write(mySerial.read());  //Forward what Software Serial received to Serial Port
  }
}
