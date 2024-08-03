#include <SoftwareSerial.h>
SoftwareSerial sim(10, 11);
int _timeout;
String _buffer;
String number = "+233201035452"; //-> change with your number
void setup() {
  delay(7000); //delay for 7 seconds to make sure the modules get the signal
  Serial.begin(9600);
  _buffer.reserve(50);
  Serial.println("System Started...");
  sim.begin(9600);
  delay(1000);
  Serial.println("Type s to send an SMS, r to receive an SMS, and c to make a call");

}

void loop() {
  if (Serial.available()) {
    char receivedChar = Serial.read();
    Serial.println(receivedChar);
        switch (receivedChar)
    {
      case 's':
        SendMessage();
        break;
      case 'r':
        RecieveMessage();
        break;
      case 'c':
        callNumber();
        break;
    }
  }
}



void SendMessage()
{
  Serial.println ("Sending Message");
  sim.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(200);
  Serial.println ("Set SMS Number");
   //mySerial.println("AT+CMGS=\"+233201035452\"");
  sim.println("AT+CMGS=\"+233201035452\""); //Mobile phone number to send message
  delay(200);
  String SMS = "Hello, how are you? greetings from  admin";
  sim.println(SMS);
  delay(100);
  sim.println((char)26);// ASCII code of CTRL+Z
  delay(200);
   Serial.println("buffering...");
 //_buffer = _readSerial();
 delay(1000);
  Serial.println("returning to listening....");
}
void RecieveMessage()
{
  
  Serial.println ("SIM800L Read an SMS");
  sim.println("AT+CMGF=1");
  delay (200);
  sim.println("AT+CNMI=1,2,0,0,0"); // AT Command to receive a live SMS
  delay(200);
  Serial.write ("Unread Message done");
}
String _readSerial() {
  _timeout = 0;
  while  (!sim.available() && _timeout < 12000  )
  {
    delay(13);
    _timeout++;
  }
  if (sim.available()) {
    return sim.readString();
  }
}
void callNumber() {
  sim.print (F("ATD"));
  sim.print (number);
  sim.print (F(";\r\n"));
  _buffer = _readSerial();
  Serial.println(_buffer);
}


// void send1() {
//   mySerial.println("AT");
//   updateSerial();

//   mySerial.println("AT+CMGF=1");

//   updateSerial();
//   mySerial.println("AT+CMGS=\"+233205055229\"");
//   updateSerial();
//   delay(2000);
//   mySerial.println("My name is placeholder.");
//   mySerial.println("disturbance in farm");
//   updateSerial();
//   mySerial.write(26);
//   mySerial.write("disturbance in farm");
//   delay(5000);
// }

// void updateSerial() {
//   delay(500);
//   while (Serial.available()) {
//     mySerial.write(Serial.read());  //Forward what Serial received to Software Serial Port
//   }
//   while (mySerial.available()) {
//     Serial.write(mySerial.read());  //Forward what Software Serial received to Serial Port
//   }
// }
