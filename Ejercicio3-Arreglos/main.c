#include <stdio.h>
#include <stdlib.h>

void apartadoA();
void apartadoB();
void apartadoC();
void apartadoD();
void apartadoE();

int main(int argc, char const *argv[])
{
    char apartados[5] = {"ABCDE"};
    int opcion = 0;

    while(1)
    {
        printf("Ingrese una opcion: \n");
        for (int i = 0; i < 5; i++)
        {
            printf("Opcion %d -> Apartado %c\n", i+1, apartados[i]);
        }
        printf(">");
        scanf("%d", &opcion);
        if (opcion > 0 && opcion < 6)
        {
            break;
        }
    }
    
    switch (opcion)
    {
    case 1:
        printf("Selecciono el apartado A:\n");
        apartadoA();
        break;
    case 2:
        printf("Selecciono el apartado B:\n");
        apartadoB();
        break;
    case 3:
        printf("Selecciono el apartado C:\n");
        apartadoC();
        break;
    case 4:
        printf("Selecciono el apartado D:\n");
        apartadoD();
        break;
    case 5:
        printf("Selecciono el apartado E:\n");
        apartadoE();
        break;
    }
    
    return 0;
}

//FUNCIONES

void apartadoA()
{
    char f[10] = {'1', '2', '9', '5', '4', 'a', 'S', 'o', 'n', '0'};

    printf("El septimo elemento del arreglo f = {'1', '2', '9', '5', '4', 'a', 's', 'o', 'n', '0'} es:\n>%c", f[6]);

}
void apartadoB()
{
float b[4] = {0};
    
    printf("Introduzca el valor del 4to elemento del arreglo tipo float 'b'\n");

    scanf("%f", &b[3]);

    //para verificar
    printf("El valor del 4to elemento del arreglo 'b' es: \n>%.3f", b[3]);

}
void apartadoC()
{
    int g[5];

    for (int i = 0; i < 5; i++)
    {
        g[i] = 8;
    }
    printf("A continuacion se muestran los valores del arreglo 'g[5]':\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d \t", g[i]);
    }
    
}
void apartadoD()
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
        printf("Para imprimir solo la suma de los 100 elemtos del arreglo ingrese '1', si tambien quiere imprimir los valores de cada elemtno ingrese '2'\n");
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

}
void apartadoE()
{
    double a[11] = {0};
    double b[34] = {0};

    for (int i = 0; i < 11; i++)
    {
        a[i] = rand();

        b[i] = a[i];
    }
    
    printf("Pos\ta[11]\tb[34]\n");

    for (int i = 0; i < 34; i++)
    {
        if(i >= 11)
        {
            printf("%d\t--\t%.1lf\n", i, b[i]);
            continue;
        }
        printf("%d\t%.1lf\t%.1lf\n", i, a[i], b[i]);
    }

}
