#pragma once
#include "ComponenteSalario.h"
class HorasOrdinariasMixta :
    public ComponenteSalario
{
private:
    int horas; 
	int valorHora; 
public:
    HorasOrdinariasMixta(int horas);
    int calcular() const override;
    void setSalarioBase(float salario) override;
};

