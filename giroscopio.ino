
#include <MPU6050.h>
#include <Wire.h>
#include <I2Cdev.h>

int ax,ay,az;
int gx,gy,gz;
MPU6050 sensor;

void setup() {
 Serial.begin(500000);
 Wire.begin();
 sensor.initialize();
 if (sensor.testConnection())
 {//Serial.println("sensor iniciado correctamente");
  }
  else {//Serial.println("error al iniciar");
  }
 }


void loop() {
sensor.getAcceleration(&ax,&ay,&az);
sensor.getRotation(&gx,&gy,&gz);
//Serial.println("ax,ay,az,gx,gy,gz");
Serial.print(ax); 
Serial.print("\t");
Serial.print(ay); 
Serial.print("\t");
Serial.println(az); 
//Serial.print("\t");
//Serial.print(gx); 
Serial.print("\t");
//Serial.print(gy); 
Serial.print("\t");
//Serial.println(gz); 




delay(5);
}
