#pragma once
#include "ComponenteSalario.h"
class HorasDoblesDiurnas :
    public ComponenteSalario
{
private:
    int horas;
    int valorHora;
public:
    HorasDoblesDiurnas(int horas);
    int calcular() const override;
    void setSalarioBase(float salario) override;
};

