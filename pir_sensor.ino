// Uses a PIR sensor to detect movement, buzzes a buzzer

int ledPin = 13;                // choose the pin for the LED
int inputPin = 12;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;      
void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
  Serial.begin(9600);
}

void loop(){
  val = digitalRead(inputPin);  // read input value
if(val==HIGH){
  Serial.println("High");
  digitalWrite(ledPin,HIGH);
  }
else{
   digitalWrite(ledPin,HIGH);
   Serial.println("Low");
  }
  delay(100);
}
