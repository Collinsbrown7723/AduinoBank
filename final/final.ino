#include <SoftwareSerial.h>
SoftwareSerial sim(10, 11); 
int _timeout;
String _buffer;
String SMS = "CONNECTION FROM GSM CONTROL WITH ESP8266";
//String number = "+233201035452"; //-> change with your number
void setup() {
  delay(7000); //delay for 7 seconds to make sure the modules get the signal
  Serial.begin(9600);
  _buffer.reserve(50);
  Serial.println("Sistem Started...");
  sim.begin(9600);
  delay(1000);
 // Serial.println("Type s to send an SMS, r to receive an SMS, and c to make a call");
SendMessage(); //send first test
}

void loop() {
  if (Serial.available()) {
    char receivedChar = Serial.read();
 //   handleRecieve(receivedChar);
  }
  SendMessage();
  delay(1000);
}
/*
handleRecieve(){
    switch (receivedChar)
    case '000':
    //start 
    break;
    case '001':
    //second speed
    break;
    case '010':
    //thirdspeed
    break;
    case '100':
    //stop
    break;
    default:
    //default
    break;
    }
*/
void SendMessage()
{
  Serial.println ("Sending Message");
  sim.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(200);
  Serial.println ("Set SMS Number");
   //mySerial.println("AT+CMGS=\"+233201035452\"");
  sim.println("AT+CMGS=\"+233201035452\""); //Mobile phone number to send message
  delay(200);
  String SMS = "CONNECTION FROM GSM CONTROL WITH ESP8266";
  sim.println(SMS);
  delay(100);
  sim.println((char)26);// ASCII code of CTRL+Z
  delay(200);
   Serial.println("buffering...");
 // _buffer = _readSerial();
 delay(1000);
  Serial.println("returning to listening....");
}
