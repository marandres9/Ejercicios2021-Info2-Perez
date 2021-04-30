#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    float c[100];
    double suma = 0;

    int opcion = 0;

    for (int i = 0; i < 100; i++)
    {
        c[i] = rand();

        suma += c[i];
    }

    while (1)
    {
        printf("Para imprimir solo la suma de los 100 elemtos del arreglo ingrese '1', si tambien quiere\n");
        printf("imprimir los valores de cada elemtno ingrese '2'\n >");
        scanf("%d", &opcion);

        if (opcion == 1)
            {
                printf("--->suma: %.2lf", suma);
                break;
            }
        else if (opcion == 2)
        {
            for (int i = 0; i < 100; i++) 
            {
                printf("%.2f\n", c[i]);
            }
            printf("-->suma: %.2lf", suma);
            break;
        }    
    }

    return 0;
}