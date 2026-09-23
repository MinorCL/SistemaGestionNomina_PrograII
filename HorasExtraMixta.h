#pragma once
#include "ComponenteSalario.h"
class HorasExtraMixta :
    public ComponenteSalario
{
private:
    int horas;
    int valorHora;
public:
    HorasExtraMixta(int horas);
    int calcular() const override;
    void setSalarioBase(float salario) override;
};

