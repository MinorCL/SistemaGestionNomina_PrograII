#pragma once
#include "Empleado.h"
#include "Lista.h"
#include <string>

class Planilla {
private:
    int numero;
    string periodo;
    string fechaGeneracion;
    Lista& todosEmpleados;   
    Empleado** empleadosSeleccionados; 
    int capacidad;         
    int cantidad;         

    void redimensionarArreglo();

public:
    Planilla(int num, const string& periodo, const string& fecha, Lista& empleadosRef);
    ~Planilla();

    Empleado* getEmpleadoEn(int index) const;
    void agregarEmpleado(const string& cedula);
    void generarReportePantalla() const;
    void limpiarPlanilla();

    int getNumero() const;
    string getPeriodo() const;
    string getFechaGeneracion() const;
    int getCantidadEmpleados() const;
    const Lista& getEmpleados() const;


};

