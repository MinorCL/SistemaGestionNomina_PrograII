#include "DeduccionPorcentual.h"
void DeduccionPorcentual::aplicar(double& salario) {
	salario -= salario * porcentaje / 100.0f;
}

void DeduccionPorcentual::setPorcentaje(float porcentaje)
{
	this->porcentaje = porcentaje;
}
