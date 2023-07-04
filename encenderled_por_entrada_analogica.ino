
int sensor=A0;
int salida=31;
int dato= 0;



void setup(){
pinMode(salida,OUTPUT);
Serial.begin(9600);
}
void loop() {
dato=analogRead(sensor);
millis();
delay(1000);
Serial.println(dato);
Serial.println('#');

if (dato >= 600) {

digitalWrite(salida,HIGH);}
if (dato < 600) {
digitalWrite(salida,LOW);}}
