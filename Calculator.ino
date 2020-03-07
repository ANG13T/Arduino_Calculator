
const int firstTenDigit = 13;
const int firstOnesDigit = 12;
const int operation = 11;
const int secondTensDigit = 10;
const int secondOnesDigit = 9;
const int enterButton = 8;

void setup() {
  Serial.begin(9600);
  pinMode(firstTenDigit, INPUT);
  pinMode(firstOnesDigit, INPUT);
  pinMode(operation, INPUT);
  pinMode(secondTensDigit, INPUT);
  pinMode(secondOnesDigit, INPUT);
  pinMode(enterButton, INPUT);
}

int tenDigit1 = 0;

void loop() {
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
