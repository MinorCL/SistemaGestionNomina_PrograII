#pragma once

class Deduccion {
public:
    virtual void aplicar(double& salario) = 0; 
    virtual void setPorcentaje(float porcentaje) {}

};