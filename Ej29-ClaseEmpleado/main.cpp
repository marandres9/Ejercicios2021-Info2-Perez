#include <iostream>
#include "Empleado.hpp"

int main() {
    Comercial a("com", 20, 7000, 25100);
    Repartidor b("rep", 20, 5000, 3);

    a.getSalario();
    b.getSalario();

    a.aplicarPlus();
    b.aplicarPlus();
    std::cout << "Tiene plus? :" << a.tienePlus() << std::endl;
    a.getSalario();
    std::cout << "Tiene plus?: " << b.tienePlus() << std::endl;
    b.getSalario();

}