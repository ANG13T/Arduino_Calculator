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
int oneDigit1 = 0;

int tenDigit2 = 0;
int oneDigit2 = 0;

void loop() {
  int firstTenState = digitalRead(firstTenDigit);
  int firstOneState = digitalRead(firstOnesDigit);
  int secondTenState = digitalRead(secondTensDigit);
  int secondOneState = digitalRead(secondOnesDigit);
  
    if(firstTenState == HIGH){
     tenDigit1 = calculate(tenDigit1);
     display(tenDigit1, 0,0);
    }

    if(firstOneState == HIGH){
     oneDigit1 = calculate(oneDigit1);
     display(oneDigit1, 1,0);
    }

    if(secondTenState == HIGH){
     tenDigit2 = calculate(tenDigit2);
     display(tenDigit2, 14,0);
    }

    if(secondOneState == HIGH){
     oneDigit2 = calculate(oneDigit2);
     display(oneDigit2, 15,0);
    }
    
}

void check(int state, int digit, int curPos1, int curPos2){
  if(state == HIGH){
     digit = calculate(digit);
     display(digit, curPos1, curPos2);
    }
}

int calculate(int digit){
      if(digit < 9){
         digit++;
      }else{
        digit = 0;
      }
    return digit;
 }

void display(int digit, int curPos1, int curPos2){
      delay(250);
      Serial.println(digit);
      lcd.setCursor(curPos1,curPos2);
      lcd.print(digit);
}
