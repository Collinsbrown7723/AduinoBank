
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>


//////////////////////////////////////variable/////////////////////////////////////
String input = "";    //password                                                 //
const byte ROWS = 4;  //four rows                                                //
const byte COLS = 3;  //three columns                                            //
int count = 0;        //
String coll = "";     //
///////////////////////////////////////////////////////////////////////////////////
float current;  //
///////////////////////////////////////////////////////////////////////////////////
int relay = 2;  //
///////////////////////////////////////////////////////////////////////////////////
int threshold = 13000;  //
///////////////////////////////////////////////////////////////////////////////////

char keys[ROWS][COLS] = {
  { '1', '2', '3' },
  { '4', '5', '6' },
  { '7', '8', '9' },
  { '*', '0', '#' }
};

//////////////////////////////////////objects///////////////////////////////////////////////////////////////////

LiquidCrystal_I2C lcd(0x27, 20, 4);
byte rowPins[ROWS] = { 11, 10, 9, 8 };  //connect to the row pinouts of the keypad
byte colPins[COLS] = {
  7,
  6,
  5,
};  //connect to the column pinouts of the keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

/////////////////////////////////////functions/////////////////////////////////////////////////////////////////

String Read_key() {
  String input = "";  // Initialize the input string
                      // Initialize the password string
  char key = keypad.getKey();

  while (key != '#') {
    if (key) {
      input += key;
      Serial.println(input);
      lcd.print("*");
    }

    key = keypad.getKey();

    // Read the next key
  }
  lcd.clear();
  coll = coll + input;
  //lcd.print(coll);
  delay(1000);

  return coll;  // Return the password when '#' is pressed
}
///////////////////////////////////////////////////////////////////////////////////////
void verify() {
  lcd.print("Enter secret key");
  Read_key();
  if (coll == "100") {
    lcd.setCursor(0, 0);
    lcd.print("Access grandted");
    delay(500);
    digitalWrite(relay, HIGH);
    coll = "";
    lcd.clear();
    input = "";  // setting data back to init
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Access denied");
    // lcd.setCursor(1,0);
    //  lcd.print("two attems left");
    //  count++;
    delay(1000);
    coll = "";
    lcd.clear();
    verify();
  }
}

void setup() {
  digitalWrite(relay, HIGH);
  ////////////////////////////////////////current sensor///////////////////////////////////////////////
  pinMode(A0, INPUT);
  current = analogRead(A0);

  ////////////////////////////////////////relay///////////////////////////////////////////////////////
  pinMode(relay, OUTPUT);
  //digitalWrite(relay, LOW);  // initiate low state

  ////////////////////////////////////////lcd and serail monitor////////////////////////////////////////////////////////////
  lcd.init();
  lcd.init();
  lcd.backlight();

  Serial.begin(115200);
  delay(1000);
  lcd.clear();
  verify();
}

void loop() {
  while (current <= threshold) {
    digitalWrite(relay, LOW);
    lcd.setCursor(0, 0);
    lcd.print("current = ");
    lcd.print(current);
    lcd.print("A");
    lcd.setCursor(0, 1);
    lcd.print("System up");
    delay(500);
  }digitalWrite(relay, HIGH);

  verify();
}
