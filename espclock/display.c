#include<stdint.h>
#include<Arduino.h>

#include "display.h"

#define max7219_reg_noop        0x00
#define max7219_reg_digit0      0x01
#define max7219_reg_digit1      0x02
#define max7219_reg_digit2      0x03
#define max7219_reg_digit3      0x04
#define max7219_reg_digit4      0x05
#define max7219_reg_digit5      0x06
#define max7219_reg_digit6      0x07
#define max7219_reg_digit7      0x08
#define max7219_reg_decodeMode  0x09
#define max7219_reg_intensity   0x0a
#define max7219_reg_scanLimit   0x0b
#define max7219_reg_shutdown    0x0c
#define max7219_reg_displayTest 0x0f



void writeByte(uint8_t data) {
  for (uint8_t i = 0; i < 8; i++) {
    digitalWrite(CLK, LOW);//displayPort&=~(1<<CLK);
    delay(1);
    if (data & (1 << (7 - i))) {
      digitalWrite(DIN, HIGH);//displayPort|=(1<<DIN);
    } else {
      digitalWrite(DIN, LOW);//displayPort&=~(1<<DIN);
    }
    delay(1);
    digitalWrite(CLK, HIGH);//displayPort|=(1<<CLK);
    delay(1);
  }
}
void maxWrite(uint8_t reg, uint8_t data) {
  digitalWrite(LOAD, LOW);//displayPort&=~(1<<LOAD);
  delay(1);
  writeByte(reg);
  writeByte(data);
  delay(1);
  digitalWrite(LOAD, HIGH);//displayPort|=(1<<LOAD);
}


void displayinit(void) {
  //displayDDR=(1<<LOAD)|(1<<CLK)|(1<<DIN);
  pinMode(LOAD, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(DIN, OUTPUT);

  //displayPort=(1<<LOAD)|(1<<CLK)|(1<<DIN);
  digitalWrite(LOAD, HIGH);
  digitalWrite(CLK, HIGH  );
  digitalWrite(DIN, HIGH);

  maxWrite(max7219_reg_scanLimit, 0x03);
  maxWrite(max7219_reg_decodeMode, 0x0F);
  maxWrite(max7219_reg_shutdown, 0x01);
  maxWrite(max7219_reg_displayTest, 0x00);
  maxWrite(max7219_reg_intensity, 0x0f);

  //displayWrite(0,0);

}
void displayrefresh(void){
  maxWrite(max7219_reg_scanLimit, 0x03);
  maxWrite(max7219_reg_decodeMode, 0x0F);
  maxWrite(max7219_reg_shutdown, 0x01);
  maxWrite(max7219_reg_displayTest, 0x00);
  maxWrite(max7219_reg_intensity, 0x0f);
}

void displayWrite(uint8_t hours, uint8_t minutes) {
  uint8_t timeA[4];
  //minutes
  timeA[1] = minutes / 10;  //digit for sets of ten
  maxWrite(max7219_reg_digit1, (timeA[1]&0x0F)|0x80);
  timeA[0] = minutes - timeA[1] * 10; //digit for set of ones
  maxWrite(max7219_reg_digit0, timeA[0]&0x0F);

  //hours
  timeA[3] = hours / 10;  //digit for sets of ten
  maxWrite(max7219_reg_digit3, timeA[3]&0x0F);
  timeA[2] = hours - timeA[3] * 10; //digit for set of ones
  maxWrite(max7219_reg_digit2, timeA[2]&0x0F);
}
