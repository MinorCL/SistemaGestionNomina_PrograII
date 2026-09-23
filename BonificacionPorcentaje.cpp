#include "BonificacionPorcentaje.h"

BonificacionPorcentaje::BonificacionPorcentaje(double porcentaje)
	: porcentaje(porcentaje)
{
}
int BonificacionPorcentaje::calcular() const
{
	return salarioBase+(salarioBase * (porcentaje / 100));

}

void BonificacionPorcentaje::setSalarioBase(float salario)
{
	this->salarioBase = salario;
}
