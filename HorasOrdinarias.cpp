#include "HorasOrdinarias.h"

HorasOrdinarias::HorasOrdinarias(int horas)
{
	this->horas = horas;
}
int HorasOrdinarias::calcular() const  {
    return horas * valorHora;
}
void HorasOrdinarias::setSalarioBase(float salario)  {
    salarioBase = salario;
    valorHora = salarioBase / 240;  
}