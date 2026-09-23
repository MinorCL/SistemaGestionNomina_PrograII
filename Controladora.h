#pragma once
#include "Consola.h"
#include "Menu.h"
#include "Empleado.h"
#include "IngresoBuilder.h"
#include "DeduccionBuilder.h"
#include "ColillaPago.h"
#include "Lista.h"
#include"Planilla.h"
#include <string>
#include <iostream>
#include "ReporteTXT.h"
#include <limits>

using namespace std;

class Controladora {
private:
    Lista empleados; 
    Empleado* buscarEmpleadoPorCedula(const string& cedula);

    void mostrarManual();        
    void registrarEmpleado();     
    void buscarEmpleado();        
    void editarEmpleado(Empleado* emp);
    void calcularSubmenu();       
    void generarPlanilla();        
    void salir();                 
    void ingresarDatosCalculo(Empleado* emp);
    void pausarPantalla();


    Controladora();

    static Controladora* instancia;


public:
    ~Controladora();
    static Controladora* getInstance();
    void ejecutar();              
     
};





