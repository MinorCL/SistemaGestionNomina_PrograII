#include "ReporteTXT.h"
#include <fstream>
#include <iomanip>

void ReporteTXT::imprimir(const Planilla& planilla) {
    ofstream archivo("planilla_" + std::to_string(planilla.getNumero()) + ".txt");

    if (!archivo.is_open()) {
        cout << "Error al crear el archivo TXT.\n";
        return;
    }

    archivo << fixed << setprecision(2);
    archivo << "PLANILLA #" << planilla.getNumero() << "\n";
    archivo << "Periodo: " << planilla.getPeriodo() << "\n";
    archivo << "Fecha: " << planilla.getFechaGeneracion() << "\n\n";
    archivo << "EMPLEADOS:\n";
    archivo << "-------------------------------------------------------------\n";

    const Lista& empleados = planilla.getEmpleados();
    for (int i = 0; i < empleados.size(); ++i) {
        Empleado* emp = static_cast<Empleado*>(empleados.get(i));

		archivo << "-------------------------------------------------------------\n";
        archivo << "Nombre: " << emp->getNombre() << "\n";
        archivo << "Cedula: " << emp->getCedula() << "\n";
        archivo << "Salario Bruto: " << emp->getSalariobruto() << "\n";
        archivo << "Salario Neto:  " << emp->getSalarioNeto() << "\n";
        archivo << "-------------------------------------------------------------\n";
    }

    archivo.close();
    cout << "Archivo 'planilla_" << planilla.getNumero() << ".txt' generado correctamente.\n";
}
