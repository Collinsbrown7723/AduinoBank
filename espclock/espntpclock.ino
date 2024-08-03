//The ntp portion of this code is based on the example from https://github.com/arduino-libraries/NTPClient

#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

extern "C"{
#include "display.h"
}

const char *ssid     = "";
const char *password = "";

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

void setup() {
  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
  }

  timeClient.begin();
  timeClient.setTimeOffset(-3 * 3600);//(in seconds), Brazil time is UTC -3:00 
  displayinit();

  //At start up the the ntp library may return garbage, this gives it some time to sync
  while(millis()<10000){
    //update
    timeClient.update();
    
    delay(500);
  }
  
}

int hours = 0, minutes = 0;
void loop() {
  timeClient.update();

  hours = (byte)timeClient.getHours();
  minutes = (byte)timeClient.getMinutes();

  //This refreshes the display settings, not the data
  //Sometimes the dispaly would hang up and show nothing 
  //while the esp would continue to run 
  displayrefresh();
  //update the display
  displayWrite(hours, minutes);

  //update after one second or so
  delay(1000);
}
