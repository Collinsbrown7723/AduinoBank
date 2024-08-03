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
 // _buffer = _readSerial();
 delay(1000);
  Serial.println("returning to listening....");
}