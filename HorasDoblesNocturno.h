#pragma once
#include "ComponenteSalario.h"
class HorasDoblesNocturno :
    public ComponenteSalario
{
private:
    int horas;
    int valorHora;
public:
    HorasDoblesNocturno(int horas);
    int calcular() const override;
    void setSalarioBase(float salario) override;
};

