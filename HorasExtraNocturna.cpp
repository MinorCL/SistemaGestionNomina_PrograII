#include "HorasExtraNocturna.h"

HorasExtraNocturna::HorasExtraNocturna(int horas)
{
	this->horas = horas;
}


int HorasExtraNocturna::calcular() const
{
	return horas * valorHora;

}

void HorasExtraNocturna::setSalarioBase(float salario)
{
	this->salarioBase = salario;
	valorHora = (salarioBase / 240) *3 / 2 * 8 / 7;
}
