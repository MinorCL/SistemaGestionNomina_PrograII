#pragma once
#include "ComponenteSalario.h"
class BonificacionPorcentaje :
    public ComponenteSalario
{
    private:
		double porcentaje;
public:
	BonificacionPorcentaje(double porcentaje);
    int calcular() const override;
    void setSalarioBase(float salario) override;
};

