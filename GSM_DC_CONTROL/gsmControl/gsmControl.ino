/* 
 *     
 *    PINOUT: 
 *        _____________________________
 *       |  ARDUINO UNO >>>   SIM800L  |
 *        -----------------------------
 *            GND      >>>   GND
 *        RX  10       >>>   TX    
 *        TX  11       >>>   RX
 *       RESET 2       >>>   RST 
 *        
 *
*/

#include <Sim800l.h>
#include <SoftwareSerial.h> //is necesary for the library!! 
Sim800l Sim800l;  //to declare the library
char* text;
char* number;
bool error; //to catch the response of sendSms
int day,month,year,minute,second,hour;

void setup(){
  	Serial.begin(115200);
	Sim800l.begin(); // initializate the library. 
	text="hello from phone";  //text for the message. 
	number="233201035452"; //change to a valid number.
	error=Sim800l.sendSms(number,text);
	// OR 
	//Sim800l.sendSms("+540111111111","the text go here")


}

void loop(){
	//Sim800l.RTCtime(&day,&month,&year,&hour,&minute,&second);
 Sim800l.sendSms(number,text);
Serial.println("..");
}