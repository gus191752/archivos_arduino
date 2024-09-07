int sensor=A0;
int salida=13;
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
while (Serial.available()){
byte comando=Serial.read();
switch (comando){
case'1':
digitalWrite(salida,HIGH);
break;
case '2' :
digitalWrite(salida,LOW);
break;
}}}