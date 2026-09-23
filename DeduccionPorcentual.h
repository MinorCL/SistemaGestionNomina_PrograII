#pragma once
#include "Deduccion.h"
class DeduccionPorcentual : public Deduccion
{
private:
	float porcentaje;
public:
	void aplicar(double& salario) override;
	void setPorcentaje(float porcentaje);
};

