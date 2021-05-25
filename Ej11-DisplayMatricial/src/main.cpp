#include <Arduino.h>

void desplazarLed();

void setup() 
{
  DDRD |= B11111100;
  DDRB |= B00111111;
  DDRC |= B00001111;
}

// Columnas dIO [2-9] 
// Filas dIO [10-13], aIO [0-3]

void loop() 
{
  desplazarLed();
}

void desplazarLed()
{
  byte ledFila[8] = {B00000100, // Las filas [1-4] se encuentran en PORTB
                    B00001000,
                    B00010000,
                    B00100000,
                    B00000001,  // Las filas [5-8] se encuentran en PORTC
                    B00000010,
                    B00000100,
                    B00001000};
  byte ledCol;
  bool fila4; // Se usa para indicar si se usan las filas conectadas en PORTB o PORTC

  PORTD |= B11111100;
  PORTB |= B00000011; // me aseguro que todas las columnas este en apagadas

  for (int i=0; i<8; i++) // Las filas se controlan usando un vector con el pin  de cada fila
  {
    if (i < 4)
    {
      PORTB |= ledFila[i];
      fila4 = 1;
    }
    else
    {
      PORTC |= ledFila[i];
      fila4 = 0;
    }

    for (ledCol = B00000100; ledCol <= B10000000; ledCol <<= 1) // Las columnas se controlan desplazando el bit que la controla
    {
      PORTD &= ~ledCol;
      delay(100);
      PORTD |= ledCol;  // Prende y apaga la columna por 0.5s
      if (ledCol == B10000000) break; // Si no lo fuerzo a salir del for() usando break una vez que llega al ultimo bit nunca sale
    }
    for (ledCol = B00000001; ledCol <= B00000010; ledCol <<= 1) // Necesito 2 for() porque los pines de columnas estan en PORTD y PORTB
    {
      PORTB &= ~ledCol;
      delay(100);
      PORTB |= ledCol; 
    }
    
    fila4 == 1 ? PORTB &= ~ledFila[i] : PORTC &= ~ledFila[i]; // Controla la fila que hay que apagar
  }
}