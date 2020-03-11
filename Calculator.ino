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

   lcd.setCursor(0,0);
   lcd.print(0);
   lcd.setCursor(1,0);
   lcd.print(0);
   lcd.setCursor(7,0);
   lcd.print("+");
   lcd.setCursor(14,0);
   lcd.print(0);
   lcd.setCursor(15,0);
   lcd.print(0);

   lcd.setCursor(4,1);
   lcd.print("=");
   
}

int tenDigit1 = 0;
int oneDigit1 = 0;

int tenDigit2 = 0;
int oneDigit2 = 0;

int operatorDigit = 0;
String operatorString = "+";

void loop() {
  int firstTenState = digitalRead(firstTenDigit);
  int firstOneState = digitalRead(firstOnesDigit);
  int secondTenState = digitalRead(secondTensDigit);
  int secondOneState = digitalRead(secondOnesDigit);
  int operatorState = digitalRead(operation);
  int enterState = digitalRead(enterButton);
  
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
    
    if(operatorState == HIGH){
      delay(250);
      operatorDigit = determineOperator(operatorDigit);
      if(operatorDigit == 0){
        operatorString = "+";
      }
      if(operatorDigit == 1){
        operatorString = "-";
      }
      if(operatorDigit == 2){
        operatorString = "*";
      }
      if(operatorDigit == 3){
        operatorString = "/";
      }
      Serial.println(operatorString);
      lcd.setCursor(7,0);
      lcd.print(operatorString);
        Serial.println("boom");
    }

    if(enterState == HIGH){
      delay(250);
      Serial.println("boom");
      double total = calculateNumber(tenDigit1, oneDigit1, tenDigit2, oneDigit2, operatorString);
      Serial.println("calculated number is: ");
      Serial.println(total);
      lcd.setCursor(6,1);
      lcd.print(total);
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

int determineOperator(int operation){
  if(operation < 4){
         operation++;
      }else{
        operation = 0;
    }
    return operation;
}

void display(int digit, int curPos1, int curPos2){
      delay(250);
      Serial.println(digit);
      lcd.setCursor(curPos1,curPos2);
      lcd.print(digit);
}

double calculateNumber(int tenDigit1, int oneDigit1, int tenDigit2, int oneDigit2, String operation){
  double t1 = tenDigit1 * 10;
  double t2 = tenDigit2 * 10;
  double firstNum = t1 + oneDigit1;
  double secNum = t2 + oneDigit2;
  if(operation == "+"){
    return (firstNum + secNum);
  }

  if(operation == "-"){
    return (firstNum - secNum);
  }

  if(operation == "/"){
    return (firstNum / secNum);
  }

  if(operation == "*"){
    return (firstNum * secNum);
  }
}
