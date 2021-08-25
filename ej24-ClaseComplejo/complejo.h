#ifndef _COMPLEJO_H_
#define _COMPLEJO_H_

class Complejo {
    double p;
    double q;

    public:
        Complejo();
        Complejo(double re, double im);

        void suma(Complejo c);
        void resta(Complejo c);
        void imprimir();
};

#endif