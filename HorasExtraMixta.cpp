#include "HorasExtraMixta.h"


HorasExtraMixta::HorasExtraMixta(int horas)
{
	this->horas = horas;
}


int HorasExtraMixta::calcular() const
{
	return horas * valorHora;

}

void HorasExtraMixta::setSalarioBase(float salario)
{
	this->salarioBase = salario;
	valorHora = (salarioBase / 240) *3/2* 8 / 7;
}
