#include <stdio.h>
#include <stdint.h>

struct sensor
{
    char tipo;
    int valor;
    unsigned long tiempoUltMedicion;   
} sensor1;

int main()
{
    printf("El tamano de la estructura es: %d\n", sizeof(sensor1));
    
    return 0;
}