#pragma once
#include "ComponenteSalario.h"

class HorasOrdinarias : public ComponenteSalario {
    int horas;
    float valorHora;
public:
    HorasOrdinarias(int horas);
    int calcular() const override;
    void setSalarioBase(float salario) override;
};

