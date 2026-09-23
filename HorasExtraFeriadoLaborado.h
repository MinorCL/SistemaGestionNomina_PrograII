#pragma once
#include "ComponenteSalario.h"
class HorasExtraFeriadoLaborado :
    public ComponenteSalario
{
private:
    int horas;
    int valorHora;
public:
    HorasExtraFeriadoLaborado(int horas);
    int calcular() const override;
    void setSalarioBase(float salario) override;
};

