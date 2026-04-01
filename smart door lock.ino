#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myServo;
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {22, 23, 24, 25};
byte colPins[COLS] = {26, 27, 28, 29};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
String password = "0000";
String input = "";
int wrongCount = 0;
void setup()
{
  lcd.begin();
  lcd.backlight();
  pinMode(10, OUTPUT);
  pinMode(8, OUTPUT);
  PinMode(7,OUTPUT);  
  myServo.attach(9);  
  myServo.write(0);    
  lcd.setCursor(0, 0);
  lcd.print("Enter Password");
}
void loop() 
{
char key = keypad.getKey();
if (key) 
{
    if (key == '*') 
    {   
      input = "";
      lcd.clear();
      lcd.print("Cleared");
      delay(1000);
      lcd.clear();
      lcd.print("Enter Password");
    }
    else if (key == 'A') 
    {  
      if (input == password) {
      lcd.clear();
      lcd.print("Access Granted");
      digitalWrite(10, HIGH);  
      digitalWrite(8, HIGH);   
      myServo.write(90);      
      delay(2000);             
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Welcome Home");  
      delay(2000);             
      digitalWrite(10, LOW);   
      digitalWrite(8, LOW);    
      myServo.write(0);       
      wrongCount = 0;
}
      else
      {
        lcd.clear();
        lcd.print("Wrong Password");
        for (int i = 0; i < 4; i++) 
        {
          digitalWrite(8, HIGH);
          delay(300);
          digitalWrite(8, LOW);
          delay(300);
        }
        wrongCount++;
        if (wrongCount >= 3)
        {
          lcd.clear();
          lcd.print("SYSTEM LOCKED");

          for (int i = 0; i < 5; i++) 
          {
            digitalWrite(8, HIGH);
            delay(300);
            digitalWrite(8, LOW);
            delay(300);
          }
          delay(5000);
          wrongCount = 0;
        }
      }
      input = "";
      lcd.clear();
      delay(1000);
      lcd.print("Enter Password");
    }
    else 
    { 
      input += key;
      lcd.setCursor(0, 1);
      lcd.print(input);
    }
  }
}
