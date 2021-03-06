#include <iostream>
#include "rectangulo.h"

Rectangulo::Rectangulo(float a, float b) {
    x = a;
    y = b;
    calcAreaPerim();
}

void Rectangulo::calcAreaPerim() {
    area = x * y;
    perim = 2*x + 2*y;
}

void Rectangulo::setRectangulo(float a, float b) {
    x = a;
    y = b;
    calcAreaPerim();
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
