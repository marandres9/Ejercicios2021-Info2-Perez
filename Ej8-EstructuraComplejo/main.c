#include <stdio.h>

struct complejo
{
    float real;
    float imaginario;
} x;

int main()
{
    struct complejo* px = &x;
    struct complejo cx[100];

    x.real = 1.3;
    x.imaginario = -2.2;
    printf("Accediendo a los valores inciales del complejo 'x'\n");
    printf("%.2f + %.2fj\n\n", x.real, x.imaginario);

    px->real = 2;
    px->imaginario = 2;  
    printf("Modificando y accediendo a los valores de 'x' mediante puntero\n");
    printf("%.2f + %.2fj\n\n", px->real, px->imaginario);

    cx[17].real = 1;
    cx[17].imaginario = 7;
    printf("Accediendo a la posicion 18 del vector\n");
    printf("%.2f + %.2fj\n\n", cx[17].real, cx[17].imaginario);

    px = cx + 17;
    px->real = 0;
    px->imaginario = 0;
    printf("Accediendo a la posicion 18 del vector modificada mediante puntero\n");
    printf("%.2f + %.2fj\n", cx[17].real, cx[17].imaginario);

    return 0;
}