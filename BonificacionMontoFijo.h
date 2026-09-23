#pragma once
#include "ComponenteSalario.h"
class BonificacionMontoFijo : public ComponenteSalario {
    int monto;
public:

    BonificacionMontoFijo(int monto) : monto(monto) {}
    int calcular() const override;
    void setSalarioBase(float salario) override;
};
