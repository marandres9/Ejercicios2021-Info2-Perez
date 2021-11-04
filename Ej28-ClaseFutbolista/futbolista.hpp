#pragma once

#include "persona.hpp"

class Futbolista : public Persona {
public:
    Futbolista (std::string nom, std::string ap, int num)
        : Persona(nom, ap), numero(num) {}

    void getDatos()
    {
        std::cout << this->apellido << ", " <<
                     this->nombre << ": " << 
                     this->numero << std::endl;
    }
private:
    int numero;
};