#include <LiquidCrystal.h>

LiquidCrystal lcd(7,8,9,10,11,12);
int fN = 0;
int sN = 0;
boolean secondNum = false;
String toPrint;
char sign;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop(){}

void serialEvent(){
  while(Serial.available()){
      char check = Serial.read();

      if(check == '+' || check == '-' || check == '*' || check == '/'){
        sign = check;
        lcd.print(check);
        secondNum = true;
      }
      else if(check == 'e'){
        lcd.setCursor(0,1);
        secondNum = false;
        switch(sign){
          case '+':
            lcd.print(fN + sN);
            break;
          case '-':
            lcd.print(fN - sN);
            break;
          case '*':
            lcd.print(fN*sN);
            break;
          case '/':
            lcd.print((double)fN/sN);
            break;
        }
        fN = 0;
        sN = 0;
      }
      else if(isDigit(check)){
        if(!secondNum){
          fN = fN*10 + (check-'0');
          toPrint = fN;
          lcd.clear();
          lcd.print(toPrint);
        }
        else{
          sN = sN * 10 + (check-'0');
          toPrint = (String)fN + (String)sign + (String)sN;
          lcd.clear();
          lcd.print(toPrint);
        }
      }
    
  }

  
}

