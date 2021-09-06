#ifndef RECTANGULO_H
#define RECTANGULO_H

class Rectangulo {
    double x;
    double y;
    double area;
    double perim;

    public:
    // constructores
    Rectangulo();
    Rectangulo(float, float);
    // metodos
    void calcAreaPerim();
    void setRectangulo(float, float);
    void getRectangulo();

    bool estaDentroDe(Rectangulo);
    float areaInterseccion(Rectangulo);
    
};

#endif
