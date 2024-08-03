# espclock

This is a clock I built for my mother based on the esp8266.
This was my first experience with this chip since it was released, unforntunately, as I found it pretty useful. 

The main code is basically a copy and paste of the ntp example of the Arduino library available [here](https://github.com/arduino-libraries/NTPClient)

The work I had was to code functions to control a MAX7219 chip that drives the four digit seven segment display and make the board layout for supporting the esp8266 module.

I used an old ESP01 module. Its few IOs were enough as I only needed three pins to control the max7219 chip.
