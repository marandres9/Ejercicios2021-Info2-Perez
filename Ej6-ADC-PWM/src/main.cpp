<<<<<<< HEAD
#include <Arduino.h>

int red = 11;
int green = 10; 
int blue = 9; 

int potR = A0; 
int potG = A1; 
int potB = A2; 

float conversion = 255/1023;

void setup()
{
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
    
  pinMode(potR, INPUT);
  pinMode(potG, INPUT);
  pinMode(potB, INPUT);
}

void loop()
{
  analogWrite(red, (255./1023.) * analogRead(potR)); 
  analogWrite(green, (255./1023.) * analogRead(potG)); 
  analogWrite(blue, (255./1023.) * analogRead(potB)); 
=======
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
>>>>>>> 369ab2f50ff1eb3bd12d265b62c60fb16908bd26
}