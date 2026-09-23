#include "HorasExtraFeriadoLaborado.h"

HorasExtraFeriadoLaborado::HorasExtraFeriadoLaborado(int horas)
{
	this->horas = horas;
}


int HorasExtraFeriadoLaborado::calcular() const
{
	return horas * valorHora;

}

void HorasExtraFeriadoLaborado::setSalarioBase(float salario)
{
	this->salarioBase = salario;
	valorHora = (salarioBase / 240) * 3;
}
