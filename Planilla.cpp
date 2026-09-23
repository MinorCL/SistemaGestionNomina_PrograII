// Planilla.cpp
#include "Planilla.h"
#include <iostream>
#include <iomanip>

using namespace std;


Empleado* Planilla::getEmpleadoEn(int index) const {
    if (index >= 0 && index < cantidad)
        return empleadosSeleccionados[index];
    return nullptr;
}

Planilla::Planilla(int num, const std::string& periodo, const std::string& fecha, Lista& empleadosRef)
    : numero(num), periodo(periodo), fechaGeneracion(fecha), todosEmpleados(empleadosRef),
    capacidad(10), cantidad(0) {
    empleadosSeleccionados = new Empleado * [capacidad];
}

Planilla::~Planilla() {
    delete[] empleadosSeleccionados; // Solo liberamos el arreglo, no los empleados (son manejados por Lista)
}

void Planilla::redimensionarArreglo() {
    int nuevaCapacidad = capacidad * 2;
    Empleado** nuevoArreglo = new Empleado * [nuevaCapacidad];

    for (int i = 0; i < cantidad; ++i) {
        nuevoArreglo[i] = empleadosSeleccionados[i];
    }

    delete[] empleadosSeleccionados;
    empleadosSeleccionados = nuevoArreglo;
    capacidad = nuevaCapacidad;
}

void Planilla::agregarEmpleado(const std::string& cedula) {
    // Buscar el empleado en la lista general
    for (int i = 0; i < todosEmpleados.size(); ++i) {
        Empleado* emp = static_cast<Empleado*>(todosEmpleados.get(i));

        if (emp->getCedula() == cedula) {
            // Verificar si ya está en la planilla
            for (int j = 0; j < cantidad; ++j) {
                if (empleadosSeleccionados[j]->getCedula() == cedula) {
                    cout << "El empleado ya está en la planilla.\n";
                    return;
                }
            }

            // Redimensionar si es necesario
            if (cantidad >= capacidad) {
                redimensionarArreglo();
            }

            // Agregar al arreglo
            empleadosSeleccionados[cantidad++] = emp;
            cout << "Empleado agregado a la planilla.\n";
            return;
        }
    }

    cout << "No se encontró un empleado con la cédula " << cedula << ".\n";
}

void Planilla::generarReportePantalla() const {
    system("cls");
    cout << "====================================================================\n";
    cout << "                      PLANILLA DE NOMINA #" << numero << "\n";
    cout << "                      PERIODO: " << periodo << "\n";
    cout << "                      FECHA: " << fechaGeneracion << "\n";
    cout << "====================================================================\n\n";

    cout << std::left << setw(15) << "CEDULA"
        << setw(25) << "NOMBRE"
        << setw(15) << "PUESTO"
        << setw(12) << "SAL.BASE"
        << setw(12) << "SAL.BRUTO"
        << setw(12) << "SAL.NETO"
        << "\n";
    cout << string(100, '-') << "\n";

    for (int i = 0; i < cantidad; ++i) {
        Empleado* emp = empleadosSeleccionados[i];

        // Aquí deberías tener los cálculos reales de salario bruto, deducciones y neto
        double salarioBruto = emp->getSalarioBase();
        double deducciones = salarioBruto * 0.10; // Ejemplo: 10% de deducciones
        double salarioNeto = salarioBruto - deducciones;

        cout << std::left << setw(15) << emp->getCedula()
            << setw(25) << emp->getNombre()
            << setw(15) << emp->getPuesto()
            << fixed << setprecision(2)
            << setw(12) << emp->getSalarioBase()
            << setw(12) << emp->getSalariobruto()
		<< setw(12) << emp->getSalarioNeto()
            << "\n";
    }

    cout << "\n====================================================================\n";
    cout << "                 FIN DEL REPORTE DE PLANILLA\n";
    cout << "                 TOTAL EMPLEADOS: " << cantidad << "\n";
    cout << "====================================================================\n";
}

void Planilla::limpiarPlanilla() {
    cantidad = 0; // Simplemente reiniciamos el contador (no liberamos memoria de empleados)
}

// Implementaciones de getters
int Planilla::getNumero() const { return numero; }
string Planilla::getPeriodo() const { return periodo; }
string Planilla::getFechaGeneracion() const { return fechaGeneracion; }
int Planilla::getCantidadEmpleados() const { return cantidad; }

const Lista& Planilla::getEmpleados() const
{
	return todosEmpleados; 
}


