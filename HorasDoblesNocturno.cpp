#include "HorasDoblesNocturno.h"

HorasDoblesNocturno::HorasDoblesNocturno(int horas)
{
	this->horas = horas;
}


int HorasDoblesNocturno::calcular() const
{
	return horas * valorHora;

}

void HorasDoblesNocturno::setSalarioBase(float salario)
{
	this->salarioBase = salario;
	valorHora = (salarioBase / 240) * 2 * 8 / 6;
}


