#pragma once

class Sensor {
public:
    Sensor();
    Sensor(int vel, int acel);

    void setAceleracion(int acel);
    void setVelocidad(int vel);

    void getAceleracion();
    void getVelocidad();
private:
    int velocidad;
    int aceleracion;
};

Sensor::Sensor() 
{}
Sensor::Sensor(int vel, int acel) 
    : velocidad(vel), aceleracion(acel) 
{}

void Sensor::setVelocidad(int vel = 0) {
    if (vel > 4095 || vel < 0) {
        return;
    }
    velocidad = vel * 1000/4095;
}
void Sensor::setAceleracion(int acel = 0) {
    if (acel > 1023 || acel < 0) {
        return;
    }
    aceleracion = acel * 5/1023;
}

void Sensor::getVelocidad() {
    std::cout << "Velocidad: " << this->velocidad << " m/s\n"; 
}
void Sensor::getAceleracion() {
    std::cout << "Acelearcion: " << this->velocidad << " g\n"; 

}