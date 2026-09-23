#include "HorasDoblesMixta.h"

HorasDoblesMixta::HorasDoblesMixta(int horas)
{
	this->horas = horas;
}


int HorasDoblesMixta::calcular() const
{
	return horas * valorHora;

}

void HorasDoblesMixta::setSalarioBase(float salario)
{
	this->salarioBase = salario;
	valorHora = (salarioBase / 240) * 2*8/7;
}

