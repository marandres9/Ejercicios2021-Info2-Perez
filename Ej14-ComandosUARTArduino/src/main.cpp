#include <Arduino.h>

String serialInput;
int pinLED = 13;

void setup() {
  // iniciar puerto serie
  Serial.begin(9600);
  while(!Serial);

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