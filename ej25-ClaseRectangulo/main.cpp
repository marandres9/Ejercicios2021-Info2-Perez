#include <iostream>
#include "rectangulo.h" 

int main() {
    Rectangulo r1;
    Rectangulo r2(2, 2);
   
    std::cout << "Rectangulo r1:" << std::endl;
    r1.getRectangulo();

    r2.calcAreaPerim();
    std::cout << "Rectangulo r2:" << std::endl;
    r2.getRectangulo();
    
    r1.setRectangulo(3, 2);
    r1.calcAreaPerim();
    std::cout << "Nuevo rectangulo r1:" << std::endl;
    r1.getRectangulo();

    const char* resultado = r2.estaDentroDe(r1) == 1 ? "true" : "false";
    std::cout << "r2 se encuentra dentro de r1? : " << resultado << std::endl;
    std::cout << "Area de interseccion entre r1 y r2 = " << r2.areaInterseccion(r1) << std::endl;
        

    return 0;
}
