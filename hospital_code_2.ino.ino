#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
int seconds = 0;
LiquidCrystal_I2C lcd(0x27,20,4); 
#include <Keypad.h>

///////////////////////////////////////variable////////////////////////////////////////////////////////////////
String input = "";    //password
const byte ROWS = 4;  //four rows
const byte COLS = 4;  //three columns
String coll = "";     //collected password stores here
int count = 0;
int  collInt;
int relay1 = 1;
int relay2 = 2;
int relay3 = 3; 
//*************************************************************************************************************


////////////////////////////////////////objects////////////////////////////////////////////////////////////////

char keys[ROWS][COLS] = {
  { '1', '2', '3',  },
  { '4', '5', '6', },
  { '7', '8', '9', },
  { '*', '0', '#', }
};


byte rowPins[ROWS] = { 11, 10, 9, 8 };  //connect to the row pinouts of the keypad
byte colPins[COLS] = { 7, 6, 5,};    //connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);


//*************************************************************************************************************



////////////////////////////////////////objects////////////////////////////////////////////////////////////////

//*************************************************************************************************************


////////////////////////////////////////global fuctions////////////////////////////////////////////////////////////////

//*************************************************************************************************************

String Read_key() {
  String input = "";  // Initialize the input string
                      // Initialize the password string
  char key = keypad.getKey();

  while (key != '#') {
    if (key) {
      input += key;
      Serial.println(input);
      lcd.print(input);
    }

    key = keypad.getKey();

    // Read the next key
  }
  lcd.clear();
  coll = coll + input;
  lcd.print(coll);
  delay(1000);
  if (count == 0){
  verify();
  }
  else if(count ==1) {
   //collInt = coll.toInt(); 
 	file_selection();
  }
  // Store the entered values in the password variable

  return coll;  // Return the password when '#' is pressed
}





void setup() {
    lcd.init();                      // initialize the lcd 
  lcd.init();
   lcd.backlight();
  Serial.begin(115200);
  pinMode(relay1,OUTPUT);
    pinMode(relay2,OUTPUT);
      pinMode(relay3,OUTPUT);
  lcd.print("hellow word");
  delay(1000);
  lcd.clear();
  //user promt for authentication
  Serial.println("welcome 'Enter password'");
  lcd.print("welcome 'Enter password'");
  delay(1000);
  lcd.clear();
}

void loop() {
  Read_key();
}

void verify() {
  if (coll == "100") {
    // Grant access
    Serial.println("Access granted");
    lcd.print("Access granted");
    delay(1000);
    count++;
    coll = "";
    lcd.clear();
  lcd.print("Enter File numbers");
  delay(500);
    lcd.clear();
  

  } 
  else {
    // Print error
    Serial.println("Wrong password, try again");
    lcd.print("Wrong password, try again");
    delay(1000);
    coll = "";
    lcd.clear();
  }
}


void file_selection() {
  switch (coll.toInt()) {
    //////////////////////box one////////////////////////////
    case 1:
      // box 1 led 1
      lcd.print("actuator ");
      Serial.print("actuator ");
      digitalWrite(relay1,HIGH);
      break;

    case 2:
      // box 1 led 2
      digitalWrite(relay1,HIGH);
      break;

    case 3:
      // box 1 led 3
      digitalWrite(relay1,HIGH);
      break;

    case 4:
      // box 1 led 4
      digitalWrite(relay1,HIGH);
      break;

    case 5:
    digitalWrite(relay1,HIGH);
      // box 1 led 5
      break;

    //////////////////////////box two(2)
    case 6:
    digitalWrite(relay2,HIGH);
      // box 2 led 1
      break;

    case 7:
      // box 2 led 2
          digitalWrite(relay2,HIGH);
      break;

    case 8:
      // box 2 led 3
          digitalWrite(relay2,HIGH);
      break;

    case 9:
      // box 2 led 4
          digitalWrite(relay2,HIGH);
      break;

    case 10:
      // box 2 led 5
          digitalWrite(relay2,HIGH);
      break;

    //////////////////////////box three(3)
    case 11:
      // box 3 led 1
          digitalWrite(relay3,HIGH);
      break;

    case 12:
      // box 3 led 2
         digitalWrite(relay3,HIGH);
      break;

    case 13:
      // box 3 led 3
         digitalWrite(relay3,HIGH);
      break;

    case 14:
      // box 3 led 4
         digitalWrite(relay3,HIGH);
      break;

    case 15:
      // box 3 led 5
         digitalWrite(relay3,HIGH);
      break;
  }
}
