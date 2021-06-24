#include <Arduino.h>
// SD
//  ** MOSI - pin 11
//  ** MISO - pin 12
//  ** CLK - pin 13
//  ** CS - pin 10
#include <SD.h>
#include <SPI.h>

// prototipos de funciones:
void escribirEstructura();
void leerEstructura();

// SD
const int chipSelect = 10;
File myFile;
const char *nombreArchivo = "test.dat";

struct sensor {
    uint32_t tiempoUltMedicion;   
    uint16_t valor;
    char tipo;
} datos, datos_lec;

void setup() {
  datos.tipo = 'x';
  datos.valor = 100;
  datos.tiempoUltMedicion = 1000;
  
  // iniciar monitor
  Serial.begin(9600);
  while (!Serial);

  // SD
  Serial.println("Iniciando SD...");
  if (!SD.begin(chipSelect)) {
    Serial.println("Error al incializar!");
    while (1);
  }
  Serial.println("SD inicializada!");

  // escribir estructura
  escribirEstructura();
  // leer estructura
  leerEstructura();
}

void loop() {

}

void escribirEstructura() {
  // abrir archivo
  myFile = SD.open(nombreArchivo, FILE_WRITE);
  
  if (myFile) {  
    Serial.print(myFile.name());
    Serial.println(" abierto para escritura");
    Serial.println("");

    // escribir estructura
    myFile.write((const uint8_t*) &datos, sizeof(datos));
  }
  else {
    Serial.println("error al abrir el archivo");
  }
  // cerrar archivo
  myFile.close();

  Serial.print("Archivo cerrado: ");
  Serial.println(myFile.name());
  Serial.println("");
}

void leerEstructura() {
  // abrir archivo para lectura
  myFile = SD.open(nombreArchivo, FILE_READ);
  
  if (myFile) {  
    Serial.print(myFile.name());
    Serial.println(" abierto para lectura");
    Serial.println("");

    // leer estructura
    myFile.read((uint8_t*) &datos_lec, sizeof(datos_lec));
  }
  else {
    Serial.println("error al abrir el archivo");
  }
  // cerrar archivo
  myFile.close();

  Serial.print("Archivo cerrado: ");
  Serial.println(myFile.name());
  Serial.println("");

  // mostrar contenidos leidos
  Serial.println("Estructura leida:");
  
  Serial.print("Tipo sensor: ");
  Serial.println(datos_lec.tipo);
  Serial.print("Valor de la medicion: ");
  Serial.println(datos_lec.valor);
  Serial.print("Tiempo desde la ultima medicion: ");
  Serial.println(datos_lec.tiempoUltMedicion);
}