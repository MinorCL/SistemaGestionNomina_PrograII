#include "Renta.h"
void Renta::aplicar(double& salario)  {
    float impuesto = 0;
    if (salario > 1352000) impuesto = (salario - 1352000) * 0.15 + (1352000 - 922000) * 0.10;
    else if (salario > 922000) impuesto = (salario - 922000) * 0.10;
    salario -= impuesto; // Reduce directamente el salario
}