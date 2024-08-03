/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
String inputString = "";

void setup() {
  myservo.attach(2); 
  Serial.begin(9600);
  inputString.reserve(200);

}
bool stringComplete = false; 
String cmd = "";
void loop() {
cmd = serialEvent();

  }


String serialEvent() {
   if(Serial.available()){
     char inChar = (char)Serial.read();
     inputString += inChar;
     if (inChar == '\n') {
      stringComplete = true;
      Serial.println(inputString);
            if(inputString == 1){
          Serial.println("worked");
}
      inputString = "";
    }
     //delay(10);
   }
  //  return inputString;
}