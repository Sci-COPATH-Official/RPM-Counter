//Infinite Xpro 
// out pin connected to the D2

#include <LiquidCrystal.h>       //i2c library file 
LiquidCrystal lcd(12, 11,10,9,8,7);    // set the LCD address to 0x27 for a 16 chars and 2 line display

float value=0;
float rev=0;
int rpm;
int oldtime=0;        
int time;

void isr()          //interrupt service routine
{
  rev++;
}

void setup()
{
  lcd.begin(16,2);
  attachInterrupt(0,isr,RISING);  //attaching the interrupt
  
  lcd.setCursor(0,0);
  lcd.print("Infinite Xpro");
  lcd.setCursor(0,1);
  lcd.print("Please Subscribe");
  delay(3000);
}

void loop()
{
  delay(1000);
  detachInterrupt(0);           //detaches the interrupt
  time=millis()-oldtime;        //finds the time 
  rpm=(rev/time)*60000;         //calculates rpm
  oldtime=millis();             //saves the current time
  rev=0;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("  Tachometer   ");
  lcd.setCursor(0,1);
  lcd.print("Speed: ");
  lcd.setCursor(6,1);
  lcd.print(rpm);
  lcd.setCursor(13,1);
  lcd.print("RPM");
  lcd.print("   ");
  attachInterrupt(0,isr,RISING);

}
