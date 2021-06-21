#include <stdio.h>
#include <stdint.h>
// tamano del arreglo:
#define ARRSIZE 3


struct datos {
    char sexo;
    uint16_t edad;
    uint32_t nroDoc;   
};

int main()
{
    struct datos arregloDatos[ARRSIZE];
    char cond = 'y';   // para checkear

    // FILE* fptr;
    // fptr = fopen("test.dat", "w+");

    // inicializar cada estuctura a un valor por defecto de 'sexo'
    // for (int i = 0; i<ARRSIZE; i++) {
    //     arregloDatos[i].sexo = 'x';
    // }

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

        if (i < (ARRSIZE - 1)) {
            // checkear si quiere seguir agregando
            printf("Para ingresar otro contacto ingrese 'y'\n");
            scanf(" %c", &cond);
            getchar();

            if (cond != 'y') {
                break;
            }
        }
       
    }

    for (int i=0; i<ARRSIZE; i++){
        printf("%c\n", arregloDatos[i].sexo);
        printf("%d\n", arregloDatos[i].edad);
        printf("%d\n", arregloDatos[i].nroDoc);
    }


    return 0;
}