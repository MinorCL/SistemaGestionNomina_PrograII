#include "DeduccionBuilder.h"

DeduccionBuilder::DeduccionBuilder() : modelo(new DeduccionCompuesta()), built(false) {}

DeduccionBuilder* DeduccionBuilder::conTipoCCSS() {
    modelo->agregarDeduccion(DeduccionFactory::crearDeduccion(DeduccionFactory::CCSS_T));
    return this;
}

DeduccionBuilder* DeduccionBuilder::conTipoRenta() {
    modelo->agregarDeduccion(DeduccionFactory::crearDeduccion(DeduccionFactory::RENTA));
    return this;
}

DeduccionBuilder* DeduccionBuilder::conTipoEmbargo() {
    modelo->agregarDeduccion(DeduccionFactory::crearDeduccion(DeduccionFactory::EMBARGO));
    return this;
}

DeduccionBuilder* DeduccionBuilder::conMontoFijo(float montoFijo) {
    modelo->agregarDeduccion(DeduccionFactory::crearDeduccion(DeduccionFactory::MONTO_FIJO, montoFijo));
    return this;
}

DeduccionBuilder* DeduccionBuilder::conPorcentaje(float porcentaje) {
    modelo->agregarDeduccion(DeduccionFactory::crearDeduccion(DeduccionFactory::PORCENTAJE, porcentaje));
    return this;
}

DeduccionBuilder* DeduccionBuilder::conMaternidad() {
    modelo->agregarDeduccion(DeduccionFactory::crearDeduccion(DeduccionFactory::MATERNIDAD));
    return this;
}



Deduccion* DeduccionBuilder::build() {
    if (built) {

        DeduccionCompuesta* copia = new DeduccionCompuesta();

        return modelo;
    }
    built = true;
    return modelo;
}

bool DeduccionBuilder::tieneDeduccion() const {
    return modelo->tieneDeducciones();
}

DeduccionBuilder::~DeduccionBuilder() {
    if (!built) {
        delete modelo;
    }
}
void DeduccionBuilder::setCCSS(float p) {
    if (modelo != nullptr) {
        modelo->modificarPorcentajeCCSS(p);
    }
}
