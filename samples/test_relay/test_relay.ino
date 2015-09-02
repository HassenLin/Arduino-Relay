#include <Relay.h>
#include <PushButton.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x3F for a 20 chars and 4

int motorPin = 11;
int Down_Pin = 7;
int Up_Pin = 8;
int MotorDergee = 90;

#define Relay1Pin 4
#define Relay2Pin 2

Relay relay1(Relay1Pin),relay2(Relay2Pin);
PushButton Up(Up_Pin),Down(Down_Pin);

void setup() {

  lcd.begin();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(3, 0);
  lcd.print("Hello, world!");
  lcd.setCursor(2, 1);
  lcd.print("Hello  Arduino!");
  lcd.setCursor(2, 3);
  lcd.print("By Hassen!");
}

void ShowStatus()
{
  String s;
  if(relay1.m_Level == HIGH)
    s =  "Relay 1:On";
   else
    s =  "Relay 1:Off";
  if(relay2.m_Level == HIGH)
    s +=  " 2:On";
   else
    s +=  " 2:Off";
  lcd.setCursor(0, 2);
  lcd.print("                    ");
  lcd.setCursor(0, 2);
  lcd.print(s);

}
void loop() {
  if (Up.isHit())
  {
    if(relay1.m_Level == HIGH)
      relay1.SetLevel(LOW);
    else  
      relay1.SetLevel(HIGH);
    ShowStatus();
    delay(500);
  }
  if (Down.isHit())
  {
    if(relay2.m_Level == HIGH)
      relay2.SetLevel(LOW);
    else  
      relay2.SetLevel(HIGH);
    ShowStatus();
    delay(500);
  }

  delay(10);

}
