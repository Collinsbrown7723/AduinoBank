#define ldr_pin 7
#define led_pin 8
int LDR =0;
int threshold{100};
int a_val{};
void setup() {
 pinMode(ldr_pin,INPUT);

}

void loop() {
  a_val=analogRead(ldr_pin);
if(a_val>=threshold){
  digitalWrite(led_pin,HIGH);
  }
  else{
    digitalWrite(led_pin,HIGH);
    }
}
