#pragma once
#include <string>
#include <iostream>

class Persona {
public:
    Persona(std::string nom, std::string ap)
        : nombre(nom), apellido(ap) {}

protected:
    std::string nombre, apellido;
};