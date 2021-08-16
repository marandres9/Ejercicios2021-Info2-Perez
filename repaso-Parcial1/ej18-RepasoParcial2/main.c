#include <stdio.h>
#include <stdlib.h>

const int nroPersonas = 2;
char nombreArchivo[9] = "datos.dat";

struct Datos {
    char nombre[20];
    int edad;
    int dni;
    int telefono;
} *personas, *personasLec;

void guardarDatos();
void leerDatos();
void selecPersona();
int esMayor(struct Datos* persona);

int main() {
    guardarDatos();
    selecPersona();

    return 0;
}

void guardarDatos() { 
    FILE* fptr;
    personas = calloc(nroPersonas, sizeof(struct Datos));

    for(int i=0; i<nroPersonas; i++) {
        printf("Ingresar:\n\tNombre\n\tEdad\n\tDNI\n\tTelefono\n");
        scanf("%s", personas[i].nombre);
        scanf("%d", &personas[i].edad);
        scanf("%d", &personas[i].dni);
        scanf("%d", &personas[i].telefono);
    }

    fptr = fopen(nombreArchivo, "wb");
    fwrite(personas, sizeof(struct Datos), nroPersonas, fptr);
    fclose(fptr);

    free(personas);
}
void leerDatos() {
    FILE* fptr;
    personasLec = calloc(nroPersonas, sizeof(struct Datos));

    fptr= fopen(nombreArchivo, "rb");
    fread(personasLec, sizeof(struct Datos), nroPersonas, fptr);
    fclose(fptr);
}
void selecPersona() {
    int seleccion;

    leerDatos();

    printf("Ingresar un numero 1-%d", nroPersonas);
    scanf("%d", &seleccion);

    printf("Nombre: %s\n", personasLec[seleccion].nombre);
    printf("Edad: %d\n", personasLec[seleccion].edad);
    printf("DNI: %d\n", personasLec[seleccion].dni);
    printf("Telefono: %d\n", personasLec[seleccion].telefono);

    // prueba funcion esMayor()
    // printf("%d\n", esMayor(personasLec+1));

    free(personasLec);
}
int esMayor(struct Datos* persona) {    // devuelve 1 si es mayor, sino 0
    int x;

    x = persona->edad >= 18 ? 1 : 0;

    return x;
}