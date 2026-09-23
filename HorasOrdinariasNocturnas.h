#pragma once
#include "ComponenteSalario.h"
class HorasOrdinariasNocturnas :
    public ComponenteSalario
{
private:
    int horas;
    int valorHora;
public:
    HorasOrdinariasNocturnas(int horas);
    int calcular() const override;
    void setSalarioBase(float salario) override;
};

