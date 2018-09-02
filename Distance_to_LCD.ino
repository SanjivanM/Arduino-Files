//set up for LCD
#include <LiquidCrystal.h>
int tempPin = 0;
//                BS  E  D4 D5  D6 D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

//Ultrasonic setup
#include <SR04.h>
#define TRIG_PIN 4
//REGULAR

#define ECHO_PIN 5
//PWM

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);//set up Ultrasonic pins
long a;
//declare a as a 'long' var type

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  //set up serial IO to 9600 baud
  lcd.begin(16, 2);
  //.........================
  lcd.setCursor(0,0);
  lcd.print("  Sensor Ready  ");
  delay(1000);
  lcd.begin(16,2);
  lcd.setCursor(0,1);
  lcd.print("centimeters.");

}

void loop()
{
  // put your main code here, to run repeatedly:
  a=sr04.Distance();
  //read dist to 'a'

  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,0);
  lcd.print(a);

  
}
