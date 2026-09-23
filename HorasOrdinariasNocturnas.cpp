#include "HorasOrdinariasNocturnas.h"

HorasOrdinariasNocturnas::HorasOrdinariasNocturnas(int horas)
{
	this->horas = horas;
}


int HorasOrdinariasNocturnas::calcular() const
{
	return horas * valorHora;

}

void HorasOrdinariasNocturnas::setSalarioBase(float salario)
{
	this->salarioBase = salario;
	valorHora = (salarioBase / 240) * 8 / 6;
}