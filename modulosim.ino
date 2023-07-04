#include <SoftwareSerial.h>
SoftwareSerial puertoserial(5,6);
int pin3 = 3;
int valor=0;


void sms()

{
 ///////////enviar sms////////////////
 Serial.println("Initializing...");
delay(1000);

puertoserial.println("AT"); //Once the handshake test is successful, it will back to OK
updateSerial();

puertoserial.println("AT+CMGF=1"); // Configuring TEXT mode
updateSerial();
puertoserial.println("AT+CMGS=\"+5804123240846\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
updateSerial();
puertoserial.print("prueba del modulo arduino sim 800l por gustavo"); //text content
updateSerial();
puertoserial.write(26);
Serial.print("prueba del modulo arduino sim 800l por gustavo");
}

void setup() 
{
pinMode(pin3,INPUT);  
Serial.begin(9600);
puertoserial.begin(9600);
}


void loop() 
{
valor = digitalRead(pin3);
  
if (valor==HIGH)
  {
    sms();      
  }
}

void updateSerial()
{
delay(500);
while (Serial.available())
{
puertoserial.write(Serial.read());//Forward what Serial received to Software Serial Port
}
while(puertoserial.available())
{
Serial.write(puertoserial.read());//Forward what Software Serial received to Serial Port
}
}
