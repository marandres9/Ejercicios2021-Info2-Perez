#include "complejo.h"
#include <iostream>

Complejo::Complejo() {
    p = 0;
    q = 0;
}

Complejo::Complejo(double re, double im) {
    p = re;
    q = im;
}

void Complejo::suma(Complejo c) {
    p += c.p;
    q += c.q;
}

void Complejo::resta(Complejo c) {
    p -= c.p;
    q -= c.q;
}

void Complejo::imprimir() {
    std::cout << "(" << p << ", " << q << ")" << std::endl;
}
