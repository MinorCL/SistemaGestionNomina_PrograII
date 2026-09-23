#pragma once
#include "ComponenteSalario.h"
#include "ComponteFactory.h"

class IngresoBuilder {
private:
    float salarioBase;
    ComponenteSalario** componentes;
    int capacidad;
    int cantidad;
    void expandir();

public:
    IngresoBuilder();
    IngresoBuilder(float s);
    ~IngresoBuilder();

    IngresoBuilder* agregarComponente(TipoComponente tipo, int parametro);
    IngresoBuilder* agregarHorasOrdinarias(int horas);
    IngresoBuilder* agregarHorasExtraDiurna(int horas);
    IngresoBuilder* agregarBonificacionMontoFijo(double monto);
    IngresoBuilder* agregarBonificacionPorcentaje(double porcentaje);
    IngresoBuilder* agregarHorasOrdinariasMixta(int horas);
    IngresoBuilder* agregarHorasOrdinariasNocturnas(int horas);
    IngresoBuilder* agregarHorasExtraMixta(int horas);
    IngresoBuilder* agregarHorasExtraNocturna(int horas);
    IngresoBuilder* agregarHorasDoblesDiurnas(int horas);
    IngresoBuilder* agregarHorasDoblesMixta(int horas);
    IngresoBuilder* agregarHorasDoblesNocturna(int horas);
    IngresoBuilder* agregarHorasFeriadoLaborado(int horas);
    IngresoBuilder* agregarHorasExtraFeriadoLaborado(int horas);

    bool tieneComponentes() const;
    int calcularSalarioBruto();
};