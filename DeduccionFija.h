#pragma once
#include "Deduccion.h"
class DeduccionFija : public Deduccion
{
private:
	float montoFijo;
public:
	void aplicar(double& salario)override;
	void setMontoFijo(float montoFijo);
};

