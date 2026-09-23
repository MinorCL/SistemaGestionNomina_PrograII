#include "HorasExtraDiurnas.h"

HorasExtraDiurna::HorasExtraDiurna(int horas)
{
	this->horas = horas;
	valorHora = (salarioBase / 240) * 3 / 2;
}
int HorasExtraDiurna::calcular() const {
    return horas * valorHora;
}
void HorasExtraDiurna::setSalarioBase(float salario)  {
    salarioBase = salario;
    valorHora = (salarioBase / 240) * 3 / 2; 
}