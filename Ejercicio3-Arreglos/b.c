#include <stdio.h>

int main(int argc, char const *argv[])
{
    float b[4] = {0};
    
    printf("Introduzca el valor del 4to elemento del arreglo tipo float 'b'\n");

    scanf("%f", &b[3]);

    //para verificar
    printf("El valor del 4to elemento del arreglo 'b' es: \n>%.2f", b[3]);

    return 0;
}