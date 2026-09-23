#pragma once
class ComponenteSalario {
    protected:
		float salarioBase;
public:
    virtual ~ComponenteSalario() = default;
    virtual int calcular() const = 0; 
	virtual void setSalarioBase(float salarioBase) = 0; 
};

enum TipoComponente {
    BONIFICACION_MONTO_FIJO,
    BONIFICACION_PORCENTAJE,
    HORAS_ORDINARIAS_DIURNO,
    HORAS_ORDINARIAS_MIXTA,
    HORAS_ORDINARIAS_NOCTURNO,
    HORAS_EXTRA_DIURNA,
    HORAS_EXTRA_MIXTA,
    HORAS_EXTRA_NOCTURNA,
    HORAS_DOBLES_DIURNA,
    HORAS_DOBLES_MIXTA,
    HORAS_DOBLES_NOCTURNO,
    HORAS_FERIADO_LABORADO,
    HORAS_EXTRA_FERIADO_LABORADO
};