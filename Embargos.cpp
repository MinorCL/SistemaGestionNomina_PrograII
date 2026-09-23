#include "Embargos.h"

float Embargos::calcularMontoEmbargable(float salario)const
{
    // 1. Si el salario es menor o igual al mínimo, no se embarga nada
    if (salario <= salarioMinimo)
    {
        return 0.0;
    }

    // 2. Calculamos el exceso sobre el salario mínimo
    float exceso = salario - salarioMinimo;

    if (exceso <= 3 * salarioMinimo)
    {
        return exceso * 0.125; // 12.5% del exceso
    }
    else
    {
        return exceso * 0.25;  // 25% del exceso
    }
}

void Embargos::aplicar(double& salario)
{
    salario -= calcularMontoEmbargable(salario);
}