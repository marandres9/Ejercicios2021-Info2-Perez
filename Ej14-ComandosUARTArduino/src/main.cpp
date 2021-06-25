#include <Arduino.h>

String serialInput;
int pinLED = 13;

void setup() {
  // iniciar puerto serie
  Serial.begin(9600);
  while(!Serial);

  // Serial.setTimeout(2000); // si no especificamos el timeout usa el valor por defecto (1000 ms)
                              // significa que si no ingresamos un dato nuevo en 1 seg deja de aceptar y devuelve
                              // el string ingresado hasta el momento
  pinMode(pinLED, OUTPUT);  
}

void loop() {
  if (Serial.available()) {
    serialInput = Serial.readString(); 
    if (serialInput == "E") {
      digitalWrite(pinLED, 1);
    }
    else if (serialInput == "A") {
      digitalWrite(pinLED, 0);
    }
    Serial.print("Se recibio el comando: ");
    Serial.println(serialInput);
  }
}