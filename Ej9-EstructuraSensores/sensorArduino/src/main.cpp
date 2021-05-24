#include <Arduino.h>

struct sensor
{
    char tipo;
    int valor;
    unsigned long tiempoUltMedicion;   
} sensor1;


void setup() 
{
  Serial.begin(9600);
  int tamano = sizeof(sensor1);
  Serial.print("El tamano de la estructura es: ");
  Serial.println(tamano);
}

void loop() 
{
}