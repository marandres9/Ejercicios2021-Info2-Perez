#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    float montoInicial = 1000;
    float tasaInteres[5] = {0.05, 0.06, 0.08, 0.09, 0.1};

    int duracion = 10;

    float montoAcum;

    printf("A\244o \t MontoAcumulado\n");

    for(int x = 0; x < 5; x++)
    {
        printf("---\n");
        printf("Interes: %.2f\n", tasaInteres[x]);

        for (int i = 1; i <= duracion; i++)
        {
            montoAcum = montoInicial * pow( (1 + tasaInteres[x]), i );
            printf("%i \t %.2f\n", i, montoAcum);
        }
    }
 
    return 0;
}