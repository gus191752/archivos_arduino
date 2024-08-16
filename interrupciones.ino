int contador = 0;
int n = contador ;

void setup()
   {   Serial.begin(9600);
       attachInterrupt( 0, ServicioBoton, FALLING);
   }
void loop()
   {   if (n != contador)
          {     Serial.println(contador);
                n = contador ;
          }

       if (contador>100)
             {
             contador=0;
             }
   }

void ServicioBoton() 
   {    contador++ ;
   }
