

#include <ACS712XX.h>
 
ACS712XX ACS712(ACS712_05B,A2);
//ACS712XX ACS712(ACS712_20A,A0);
//ACS712XX ACS712(ACS712_30A,A0);

void setup() {
  Serial.begin(9600);
 float _offset = ACS712.autoCalibrate();   // Must ensure there no current passing through the sensors
  
}

void loop() { 
  Serial.print(F("Measured Current:"));
  
  Serial.print(ACS712.getAC());
  Serial.println(F(" A"));
  delay(100);
}
