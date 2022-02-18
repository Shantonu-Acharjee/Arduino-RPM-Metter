#include <LiquidCrystal_I2C.h>       
LiquidCrystal_I2C lcd(0x3F,16,2);   
 
//Connect IR  D2 Pin

float value=0;
float rev=0;
int rpm;
int oldtime=0;        
int time;

void isr()         
{
rev++;
}

void setup()
{
lcd.init();                       
lcd.init();
lcd.backlight();
attachInterrupt(0,isr,RISING); 
}

void loop()
{
delay(1000);
detachInterrupt(0);          
time=millis()-oldtime;        
rpm=(rev/time)*60000;        
oldtime=millis();             
rev=0;
lcd.clear();
lcd.setCursor(0,0);
lcd.print("MAX ELECTRONICS BD");
lcd.setCursor(0,1);
lcd.print("RPM");
lcd.setCursor(5,1);
lcd.print(rpm);
lcd.print("   ");
attachInterrupt(0,isr,RISING);

}
