#ifndef RECTANGULO_H
#define RECTANGULO_H

class Rectangulo {
    // coord medidas desde esq inf izq
    double x;
    double y;
    double area;
    double perim;

    void calcAreaPerim();

public:
    // constructores
    Rectangulo(float a = 1, float b = 1);

    // metodos
    void setRectangulo(float, float);
    void getRectangulo() const;

    bool estaDentroDe(Rectangulo) const;
    float areaInterseccion(Rectangulo) const;
    
};

#endif
