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

int marca=0;
int modelo=0;
int down=0;
int up=0;
int right=0;
int left=0;
int select=0;

int k=0;
int l=0;
int n=0;
int p=0;
int r=0;

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
lcd.setCursor(0,0);
lcd.print("Simulador de");
lcd.setCursor(0,1);
lcd.print("Señal CKP");
delay(3000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Seleccione");
lcd.setCursor(0,1);
lcd.print("la marca");
Serial.begin(9600);
}

void loop() 
{
  lcd.setCursor(0,0);
  lcd_key= read_LCD_buttons();

  switch(lcd_key)
  {
    case btnright:
    right=1;
    break;

    case btnup:
    up=1;
    break;

    case btndown:
    down=1;
    Serial.write("down");
    lcd.print("down");
    break;

    case btnleft:
    left=1;
    break;

    case btnselect:
    select=1;
    break;
  }
delay(1000);

//do
//{ // contadores del menu
if (down==1 && l!=1 & p!=1 && r!=1)
  {
    delay(1);
    marca ++;
    Serial.print(marca);
  }
if (up==1 && l!=1 & p!=1 && r!=1)
  {
    delay(1);
    marca --;
  }
if (down==1 && k==1 & p!=1 && r!=1)
  {
    delay(1);
    modelo ++;
  }
if (up==1 && k==1 & p!=1 && r!=1)
  {
    delay(1);
    modelo --;
  }
if (marca==1 && k!=1 && n!=1 && r!=1 ) //  estructura del menu marcas
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Chevrolet  <=");
    lcd.setCursor(1, 0);
    lcd.print("Ford");
    delay(1);
  }
if (marca==2 && k!=1 && n!=1 && r!=1 ) //  estructura del menu marcas
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Ford  <=");
    lcd.setCursor(1, 0);
    lcd.print("Jeep");
    delay(1);
  }
if (marca==3 && k!=1 && n!=1 && r!=1 ) //  estructura del menu marcas
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Jeep  <=");
    lcd.setCursor(1, 0);
    lcd.print("Toyota");
    delay(1);
  }
if (marca==4 && k!=1 && n!=1 && r!=1 ) //  estructura del menu marcas
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Toyota <=");
    lcd.setCursor(1, 0);
    lcd.print("");
    delay(1);
  }

//}

//while (1);
//{
//}

}