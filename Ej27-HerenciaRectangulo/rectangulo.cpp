#include <iostream>
#include "rectanguloYCuadrado.hpp"

Rectangulo::Rectangulo(int x=0, int y=0, int width=1, int height=1)
    : x (x), y(y), width(width), height(height) 
{
    area = getArea();
    perimetro = getPerimetro();
}

int Rectangulo::getArea() {
    return this->width * this->height;
}
int Rectangulo::getPerimetro() {
    return 2 * this->width + 2 * this->height;
}

void Rectangulo::setDimensiones(int ancho, int largo) {
    this->width = ancho;
    this->height = largo;
    this->area = getArea();
    this->perimetro = getPerimetro();
}

void Rectangulo::getDimensiones() const {
    std::cout << "Ancho = " << this->height << std::endl << "Alto= " << this->y << std::endl
        << "Area = " << this->area << std::endl << "Perimetro = " << this->perimetro << std::endl;
}

bool Rectangulo::estaDentroDe(Rectangulo r) const {
    if(this->width - this->x <= r.width - r.x && this->height - this->y <= r.height - r.y) {
        return true;
    }
    return false;
}

int Rectangulo::areaInterseccion(Rectangulo r) const {
    if(estaDentroDe(r)) {
        return this->x * this->y;
    }
    else {
        return r.x * r.y;
    }
}
