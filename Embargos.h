#pragma once
#include "Deduccion.h"

class Embargos : public Deduccion
{
    float salarioMinimo = 220310.0;

public:
    void aplicar(double& salario) override;
    float calcularMontoEmbargable(float salario)const;
};

