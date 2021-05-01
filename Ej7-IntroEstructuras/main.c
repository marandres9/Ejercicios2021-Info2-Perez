#include <stdio.h>

struct cliente
{
    char apellido[15];
    char nombre[15];
    int numeroCliente;
    
    struct
    {
        char numeroTelefonico[11];
        char direccion[50];
        char ciudad[15];
        char estado[3];
        char codigoPostal[6];
    } personal;
} registroCliente, *ptrCliente;

int main()
{
    ptrCliente = &registroCliente;

//  apartado A
    printf("Ingrese el apellido del cliente: >");
    scanf("%s", &registroCliente.apellido);
    printf("El apellido del cliente es: %s\n\n", registroCliente.apellido);

//  apartado B
    printf("Ingrese el apellido del cliente: >");
    scanf("%s", (*ptrCliente).apellido);
    printf("El apellido del cliente es: %s\n\n", ptrCliente->apellido);

//  apartado C
    printf("Ingrese el nombre del cliente: >");
    scanf("%s", &registroCliente.nombre);
    printf("El nombre del cliente es: %s\n\n", registroCliente.nombre);

//  apartado D
    printf("Ingrese el nombre del cliente: >");
    scanf("%s", ptrCliente->nombre);
    printf("El nombre del cliente es: %s\n\n", ptrCliente->nombre);

//  apartado E
    printf("Ingrese el numero del cliente: >");
    scanf("%i", &registroCliente.numeroCliente);
    printf("El numero del cliente es: %d\n\n", registroCliente.numeroCliente);  

//  apartado F
    printf("Ingrese el numero del cliente: >");
    scanf("%i", &(ptrCliente->numeroCliente));
    printf("El numero del cliente es: %i\n\n", ptrCliente->numeroCliente);

//  apartado G
    printf("Ingrese el numero telefonico del cliente: >");
    scanf("%s", ptrCliente->personal.numeroTelefonico);
    printf("El numero telefonico del cliente es: %s\n\n", ptrCliente->personal.numeroTelefonico);

    return 0;
}