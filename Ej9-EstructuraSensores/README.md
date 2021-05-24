* Programa ejectuado en computadora:
![Programa ejecutado en computadora](https://github.com/mariano-perez09/Ejercicios2021-Info2-Perez/blob/main/Ej9-EstructuraSensores/Fotos/ejC.png)
* Programa ejectuado en Arduino:
![Programa ejecutado en Arduino](https://github.com/mariano-perez09/Ejercicios2021-Info2-Perez/blob/main/Ej9-EstructuraSensores/Fotos/ejArduino.png)

Como vimos en clase, el tamaño de la estructura 'sensor' es de 12 bytes al ejecutar el programa en la computadora. Esto se debe a que se reserva la memoria en bloques del tamaño de datos mas grande que utiliza la estructura. En la caso de 'sensores', tanto el 'int' como el 'unsigned long' ocupan 4 bytes, por lo que al tipo de dato 'char' se le asignara otro bloque de 4 bytes.
En cambio, en Arduino la memoria se asigna en bloques de 1 byte. Entonces se le asignan 1 bloque de 1 byte a 'char' y  4 bloques de 1 byte a 'int' y 'unsigned long', uno a continuacion del otro. Esto resulta en un tamaño total de 7 bytes.

Esto puede causar problemas al pasar archivos de Arduino a PC o viceversa ya que los datos pueden estar almacenados en diferentes direcciones de memoria.