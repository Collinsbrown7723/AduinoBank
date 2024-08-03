#include <Servo.h>

/*------------------------------------------

  Sonar Radar System
  By nonstopengineering
  Using Arduino,Ultrasonic and Servo
  ------------------------------------------*/
const int trigPin = 9; //Initializing trigger pin
const int echoPin = 8; //Initializing echo pin
long duration;        
int distance;
byte beep = 11;
Servo myServo; // Creating a servo object for controlling the servo motor

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(beep,OUTPUT);
  Serial.begin(115200);     //Sets Baud rate for Serial communication
  myServo.attach(10); // Defines on which pin is the servo motor attached
}
void loop() {
  
// delay(1000);
// tone(pin,50,100);
  for(int a = 0; a < 180; a=a+5) // rotates the servo motor from 0 to 180 degrees
  {  
  myServo.write(a); //Sending stes to servo which servo should move
  delay(40);
  distance = Distance(); // Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
  Serial.print(a); // Sends the current degree into the Serial Port
  Serial.print(","); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  Serial.println(distance); // Sends the distance value into the Serial Port
  }
  tone(beep,50,100);
  for(int b = 180; b > 0; b=b-5) //   Rversing rotation from 180 to 0 degrees
  {  
  myServo.write(b); 
  delay(40);
  distance = Distance();
  Serial.print(b);
  Serial.print(",");
  Serial.println(distance);
  }
  tone(beep,50,100);
}

int Distance() // Function for calculating the distance measured by the Ultrasonic sensor
{ 
  
  digitalWrite(trigPin, LOW);  // Sets the trigPin on LOW state for 2 micro seconds
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); // Sets the trigPin on HIGH state for 10 micro seconds
  delayMicroseconds(10); 
  digitalWrite(9, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  // distance= duration*0.034/200; //Converting distance into meters
  distance= duration/255;
  return distance;
}
