#ifndef _COMPLEJO_H_
#define _COMPLEJO_H_

class Complejo {
    double p;
    double q;

    public:
    Complejo(double =0, double =0);

    void suma(Complejo c);
    void resta(Complejo c);
    void imprimir();
};

#endif
