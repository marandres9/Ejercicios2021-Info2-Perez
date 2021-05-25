#include <Arduino.h>

// 5611AH PinOut:
// A-7 B-6 C-4 D-2 E-1 F-9 G-10 DP-5
// Catodo Comun

// Conexiones al Arduino (pines digitales):
// A-2 B-3 C-4 D-5 E-6 F-7 G-8 DP-9

// Las siguietes funciones hacen lo mismo, pero estan escritas de forma distinta
void desplazarLed();
void alternarLed();

void setup() 
{
  DDRD |= B11111100;  // Pines dIO [2-7] como salida
  DDRB |= B00000011;  // Pines dIO [8-9] como salida
}

void loop() 
{
  // desplazarLed(); 
  alternarLed();
}

void desplazarLed() // Esta funcion va cambiando de puerto de salida desplazando el bit hacia la izquierda
{
  byte led;

  for (led = B00000100; led <= B10000000; led <<= 1)
  {
    PORTD = led;
    delay(500);
    if (led == B10000000) break;
  }
  PORTD = B0; // Para que no quede en estado alto el ultimo pin
  for (led = B00000001; led <= B00000010; led <<= 1)
  {
    PORTB = led;
    delay(500);
  }
  PORTB = B0; // Para que no quede en estado alto el ultimo pin
}

void alternarLed()  // Esta funcion cambia el puerto de salida cambiando la posicion del vector 'ledArray'
{
  byte ledArray[8] = {B00000100,
                      B00001000,
                      B00010000,
                      B00100000,
                      B01000000,
                      B10000000,
                      B00000001,
                      B00000010};

  for (int i = 0; i < 8; i++)
  {
    if (i < 6)
    {
      PORTD |= ledArray[i];
      delay(500);
      PORTD &= ~(ledArray[i]);  // Esta funcion prende y apaga cada pin
    }
    else
    {
      PORTB |= ledArray[i];
      delay(500);
      PORTB &= ~(ledArray[i]);
    }
  }
}