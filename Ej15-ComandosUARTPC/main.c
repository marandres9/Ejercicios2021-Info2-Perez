#include <stdio.h>
// #include <Windows.h>
#include "rs232.h"

// el kernel tiene una capacidad de 4096 bytes aunque como solo envia una letra 
// puedo utilizar menores tamanos
// #define LONG_BUFFER 4096
#define BUF_SIZE 512
int main() {
    int comprt = 2;
    char mode[] = {'8', 'N', '1', 0};

    char encenderLED = 'E';
    char apagarLed = 'A';

    int cantBytes;
    unsigned char recibidos[BUF_SIZE];

    if(RS232_OpenComport(comprt, 9600, mode, 0)) {
        printf("Error al abrir el puerto COM%d\n", comprt+1);
        return 0;
    }
    while (1) {
        // enviar byte y esperar 100 ms
        RS232_SendByte(comprt, encenderLED);
        Sleep(1000);
        // la funcion devuelve la cantidad de chars recibidos y se los asigna a 'recibidos'
        // lo que se recibe es el mensaje que el prog de arduino del ej 14 imprime al recibir un comando:
        // "Se recibio el comando: " + "(comando)\n" --> son 26 bytes (26 chars)
        cantBytes = RS232_PollComport(comprt, recibidos, BUF_SIZE-1);
        recibidos[cantBytes] = 0;

        printf("Se recibieron %i bytes -- %s\n", cantBytes, recibidos);   

        // se hace lo mismo que antes pero esta vez se apaga el led (comando A)
        RS232_SendByte(comprt, apagarLed);
        Sleep(1000);

        cantBytes = RS232_PollComport(comprt, recibidos, BUF_SIZE-1);
        recibidos[cantBytes] = 0;

        printf("Se recibieron %i bytes -- %s\n", cantBytes, recibidos);   
    }

    return 0;
}