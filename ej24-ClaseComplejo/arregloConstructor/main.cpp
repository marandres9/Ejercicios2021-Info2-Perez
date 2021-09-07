#include "complejo.h"

int main() {
    Complejo c1(21, 3);
    Complejo c2;
    Complejo c3(3, 21);

    c1.imprimir();

    c2.suma(c1);
    c2.resta(c3);
    
    c2.imprimir();


    return 0;
}
