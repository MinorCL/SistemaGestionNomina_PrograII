#include "ComponteFactory.h"

ComponenteSalario* ComponenteFactory::crearComponente(TipoComponente tipo, int parametro, float salarioBase)
{
    ComponenteSalario* componente = nullptr;

    switch (tipo) {
    case BONIFICACION_MONTO_FIJO:
        componente = new BonificacionMontoFijo(parametro);
        break;
    case BONIFICACION_PORCENTAJE:
        componente = new BonificacionPorcentaje(parametro);
        break;
    case HORAS_ORDINARIAS_DIURNO:
        componente = new HorasOrdinarias(parametro);
        break;
    case HORAS_ORDINARIAS_MIXTA:
        componente = new HorasOrdinariasMixta(parametro);
        break;
    case HORAS_ORDINARIAS_NOCTURNO:
        componente = new HorasOrdinariasNocturnas(parametro);
        break;
    case HORAS_EXTRA_DIURNA:
        componente = new HorasExtraDiurna(parametro);
        break;
    case HORAS_EXTRA_MIXTA:
        componente = new HorasExtraMixta(parametro);
        break;
    case HORAS_EXTRA_NOCTURNA:
        componente = new HorasExtraNocturna(parametro);
        break;
    case HORAS_DOBLES_DIURNA:
        componente = new HorasDoblesDiurnas(parametro);
        break;
    case HORAS_DOBLES_MIXTA:
        componente = new HorasDoblesMixta(parametro);
        break;
    case HORAS_DOBLES_NOCTURNO:
        componente = new HorasDoblesNocturno(parametro);
        break;
    case HORAS_FERIADO_LABORADO:
        componente = new HorasExtraFeriadoLaborado(parametro);
        throw "Tipo de componente no implementado";
        break;
    case HORAS_EXTRA_FERIADO_LABORADO:
        componente = new HorasExtraFeriadoLaborado(parametro);
        break;
    default:
        throw "Tipo de componente no válido";
    }

    if (componente) {
        componente->setSalarioBase(salarioBase);
    }
    return componente;
}