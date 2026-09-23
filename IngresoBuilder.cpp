#include "IngresoBuilder.h"

void IngresoBuilder::expandir() {
    capacidad *= 2;
    ComponenteSalario** nuevo = new ComponenteSalario * [capacidad];
    for (int i = 0; i < cantidad; i++) {
        nuevo[i] = componentes[i];
    }
    delete[] componentes;
    componentes = nuevo;
}

IngresoBuilder::IngresoBuilder() {
    capacidad = 10;
    cantidad = 0;
    salarioBase = 0;
    componentes = new ComponenteSalario * [capacidad];
}

IngresoBuilder::IngresoBuilder(float s) {
    capacidad = 10;
    cantidad = 0;
    salarioBase = s;
    componentes = new ComponenteSalario * [capacidad];
}

IngresoBuilder* IngresoBuilder::agregarComponente(TipoComponente tipo, int parametro) {
    if (cantidad == capacidad) expandir();
    componentes[cantidad] = ComponenteFactory::crearComponente(tipo, parametro, salarioBase);
    cantidad++;
    return this;
}

// Métodos específicos (implementados usando el factory)
IngresoBuilder* IngresoBuilder::agregarHorasOrdinarias(int horas) {
    return agregarComponente(HORAS_ORDINARIAS_DIURNO, horas);
}

IngresoBuilder* IngresoBuilder::agregarHorasExtraDiurna(int horas) {
    return agregarComponente(HORAS_EXTRA_DIURNA, horas);
}

IngresoBuilder* IngresoBuilder::agregarBonificacionMontoFijo(double monto) {
    return agregarComponente(BONIFICACION_MONTO_FIJO, (monto));
}

IngresoBuilder* IngresoBuilder::agregarBonificacionPorcentaje(double porcentaje) {
    return agregarComponente(BONIFICACION_PORCENTAJE,(porcentaje));
}

IngresoBuilder* IngresoBuilder::agregarHorasOrdinariasMixta(int horas) {
    return agregarComponente(HORAS_ORDINARIAS_MIXTA, horas);
}

IngresoBuilder* IngresoBuilder::agregarHorasOrdinariasNocturnas(int horas) {
    return agregarComponente(HORAS_ORDINARIAS_NOCTURNO, horas);
}

IngresoBuilder* IngresoBuilder::agregarHorasExtraMixta(int horas) {
    return agregarComponente(HORAS_EXTRA_MIXTA, horas);
}

IngresoBuilder* IngresoBuilder::agregarHorasExtraNocturna(int horas) {
    return agregarComponente(HORAS_EXTRA_NOCTURNA, horas);
}

IngresoBuilder* IngresoBuilder::agregarHorasDoblesDiurnas(int horas) {
    return agregarComponente(HORAS_DOBLES_DIURNA, horas);
}

IngresoBuilder* IngresoBuilder::agregarHorasDoblesMixta(int horas) {
    return agregarComponente(HORAS_DOBLES_MIXTA, horas);
}

IngresoBuilder* IngresoBuilder::agregarHorasDoblesNocturna(int horas) {
    return agregarComponente(HORAS_DOBLES_NOCTURNO, horas);
}

IngresoBuilder* IngresoBuilder::agregarHorasFeriadoLaborado(int horas) {
    return agregarComponente(HORAS_FERIADO_LABORADO, horas);
}

IngresoBuilder* IngresoBuilder::agregarHorasExtraFeriadoLaborado(int horas) {
    return agregarComponente(HORAS_EXTRA_FERIADO_LABORADO, horas);
}

bool IngresoBuilder::tieneComponentes() const {
    return cantidad > 0;
}

int IngresoBuilder::calcularSalarioBruto() {
    int total = 0;
    for (int i = 0; i < cantidad; i++) {
        total += componentes[i]->calcular();
    }
    return total;
}

IngresoBuilder::~IngresoBuilder() {
    for (int i = 0; i < cantidad; i++) {
        delete componentes[i];
    }
    delete[] componentes;
}