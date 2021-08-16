#include <stdio.h>
#include <stdlib.h>

struct Mediciones {
    int hum_viento_temp[3];
} *med;

char nombreArchivo[] = "mediciones.dat";
const int nroMediciones = 4;
int entradaSensores[4][3] = { {30, 2, 30}, {7, 15, 15}, {1, 2, 3}, {4, 3, 31} };

void escribirMediciones();
void leerMediciones();
void mostrarMediciones();
void estadisticasMediciones();

int main() {
    escribirMediciones();
    mostrarMediciones();
    estadisticasMediciones();
    return 0;
}

void escribirMediciones() {
    FILE* fptr;

    med = calloc(nroMediciones, sizeof(struct Mediciones));

    for(int i=0; i<nroMediciones; i++) {
        for(int j=0; j<3; j++) {
            med[i].hum_viento_temp[j] = entradaSensores[i][j];
        }
    }

    fptr = fopen(nombreArchivo, "wb");
    fwrite(med, sizeof(struct Mediciones), nroMediciones, fptr);
    fclose(fptr);
    
    free(med);
}
void leerMediciones() {
    FILE* fptr;

    med = calloc(nroMediciones, sizeof(struct Mediciones));

    fptr = fopen(nombreArchivo, "rb");
    fread(med, sizeof(struct Mediciones), nroMediciones, fptr);
    fclose(fptr);
}
void mostrarMediciones() {
    leerMediciones();

    printf("Humedad(\%)\tVelocidadViento(km/h)\tTemp(°C)\n");
    for(int i=0; i<nroMediciones; i++) {
        printf("%d\t\t%d\t\t\t%d\n", (med+i)->hum_viento_temp[0], (med+i)->hum_viento_temp[1], med[i].hum_viento_temp[2]);
    }
    free(med);
}
void estadisticasMediciones() {
    leerMediciones();

    int promHumedad;
    int tempMax = 0;

    float sumaHum=0;
    
    leerMediciones();

    for(int i=0; i<nroMediciones; i++) {
        sumaHum += med[i].hum_viento_temp[0];
    }
    printf("Promedio de humedad: %f\n", sumaHum/nroMediciones);

    for (int i = 0; i < nroMediciones; i++) {
        tempMax = med[i].hum_viento_temp[2] > tempMax ? med[i].hum_viento_temp[2] : tempMax;
    }
    printf("Temperatura maxima: %d\n", tempMax);
    
}