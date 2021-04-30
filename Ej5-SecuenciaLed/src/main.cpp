#include <Arduino.h>

void secuenciaA();
void secuenciaB();
int check(bool *ans);

int ledA[3] = {2, 3, 4};
int ledB[3] = {2, 4, 3};

int botonA = 13;
int botonB = 12;

bool ans = 0;

void setup() 
{
  pinMode(botonA, INPUT);
  pinMode(botonB, INPUT);

  for (int i = 0; i < 3; i++)
  {
    pinMode(ledA[i], OUTPUT);

    digitalWrite(ledA[i], 0);
  }
  
}

void loop() 
{
  secuenciaA();
  secuenciaB();
}

void secuenciaA()
{  
  while(1)
  {
    for (int i = 0; i < 3; i++)
    {
      digitalWrite(ledA[i], 1);
      delay(1000);
      digitalWrite(ledA[i], 0);  
    }

    if (check(&ans) == 1)
    {
      break;
    }
  }
}

void secuenciaB()
{  
  while(1)
  {
    for (int i = 0; i < 3; i++)
    {
      digitalWrite(ledB[i], 1);
      delay(1000);
      digitalWrite(ledB[i], 0);  
    }

    if (check(&ans) == 0)
    {
      break;
    }
  }
}

int check(bool *ans)
{
  
  if (digitalRead(botonA))
  {
    *ans = 0;
    delay(100);
  }
  else if (digitalRead(botonB))
  {
    *ans = 1;
    delay(100);
  }
  return *ans;
}