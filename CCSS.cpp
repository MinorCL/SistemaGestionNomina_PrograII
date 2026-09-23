#include "CCSS.h"
CCSS::CCSS()
{
    this->porcentaje = 26;
}

CCSS::CCSS(float porcentaje) {
    this->porcentaje = porcentaje;
}
void CCSS::aplicar(double& salario)  {
    salario -= salario * (porcentaje/100); 
}

void CCSS::setPorcentaje(float porcentaje) {
    this->porcentaje = porcentaje;
}

