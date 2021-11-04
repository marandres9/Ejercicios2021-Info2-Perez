#include <iostream>
#include "rectangulo.h"

Rectangulo::Rectangulo(float a, float b) {
    this->x = a;
    this->y = b;
    calcAreaPerim();
}

void Rectangulo::calcAreaPerim() {
    area = this->x * this->y;
    perim = 2*this->x + 2*this->y;
}

void Rectangulo::setRectangulo(float x, float y) {
    this->x = x;
    this->y = y;
    calcAreaPerim();
}

void Rectangulo::getRectangulo() const {
    std::cout << "Long x = " << x << std::endl << "Long y = " << y << std::endl
        << "Area = " << area << std::endl << "Perimetro = " << perim << std::endl;
}

bool Rectangulo::estaDentroDe(Rectangulo r) const {
    if(x <= r.x && y <= r.y) {
        return true;
    }
    return false;
}

float Rectangulo::areaInterseccion(Rectangulo r) const {
    if(estaDentroDe(r)) {
        return x * y;
    }
    else {
        return r.x * r.y;
    }
}
