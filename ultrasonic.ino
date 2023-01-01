
#include <HCSR04.h>
float distance1 = 0;
float  distance2 = 0;
HCSR04 ultrasonicSensor_01(6, 7);
HCSR04 ultrasonicSensor_02(8, 9);
int ldr=0;
int ledPin = 13;               
int inputPin = 2;              
int pirState = LOW;            
int val = 0; 
int led = 5;

void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(115200);
  ultrasonicSensor_01.begin();
  ultrasonicSensor_02.begin();
}

void loop()
{
  LDR();
  //...................data collection........................
  distance1 = ultrasonicSensor_01.getDistance();
  distance2 = ultrasonicSensor_02.getDistance();
  val = digitalRead(inputPin); 
  //..........................................................
  Serial.print(F("Sensor_01: "));
  Serial.println(distance1);
  Serial.print(F("Sensor_02: "));
  Serial.println(distance2);
  delay(10);
  //..........................functions execution.............
  humanDetected();
  ultraSonic();
}
//...........................fuctional parts
void ultraSonic () {
  if (distance1<= 100) {
   analogWrite(led, 255);
   
  }
  else if (distance2<= 100){
     analogWrite(led, 255);
    }
    else{
        analogWrite(led, 70);
      }
}
void humanDetected(){
  if(val==HIGH){
  Serial.println("human heat signatures detected");
  digitalWrite(ledPin,HIGH);
  }
else{
   digitalWrite(ledPin,HIGH);
   Serial.println("no signatures");
  }
  delay(1000);
}
  void  LDR(){
    while(ldr<=100){
      analogWrite(led,0);
      }
    }
  
