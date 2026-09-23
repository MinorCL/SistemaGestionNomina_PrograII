#include "DeduccionCompuesta.h"

void DeduccionCompuesta::expandir()
{
    capacidad *= 2;
    Deduccion** nuevo = new Deduccion * [capacidad];
    for (int i = 0; i < cantidad; i++) {
        nuevo[i] = deducciones[i];
    }
    delete[] deducciones;
    deducciones = nuevo;
}

void DeduccionCompuesta::agregarDeduccion(Deduccion* d)
{
    if (cantidad == capacidad) {
        expandir();
    }
    deducciones[cantidad++] = d;
}
void DeduccionCompuesta::aplicar(double& salario)  {
    for (int i = 0; i < cantidad; i++) {
        deducciones[i]->aplicar(salario);
    }
}

bool DeduccionCompuesta::tieneDeducciones()
{
    if(cantidad == 0) {
        return false;
	}
	return true;
}

void DeduccionCompuesta::modificarPorcentajeCCSS(float nuevoPorcentaje) {
    for (int i = 0; i < cantidad; i++) {
        deducciones[i]->setPorcentaje(nuevoPorcentaje);
    }
}

DeduccionCompuesta::~DeduccionCompuesta()
{
    for (int i = 0; i < cantidad; i++) {
        delete deducciones[i];
    }
    delete[] deducciones;
}
