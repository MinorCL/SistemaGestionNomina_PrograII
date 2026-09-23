#pragma once
#include "Deduccion.h"

class CCSS : public Deduccion {
    private:
		float porcentaje;
public:
	CCSS();
	CCSS(float porcentaje);
    void aplicar(double& salario) override ;
	void setPorcentaje(float porcentaje) override;
};
