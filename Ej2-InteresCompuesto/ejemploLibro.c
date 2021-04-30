#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    float montoInicial = 1000;
    float tasaInteres = 0.05;

    int duracion = 10;

    float montoAcum;

    printf("A\244o \t MontoAcumulado\n");


    for (int i = 1; i <= duracion; i++)
    {
        montoAcum = montoInicial * pow( (1 + tasaInteres), i );
        printf("%i \t %.2f\n", i, montoAcum);
    }
 
    return 0;
}