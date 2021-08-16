#include <stdio.h>
#include <stdlib.h>

struct Prod {
    char desc[20];
    int codigo;
    float precio;
} *lista, *listaLec;

void agProd(FILE* fptr, int* n) {
    // var para mostrar elementos escritos
    int escritos;
    // incrementar nro de prod
    (*n)++;
    // asignar un bloque mas de mem
    lista = malloc(sizeof(struct Prod));

    printf("Ingresar prod %d: \n\tdescripcion\n\tcodigo\n\tprecio\n", (*n+1));
    scanf("%s", (*lista).desc);
    scanf("%d", &(*lista).codigo);
    scanf("%f", &(*lista).precio);

    fptr = fopen("archivos.dat", "ab");
    escritos = fwrite(lista, sizeof(struct Prod), 1, fptr);
    fclose(fptr);
    printf("%d elementos escritos\n", escritos);

    free(lista);
};
void leerLista(FILE* fptr, int* n) {
    // var para mostrar elementos escritos
    int leidos;
    fptr = fopen("archivos.dat", "rb");
    // asignar memoria a la estructura de lectura
    listaLec = calloc((*n)+1, sizeof(struct Prod));

    leidos = fread(listaLec, sizeof(struct Prod), (*n)+1, fptr);
    printf("%d elementos leidos\n", leidos);
};
void mostrarProd(FILE* fptr, int* n) {
    // leer la lista
    leerLista(fptr, n);
    // mostrar leidos
    printf("Descripcion\t\tCodigo\t\tPrecio\n");
    for(int i=0; i<=*n; i++) {
        printf("%s\t\t%d\t\t%f\n", listaLec[i].desc, listaLec[i].codigo, listaLec[i].precio);
    }
    // liberar mem
    free(listaLec);
}
void buscarProd(FILE* fptr, int* n) { 
    int codigo;
    int success = 0;
    // leer la lista
    leerLista(fptr, n);

    printf("Ingresar codigo:\n");
    scanf("%d", &codigo);
    
    // comparar con la lista
    for(int i=0; i<=*n; i++) {
        if(codigo == listaLec[i].codigo) {
            printf("Producto encontrado, precio: %f\n", listaLec[i].precio);
            success = 1;
            break;
        }
    }
    if(success == 0) {
        printf("no se encontro el producto\n");
    }
    free(listaLec);
}

int main() {
    // puntero para el archivo
    FILE* fptr;

    // variable que contiene el num de productos
    int numeroProd=0;

    lista = (struct Prod*) malloc(sizeof(struct Prod));
    
    // Ingresar datos
    printf("Ingresar prod %d: \n\tdescripcion\n\tcodigo\n\tprecio\n", numeroProd+1);
    scanf("%s", (lista[numeroProd].desc));
    scanf("%d", &(lista[numeroProd].codigo));
    scanf("%f", &(lista[numeroProd].precio));

    // check
    // printf("%s - %d - %f", lista[0].desc, lista[0].codigo, lista[0].precio);

    // abrir archivo y escribir
    fptr = fopen("archivos.dat", "wb");
    fwrite(lista, sizeof(struct Prod), numeroProd+1, fptr);
    fclose(fptr);
    free(lista);

    agProd(fptr, &numeroProd);
    mostrarProd(fptr, &numeroProd);
    buscarProd(fptr, &numeroProd);

    return 0;
}