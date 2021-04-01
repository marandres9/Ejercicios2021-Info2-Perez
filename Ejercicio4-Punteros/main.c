#include <stdio.h>

int main(int argc, char const *argv[])
{
    long int valor1 = 200000;
    long int valor2;

    // a)
    long *ptrL;

    // b)
    ptrL = &valor1;

    // c)
    printf("%li\n", *ptrL);

    // d)
    valor2 = *ptrL;

    // e)
    printf("%li\n", valor2);

    // f)
    printf("%X\n", &valor1);

    // g)
    printf("%X\n", ptrL);
    /* es el mismo valor que imprimio el apartado f
    ya que la variable ptrL apunta a la direccion 
    donde esta almacenado el valor de la variable valor1*/

    return 0;
}