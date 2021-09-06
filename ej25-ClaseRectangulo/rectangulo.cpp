#include <iostream>
#include "rectangulo.h"

Rectangulo::Rectangulo() {
    x = 1;
    y = 1;
    area = 1;
    perim = 4;
}
Rectangulo::Rectangulo(float a, float b) {
    x = a;
    y = b;
    area = a * b;
    perim = 2*a + 2*b;
}

void Rectangulo::calcAreaPerim() {
    area = x * y;
    perim = 2*x + 2*y;
}

void Rectangulo::setRectangulo(float a, float b) {
    x = a;
    y = b;
}

void Rectangulo::getRectangulo() {
    std::cout << "Long x = " << x << std::endl << "Long y = " << y << std::endl
        << "Area = " << area << std::endl << "Perimetro = " << perim << std::endl;
}

bool Rectangulo::estaDentroDe(Rectangulo r) {
    if(x <= r.x && y <= r.y) {
        return true;
    }
    return false;
}

float Rectangulo::areaInterseccion(Rectangulo r) {
    if(estaDentroDe(r)) {
        return x * y;
    }
    else {
        return r.x * r.y;
    }

}
