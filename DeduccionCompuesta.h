#pragma once
#include "Deduccion.h"

class DeduccionCompuesta : public Deduccion {
private:
    Deduccion** deducciones;
    int capacidad;
    int cantidad;
    void expandir();

public:
    DeduccionCompuesta() : capacidad(2), cantidad(0) {
        deducciones = new Deduccion * [capacidad];
    }
    void agregarDeduccion(Deduccion* d);
    void aplicar(double& salario) override;
	bool tieneDeducciones();
    void modificarPorcentajeCCSS(float nuevoPorcentaje);
    ~DeduccionCompuesta();
};

