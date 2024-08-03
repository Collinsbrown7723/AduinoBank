
#ifndef DISPLAY_H
#define DISPLAY_H
#define DIN  2 //verde
#define LOAD  1 //amarelo
#define CLK  0 //laranja

void displayinit(void);
void displayrefresh(void);
void displayWrite(uint8_t hours, uint8_t minutes);

#endif 
