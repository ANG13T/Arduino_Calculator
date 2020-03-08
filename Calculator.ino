#include <LiquidCrystal_I2C.h>
#include <Wire.h>

const int firstTenDigit = 13;
const int firstOnesDigit = 12;
const int operation = 11;
const int secondTensDigit = 10;
const int secondOnesDigit = 9;
const int enterButton = 8;

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  pinMode(firstTenDigit, INPUT);
  pinMode(firstOnesDigit, INPUT);
  pinMode(operation, INPUT);
  pinMode(secondTensDigit, INPUT);
  pinMode(secondOnesDigit, INPUT);
  pinMode(enterButton, INPUT);
    
   lcd.init(); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display } 
   lcd.backlight();
   
}

int tenDigit1 = 0;

void loop() {
  lcd.setCursor(0,0);
   lcd.print("hello");
  int firstTenState = digitalRead(firstTenDigit);
  if(firstTenState == HIGH){
    if(tenDigit1 < 9){
      tenDigit1++;
    }else{
      tenDigit1 = 0;
    }
    delay(250);
    Serial.println(tenDigit1);
  }

}
