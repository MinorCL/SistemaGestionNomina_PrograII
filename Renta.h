#pragma once
#include "Deduccion.h"

class Renta : public Deduccion {
public:
    void aplicar(double& salario) override;
};

