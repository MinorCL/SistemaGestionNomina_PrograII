#pragma once
#include "ComponenteSalario.h"
class HorasExtraNocturna :
    public ComponenteSalario
{
private:
    int horas;
    int valorHora;
public:
    HorasExtraNocturna(int horas);
    int calcular() const override;
    void setSalarioBase(float salario) override;
};

