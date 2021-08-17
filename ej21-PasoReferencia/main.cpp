#include <iostream> 

using namespace std;

int tripleLlamadaPorValor(int n) {
    return n*3;
}
void triplePorReferencia(int* n) {
    *n *= 3;
}

int main() {
    int cuenta = 3;

    cout << "Utilizando la funcion tripleLlamadaPorValor:" << endl;
    cout << tripleLlamadaPorValor(cuenta) << endl;
    cout << "Variable original: " << cuenta << endl;

    cout << "Utilizando la funcion triplePorReferencia" << endl;
    triplePorReferencia(&cuenta);
    cout << cuenta << endl;
    cout << "Variable original: " << cuenta << endl;


    return 0;
}
