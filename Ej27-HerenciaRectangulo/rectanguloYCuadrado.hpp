#pragma once

class Rectangulo {
public:
    // constructor
    Rectangulo (int x, int y, int width, int height);
    // setters y getters
    void setDimensiones(int ancho, int alto);
    void getDimensiones() const;

    bool estaDentroDe(Rectangulo r) const;
    int areaInterseccion(Rectangulo r) const;

    int getArea();
    int getPerimetro();


private:
    // top left
    int x, y;
    int area;
    int perimetro;
    int width;
    int height;
};

class Cuadrado : public Rectangulo {
public:
    Cuadrado(int lado=1)
        : Rectangulo(0, 0, lado, lado) {}
};