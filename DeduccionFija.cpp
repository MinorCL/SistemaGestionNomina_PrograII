#include "DeduccionFija.h"
void DeduccionFija::aplicar(double& salario) {
	salario -= montoFijo;
}

void DeduccionFija::setMontoFijo(float montoFijo)
{
	this->montoFijo = montoFijo;
}



