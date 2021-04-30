<<<<<<< HEAD
#include <Arduino.h>

int red = 11;
int green = 10; 
int blue = 9; 

int potR = A0; 
int potG = A1; 
int potB = A2; 

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
}