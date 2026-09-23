#include "HorasDoblesDiurnas.h"

HorasDoblesDiurnas::HorasDoblesDiurnas(int horas)
{
	this->horas = horas;
}


int HorasDoblesDiurnas::calcular() const
{
	return horas * valorHora;

}

void HorasDoblesDiurnas::setSalarioBase(float salario)
{
	this->salarioBase = salario;
	valorHora = (salarioBase / 240) * 2;
}
