#pragma once
#include <string>

class Empleado {
public:
    Empleado (std::string nom, int edad, double salario)
        : nombre(nom), edad(edad), salario(salario), plus(5000) {}
protected:
    std::string nombre;
    int edad;
    double salario;
    int plus;
};

class Repartidor : public Empleado {
public:
    Repartidor (std::string nom, int edad, double salario, int zona)
        : Empleado(nom, edad, salario), zona(zona) {}

    bool tienePlus() {
        if (edad < 25 && zona == 3) {
            return true;
        }
        else {
            return false;
        }
    }
    void aplicarPlus() {
        if (tienePlus()) {
            salario += plus;
        }
    }
    void getSalario() { 
        std::cout << nombre << ", " << "Salario: " << salario << std::endl; 
    }
protected:
    int zona;    
};

class Comercial : public Empleado {
public:
    Comercial (std::string nom, int edad, double salario, double comision)
        : Empleado(nom, edad, salario), comision(comision) {}

    bool tienePlus() {
        if (edad > 30 && comision > 25000) {
            return true;
        }
        else {
            return false;
        }
    }
    void aplicarPlus() {
        if (tienePlus()) {
            salario += plus;
        }
    }
    void getSalario() { 
        std::cout << nombre << ", " << "Salario: " << salario << std::endl; 
    }
protected:
    double comision;

};