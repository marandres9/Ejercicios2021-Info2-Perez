#ifndef _COMPLEJO_H_
#define _COMPLEJO_H_

class Complejo {
    double p;
    double q;

    public:
    Complejo(double re=0, double im=0);

    void suma(Complejo c);
    void resta(Complejo c);
    void imprimir();
};

#endif
