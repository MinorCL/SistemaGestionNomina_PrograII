#include "HorasOrdinariasMixta.h"

HorasOrdinariasMixta::HorasOrdinariasMixta(int horas)
{
	this->horas = horas;
}

int HorasOrdinariasMixta::calcular() const
{
	return horas * valorHora;

}

void HorasOrdinariasMixta::setSalarioBase(float salario)
{
	this->salarioBase = salario;
	valorHora = (salarioBase / 240)*8/7; 
}



