#pragma once
#include"Deduccion.h"

class Maternidad:public Deduccion{
public:
	void aplicar(double& salario) override;
};

