bool anterior_a=0;
bool actual_a=0;
bool canal_b=0;
int contador=0;
bool boton=0;

void setup() {
pinMode(7,INPUT);
pinMode(8,INPUT);
Serial.begin(9600);
}

void loop() {
 actual_a=digitalRead(7);
 canal_b=digitalRead(8);
 boton= digitalRead(6);

if (anterior_a==0 && actual_a==1)
{
  if (canal_b==1)
  {contador++;
  }
  else
  {contador--;
  }
  }
anterior_a=actual_a; 
 Serial.println("contador: "+contador);
}
