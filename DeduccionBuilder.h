#pragma once
#include "DeduccionCompuesta.h"
#include "DeduccionFactory.h"

class DeduccionBuilder {
private:
    DeduccionCompuesta* modelo;
    bool built; // Para controlar si ya se construyó

public:
    DeduccionBuilder();
    ~DeduccionBuilder();

    DeduccionBuilder* conTipoCCSS();
    DeduccionBuilder* conTipoRenta();
    DeduccionBuilder* conTipoEmbargo();
    DeduccionBuilder* conMontoFijo(float montoFijo);
    DeduccionBuilder* conPorcentaje(float porcentaje);
    DeduccionBuilder* conMaternidad();
	void setCCSS(float p);

    Deduccion* build();
    bool tieneDeduccion() const;
};