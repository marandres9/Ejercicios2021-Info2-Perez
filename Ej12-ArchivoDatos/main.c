#include <stdio.h>
#include <stdint.h>
// tamano del arreglo:
#define ARRSIZE 5

// modifique los nombres de las variables de la estructura para que tenga un poco mas de sentido. En este caso
// se ingresan datos de varias personas

struct datos {
    char sexo;
    uint16_t edad;
    uint32_t nroDoc;   
} arregloDatos[ARRSIZE], arregloDatos_lec[ARRSIZE];

int main()
{
    char cond = 'y';   // para checkear

    FILE* fptr;
    fptr = fopen("datos.dat", "w");
    if(fptr == NULL){
        printf("No se pudo abrir el archivo");
        return -1;
    }

    // para cada contacto... (checkear si desea cancelar)
    for (int i=0; i<ARRSIZE; i++) {
        // sexo
        printf("Ingrese el sexo: 'm' o 'f'\n");
        scanf(" %c", &arregloDatos[i].sexo);
        getchar();
        // edad
        printf("Ingrese la edad:\n");
        scanf(" %d", &arregloDatos[i].edad);
        getchar();
        // doc
        printf("Ingrese el nro de documento\n");
        scanf(" %d", &arregloDatos[i].nroDoc);

        // checkear si quiere seguir agregando
        // hacemos (ARRSIZE - 1) para evitar que pregunte si quiere agregar otro contacto cuando no queda mas lugar en el arreglo
        if (i < (ARRSIZE - 1)) {
            printf("Para ingresar otro contacto ingrese 'y'\n");
            scanf(" %c", &cond);
            if (cond != 'y') {
                break;
            }
        }
    }
    // escribir y cerrar archivo
    fwrite(arregloDatos, sizeof(struct datos), ARRSIZE, fptr);
    printf("Archivo creado\n");
    fclose(fptr);
    printf("Archivo cerrado\n\n");

    // abrir archivo
    fptr = fopen("datos.dat", "r");
    if(fptr == NULL){
        printf("No se pudo abrir el archivo");
        return -1;
    }
    else {
        printf("Abriendo archivo...\n");
    }
    // leer archivo
    fread(arregloDatos_lec, sizeof(struct datos), ARRSIZE, fptr);

    // imprimir archivo. si la variable 'sexo' de la estructura no es 'm' o 'f', entonces no contiene informacino util y no se imprime
    for (int i=0; i<ARRSIZE; i++){
        if (arregloDatos_lec[i].sexo == 'm' || arregloDatos_lec[i].sexo == 'f') {
            printf("%c\n", arregloDatos_lec[i].sexo);
            printf("%d\n", arregloDatos_lec[i].edad);
            printf("%d\n\n", arregloDatos_lec[i].nroDoc);
        }
        else {
            continue;
        }
    }
    printf("EOF");
    fclose(fptr);
    return 0;
}