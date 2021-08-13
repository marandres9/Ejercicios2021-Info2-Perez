#include <Arduino.h>

volatile bool sube = 1;
volatile unsigned long t;
int contador=0;
int t_delay = 500;
int control=0;

void interr_sin_rebotes() {
    if(millis() > (t + 100)) {
        // invertir estado
        sube = !sube;
        control++;
        Serial.println(control);
        t = millis();
    }
}

const int nLeds = 3;
int ledArr[nLeds] = {8, 9, 10};

void setup() {
    Serial.begin(9600);

    pinMode(2, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(2), interr_sin_rebotes, RISING);
    // uso RISING para que cambie cuando suelto el boton, da un control mas precio

    for (int i = 0; i < nLeds; i++)
    {
        pinMode(ledArr[i], OUTPUT);

        digitalWrite(ledArr[i], 0);
    }
}

void loop() {
    digitalWrite(ledArr[contador], 1);
    delay(t_delay);
    digitalWrite(ledArr[contador], 0);
    if(sube == 1) {
        contador++;
        if(contador >= nLeds) {
            contador = 0;
        }
    }
    else {
        contador--;
        if(contador < 0) {
            contador = nLeds-1;
        }
    }
}
