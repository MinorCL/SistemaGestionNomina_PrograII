#include "ComponenteSalario.h"
#include "HorasOrdinarias.h"
#include "HorasExtraDiurnas.h"
#include "BonificacionMontoFijo.h"
#include "BonificacionPorcentaje.h"
#include "HorasOrdinariasMixta.h"
#include "HorasOrdinariasNocturnas.h"
#include "HorasExtraMixta.h"
#include "HorasExtraNocturna.h"
#include "HorasDoblesDiurnas.h"
#include "HorasDoblesMixta.h"
#include "HorasDoblesNocturno.h"
#include "HorasExtraFeriadoLaborado.h"

class ComponenteFactory {
public:
    static ComponenteSalario* crearComponente(TipoComponente tipo, int parametro, float salarioBase);
};
