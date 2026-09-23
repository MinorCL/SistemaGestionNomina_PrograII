#pragma once
#include "ComponenteSalario.h"
class HorasExtraDiurna : public ComponenteSalario {
    int horas;
    float valorHora;
public:
    HorasExtraDiurna(int horas);
    int calcular() const override;
    void setSalarioBase(float salario) override;
};

