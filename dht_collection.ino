

#include "DHT.h"

#define DHTPIN A0   
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float humidity  = dht.readHumidity();
  float temperature = dht.readTemperature();
  Serial.print("temperature :" );
  Serial.println(temperature );
   Serial.print("humidity :" );
  Serial.println(humidity  );
  delay(1000);
}
