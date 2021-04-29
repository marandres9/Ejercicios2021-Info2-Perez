#include <Arduino.h>

int led[4] = {11, 10, 9, 6};
// int entradaTemp = A0;

int lectura;

int selector = 0;

void setup() 
{
  for(int i = 0; i < 4; i++)
  {
    pinMode(led[i], OUTPUT);
  }
}

void loop() 
{
  lectura = analogRead(A0);

  selector = lectura / 256;

  switch (selector)
  {
  case 4:
    analogWrite(led[4], (lectura/4));
    break;
  case 1:
    break;
  }
}