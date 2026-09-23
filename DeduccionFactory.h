#pragma once
#include "Deduccion.h"
#include "CCSS.h"
#include "Renta.h"
#include "Embargos.h"
#include "DeduccionPorcentual.h"
#include "DeduccionFija.h"
#include "Maternidad.h"

class DeduccionFactory {
public:
    enum TipoDeduccion {
        CCSS_T,
        RENTA,
        EMBARGO,
        MONTO_FIJO,
        PORCENTAJE,
        MATERNIDAD
    };

    static Deduccion* crearDeduccion(TipoDeduccion tipo, float valor = 0.0f) {
        switch (tipo) {
        case CCSS_T: return new CCSS();
        case RENTA: return new Renta();
        case EMBARGO: return new Embargos();
        case MONTO_FIJO: {
            DeduccionFija* df = new DeduccionFija();
            df->setMontoFijo(valor);
            return df;
        }
        case PORCENTAJE: {
            DeduccionPorcentual* dp = new DeduccionPorcentual();
            dp->setPorcentaje(valor);
            return dp;
        }
        case MATERNIDAD: return new Maternidad();
        default: return nullptr;
        }
    }
};