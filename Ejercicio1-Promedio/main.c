#include <stdio.h>

int main(int argc, char const *argv[])
{
    int entrada = 0;
    char chEntrada;

    int prom = 0;
    int suma = 0;
    int contador = 0;

    while(1)    //si pongo la condicion aca, va a intentar agregar el caracter 'p' a la suma
    {
        printf("Ingrese un numero ('p' para de dejar de sumar) >");
        scanf("%c", &chEntrada);
        getchar();  //evita que en el prox ciclo se escanee el caracter de 'linea nueva' en vez del numero

        if(chEntrada == 'p')
        {
            printf("---\n");
            break;
        }

        entrada = (int) chEntrada - 48;     //el valor ascii de '0' es 48

        suma += entrada;     //acumula las entradas del usuario
        contador++;     
    }
    
    prom = suma / contador;
    printf("El promedio de los numeros ingresados es: %i", prom);

    return 0;
}