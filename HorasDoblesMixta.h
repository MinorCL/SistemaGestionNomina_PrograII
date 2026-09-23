#pragma once
#include "ComponenteSalario.h"
class HorasDoblesMixta :
    public ComponenteSalario
{
private:
    int horas;
    int valorHora;
public:
    HorasDoblesMixta(int horas);
    int calcular() const override;
    void setSalarioBase(float salario) override;
};

