#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,4,5,6,7);

int lcd_key=0;
int adc_key_in=0;

#define btnright 0
#define btnup 1
#define btndown 2
#define btnleft 3
#define btnselect 4
#define btnnone 5

int read_LCD_buttons()
{
  adc_key_in = analogRead(0);
  if (adc_key_in < 50) return btnright;
  if (adc_key_in < 195) return btnup;
  if (adc_key_in < 380) return btndown;
  if (adc_key_in < 555) return btnleft;
  if (adc_key_in < 790) return btnselect;
  if (adc_key_in > 1000) return btnnone; 
  return btnnone;
}

void setup() 
{ 
lcd.begin(16,2);
lcd.setCursor(0,1);
lcd.print("iniciando...");
delay(1000);
lcd.clear()
Serial.begin(9600);
}

void loop() 
{
  lcd.setCursor(0,1);
  lcd_key= read_LCD_buttons();

  switch(lcd_key)
  {
    case btnright:
    lcd.print("right");
    Serial.write("right");
    delay(1000);
    break;
    
    case btnup:
    lcd.print("up");
    Serial.write("up");
    break;
    
    case btndown:
    lcd.print("down");
    Serial.write("down");
    break;
    
    case btnleft:
    lcd.print("left");
    Serial.write("left");
    break;
    
    case btnselect:
    lcd.print("select");
    Serial.write("select");
    break;
     
  }

delay(1000);



}
