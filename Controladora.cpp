#include "Controladora.h"
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <exception>
using namespace std;
Controladora* Controladora::instancia = nullptr;


Controladora::Controladora() {
    Empleado* emp1 = new Empleado("1", "Minor", "Programador", 1000000);
    Empleado* emp2 = new Empleado("2", "Isaac", "Programador", 2000000);
    empleados.agregar(emp1);
    empleados.agregar(emp2);
    cout << "Controladora inicializada" << endl;
}
Controladora* Controladora::getInstance() {
    if (instancia == nullptr) {
        instancia = new Controladora();
    }
    return instancia;
}


Controladora::~Controladora() {
    if (instancia == this) {
        instancia = nullptr;
    }

    for (int i = 0; i < empleados.size(); ++i) {
        Empleado* emp = static_cast<Empleado*>(empleados.get(i));
        delete emp;
    }
    empleados.clear();
}



void Controladora::ejecutar() {
    int opcion = 0;
    do {
        try {
            system("cls");
            cout << "             [Menu Principal]                  " << endl << endl;
			cout << "0. ver empleados registrados" << endl << endl;
            cout << "1. Manual de Usuario" << endl;
            cout << "2. Registrar Empleado" << endl;
            cout << "3. Buscar/Editar Empleado" << endl;
            cout << "4. Calcular Ingresos y Deducciones" << endl;
            cout << "5. Generar Planilla" << endl;
            cout << "6. Salir" << endl << endl;
            cout << "Seleccione una opcion: " << endl;
            cout << "Opcion --> ";
            
            if (!(cin >> opcion)) {
                cin.clear(); 
                cin.ignore(1000, '\n'); 
                throw exception("Error: Entrada invalida. Debe ingresar un numero.");
            }

            cin.ignore();

            switch (opcion) {
            case 0:
                system("cls");
                cout << "----[Empleados Registrados]----" << endl << endl;
                if (empleados.size() == 0) {
                    cout << "No hay empleados registrados." << endl;
                }
                else {
                    for (int i = 0; i < empleados.size(); ++i) {
						empleados.toString();
                    }
                }
                pausarPantalla();
				break;
            case 1:
                try {
                    mostrarManual();
                    pausarPantalla();
                }
                catch (exception& e) {
                    cout << "Error al mostrar manual: " << e.what() << endl;
                }
                break;
            case 2:
                try {
                    registrarEmpleado();
                    pausarPantalla();
                }
                catch (exception& e) {
                    cout << "Error al registrar empleado: " << e.what() << endl;
                }
                break;
            case 3:
                try {
                    buscarEmpleado();
                }
                catch (exception& e) {
                    cout << "Error al buscar empleado: " << e.what() << endl;
                }
                break;
            case 4:
                try {
                    calcularSubmenu();
                    pausarPantalla();
                }
                catch (exception& e) {
                    cout << "Error al calcular deducciones: " << e.what() << endl;
                }
                break;
            case 5:
                try {
                    generarPlanilla();
                    pausarPantalla();
                }
                catch (exception& e) {
                    cout << "Error al generar planilla: " << e.what() << endl;
                }
                break;
            case 6:
                try {
                    salir();
                }
                catch (exception& e) {
                    cout << "Error al salir: " << e.what() << endl;
                }
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                pausarPantalla();
                break;
            }
        }
        catch (exception& e) {
            cout << e.what() << endl;
            pausarPantalla();
        }
    } while (opcion != 6);
}

void Controladora::mostrarManual() {
    system("cls");
    cout << "             [Manual de Usuario]                  " << endl << endl;
    cout << "Este sistema de nomina permite:" << endl << endl;
    cout << "1) Registrar empleados con: nombre, cedula, puesto y salario base" << endl;
    cout << "2) Buscar un empleado por cedula y editar sus datos basicos (Opcional)" << endl;
    cout << "3) Ingresar al submenu de calculo para un empleado:" << endl;
    cout << "   - Registrar horas ordinarias, horas extra, dobles, bonificaciones y deducciones" << endl;
    cout << "   - Calcular salario bruto y salario neto." << endl;
    cout << "4) Generar planilla en pantalla mostrando:" << endl;
    cout << "   - Salario bruto, deducciones y salario neto de un colaborador." << endl << endl;
    cout << "Para cada operacion, siga las instrucciones que apareceran al seleccionar la opcion." << endl << endl;


	cout << "Patrones de diseno utilizados:" << endl << endl;
    cout << "1) Builder"<<endl;
    cout << "   - IngresoBuilder: construye paso a paso los componentes del salario"<<endl;
    cout << "   - DeduccionBuilder: arma y agrupa deducciones en un composite."<<endl<<endl;

    cout << "2) Factory Method"<<endl;
    cout << "   - DeduccionFactory y ComponenteFactory: crean objetos concretos sin acoplar."<<endl<<endl;

    cout << "3) Singleton"<<endl;
    cout << "   - (Opcional) ValoresDefaultCCSS: unica instancia para tasas por defecto."<<endl<<endl;

    cout << "4) Delegation y Composite"<<endl;
    cout << "   - DeduccionCompuesta delega aplicar() a cada subDeduccion."<<endl<<endl;

	cout << "5) Uso de Excepciones" << endl;
	cout << "   - Manejo de errores en entradas de usuario y operaciones." << endl << endl;
    pausarPantalla();
   
}

void Controladora::registrarEmpleado() {
    try {
        system("cls");
        cout << "----[Registrar Empleado]----" << endl << endl;

        string cedula, nombre, puesto;
        float salarioBase;

        cout << "Cedula (ID): ";
        getline(cin, cedula);

        if (cedula.empty()) {
            throw exception("Error: La cedula no puede estar vacia.");
        }

        if (buscarEmpleadoPorCedula(cedula) != nullptr) {
            throw exception("Error: Ya existe un empleado con esa cedula.");
        }

        cout << "Nombre completo: ";
        getline(cin, nombre);
        if (nombre.empty()) {
            throw exception("Error: El nombre no puede estar vacio.");
        }

        cout << "Puesto: ";
        getline(cin, puesto);
        if (puesto.empty()) {
            throw exception("Error: El puesto no puede estar vacio.");
        }

        cout << "Salario base mensual: ";
        if (!(cin >> salarioBase)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw exception("Error: El salario base debe ser un numero.");
        }

        if (salarioBase <= 0) {
            throw exception("Error: El salario base debe ser mayor a cero.");
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        Empleado* nuevo = new Empleado(cedula, nombre, puesto, salarioBase);
  
        empleados.agregar(nuevo);
        cout << "Empleado registrado exitosamente." << endl;
    }
    catch (exception& e) {
        cout << e.what() << endl;
        pausarPantalla();
    }
}

void Controladora::buscarEmpleado() {
    system("cls");
    cout << "----[Buscar / Editar Empleado]----" << endl << endl;
    string cedula;
    cout << "Ingrese la cedula del empleado que desea buscar: ";
    getline(cin, cedula);

    Empleado* emp = buscarEmpleadoPorCedula(cedula);
    if (!emp) {
        cout << "No se encontro ningun empleado con cedula " << cedula << endl;
        pausarPantalla();
        return;
    }

    cout << "Empleado encontrado:" << endl;
    cout << "Cedula: " << emp->getCedula() << endl;
    cout << "Nombre: " << emp->getNombre() << endl;
    cout << "Puesto: " << emp->getPuesto() << endl;
    cout << "Salario Base: " << emp->getSalarioBase() << endl << endl;
    editarEmpleado(emp);
}

void Controladora::editarEmpleado(Empleado* emp) {
    int opcion = 0;
    do {
        system("cls");
        cout << "-----[Editar Empleado]-----" << endl << endl;
        cout << "1. Cambiar Nombre" << endl;
        cout << "2. Cambiar cedula" << endl;
        cout << "3. Cambiar Puesto" << endl;
        cout << "4. Cambiar Salario Base" << endl;
        cout << "5. Volver al menu principal" << endl << endl;
        cout << "Seleccione una opcion: " << endl;
        cout << "Opcion --> ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1: {
            system("cls");
            string nuevoNombre;
            cout << "Ingrese nuevo nombre: ";
            getline(cin, nuevoNombre);
            emp->setNombre(nuevoNombre);
            cout << "Nombre actualizado." << endl;
            pausarPantalla();
            break;
        }
        case 2: {
            system("cls");
            string nuevaCedula;
            cout << "Ingrese nueva cedula: ";
            getline(cin, nuevaCedula);
            if (buscarEmpleadoPorCedula(nuevaCedula) != nullptr) {
                cout << "Ya existe un empleado con la cedula " << nuevaCedula << endl;
                pausarPantalla();
                break;
            }
            emp->setCedula(nuevaCedula);
            cout << "Cedula actualizada." << endl;
            pausarPantalla();
            break;
        }
        case 3: {
            system("cls");
            string nuevoPuesto;
            cout << "Ingrese nuevo puesto: ";
            getline(cin, nuevoPuesto);
            emp->setPuesto(nuevoPuesto);
            cout << "Puesto actualizado." << endl;
            pausarPantalla();
            break;
        }
        case 4: {
            system("cls");
            float nuevoSalario;
            cout << "Ingrese nuevo salario base: ";
            cin >> nuevoSalario;
            emp->setSalarioBase(nuevoSalario);
            cout << "Salario base actualizado." << endl;
            pausarPantalla();
            break;
        }
        case 5:
            break;
        default:
            cout << "Opcion invalida" << endl;
            pausarPantalla();
            break;
        }
    } while (opcion != 5);
}


void Controladora::calcularSubmenu() {
    system("cls");

    cout << "----[Submenu de Calculo]----" << endl << endl;
    string cedula;
    cout << "Ingrese la cedula del empleado: ";
    getline(cin, cedula);

    Empleado* emp = buscarEmpleadoPorCedula(cedula);
    if (!emp) {
        cout << "No se encontro ningun empleado con cedula " << cedula << endl;
        pausarPantalla();
        return;
    }
    ingresarDatosCalculo(emp);
}

void Controladora::generarPlanilla() {
    try {
        system("cls");

        int numeroPlanilla;
        string periodo, fecha;

        cout << "----[Generar Planilla]----"<<endl<<endl;
        cout << "Ingrese el numero de planilla: ";
        if (!(cin >> numeroPlanilla)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw exception("Error: El numero de planilla debe ser un numero.");
        }

        if (numeroPlanilla <= 0) {
            throw exception("Error: El numero de planilla debe ser mayor a cero.");
        }

        cin.ignore();

        cout << "Ingrese el periodo (ej. Enero 2023): ";
        getline(cin, periodo);
        if (periodo.empty()) {
            throw exception("Error: El periodo no puede estar vacio.");
        }

        cout << "Ingrese la fecha de generacion: ";
        getline(cin, fecha);
        if (fecha.empty()) {
            throw exception("Error: La fecha no puede estar vacia.");
        }

        Planilla planilla(numeroPlanilla, periodo, fecha, empleados);

        int opcion;
        do {
            try {
                system("cls");
                cout << "----[Agregar Empleados a Planilla #" << numeroPlanilla << "]----"<<endl<<endl;
                cout << "1. Agregar empleado por cedula"<<endl;
                cout << "2. Generar planilla con los empleados seleccionados"<<endl;
                cout << "3. Imprimir TXT"<<endl;
                cout << "4. Cancelar"<<endl;
                cout << "Empleados agregados: " << planilla.getCantidadEmpleados() <<endl;
                cout << "Opcion: ";

                if (!(cin >> opcion)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw exception("Error: La opcion debe ser un numero.");
                }

                cin.ignore();

                switch (opcion) {
                case 1: {
                    string cedula;
                    cout << "Ingrese la cedula del empleado: ";
                    getline(cin, cedula);
                    if (cedula.empty()) {
                        throw exception("Error: La cedula no puede estar vacia.");
                    }
                    planilla.agregarEmpleado(cedula);
                    cout << "Presione ENTER para continuar...";
                    cin.get();
                    break;
                }
                case 2:
                    if (planilla.getCantidadEmpleados() > 0) {
                        planilla.generarReportePantalla();
                        cout << "Presione ENTER para volver al menu principal...";
                        cin.get();
                        return;
                    }
                    else {
                        cout << "Debe agregar al menos un empleado a la planilla."<<endl;
                        cout << "Presione ENTER para continuar...";
                        cin.get();
                    }
                    break;
                case 3: {
                 
                    if (planilla.getCantidadEmpleados() > 0) {
                        ReporteTXT reporte;
                        reporte.imprimir(planilla);
                    }
                    else {
                        cout << "Debe agregar al menos un empleado antes de generar el TXT." << endl;
                    }
                    cout << "Presione ENTER para continuar...";
                    cin.get();
                    break;
                }  
                case 4:
                    break;
 
                default:
                    cout << "Opcion invalida.\n";
                    cout << "Presione ENTER para continuar...";
                    cin.get();
                    break;
                }
            }
            catch (exception& e) {
                cout << e.what() << endl;
                cout << "Presione ENTER para continuar...";
                cin.get();
            }
        } while (opcion != 3);
    }
    catch (exception& e) {
        cout << e.what() << endl;
        cout << "Presione ENTER para continuar...";
        cin.get();
    }
}

void Controladora::ingresarDatosCalculo(Empleado* emp){
    IngresoBuilder* ingresoBuilder = new IngresoBuilder(emp->getSalarioBase());
    DeduccionBuilder* deduccionBuilder = new DeduccionBuilder;
    deduccionBuilder->conTipoCCSS()->conTipoRenta();

    DeduccionCompuesta* deduccionesCompuestas = nullptr;
    int opcion = 0;
    do {
        system("cls");
        cout << "----[Submenu calular]" << endl;
        cout << "1.Ingresos" << endl;
        cout << "2.Deducciones" << endl;
        cout << "3.Calcular" << endl;
        cout << "4.Volver al menu principal" << endl << endl;
        cout << "Seleccione una opcion: " << endl;
        cout << "Opcion --> ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            system("cls");
            cout << "----[Ingresos]----" << endl << endl;
            cout << "0. Volver al submenu de calculo" << endl;
            cout << "1. Registrar Bonificacion por monto fijo" << endl;
            cout << "2. Registrar Bonificacion por porcentaje" << endl;
            cout << "3. Registrar Horas ordinarias ajuste diurno" << endl;
            cout << "4. Registrar Horas ordinarias ajuste Mixta" << endl;
            cout << "5. Registrar Horas ordinarias ajuste nocturno" << endl;
            cout << "6. Registrar Horas extra Diurna" << endl;
            cout << "7. Registrar Horas extra Mixta" << endl;
            cout << "8. Registrar Horas extra Nocturna" << endl;
            cout << "9. Registrar dobles Diurna" << endl;
            cout << "10. Registrar dobles Mixta" << endl;
            cout << "11. Registrar dobles Nocturna" << endl;
            cout << "12. Registrar horas feriadas laboradas" << endl;
            cout << "13. Registrar horas extra feriadas laboradas" << endl << endl;
            int subOpcion;
            cout << "Seleccione una opcion: ";
            cin >> subOpcion;

            switch (subOpcion) {
            case 1: {
                system("cls");
                double montoFijo;
                cout << "Ingrese monto fijo de bonificacion: ";
                cin >> montoFijo;
                ingresoBuilder->agregarBonificacionMontoFijo(montoFijo);
                pausarPantalla();
                break;
            }
            case 2: {
                double porcentaje;
                cout << "Ingrese porcentaje de bonificacion: ";
                cin >> porcentaje;
                ingresoBuilder->agregarBonificacionPorcentaje(porcentaje);
                pausarPantalla();
                break;
            }
            case 3: {
                system("cls");
                int horas;
                cout << "Ingrese cantidad de horas ordinarias ajuste diurno: ";
                cin >> horas;
                ingresoBuilder->agregarHorasOrdinarias(horas);
                pausarPantalla();
                break;
            }
            case 4: {
                system("cls");
                int horas;
                cout << "Ingrese cantidad de horas ordinarias ajuste Mixta: ";
                cin >> horas;
                ingresoBuilder->agregarHorasOrdinariasMixta(horas);
                pausarPantalla();
                break;
            }
            case 5: {
                system("cls");
                int horas;
                cout << "Ingrese cantidad de horas ordinarias ajuste nocturno: ";
                cin >> horas;
                ingresoBuilder->agregarHorasOrdinariasNocturnas(horas);
                pausarPantalla();
                break;
            }
            case 6: {
                system("cls");
                int horas;
                cout << "Ingrese cantidad de horas extra diurna: ";
                cin >> horas;
                ingresoBuilder->agregarHorasExtraDiurna(horas);
                pausarPantalla();
                break;
            }
            case 7: {
                system("cls");
                int horas;
                cout << "Ingrese cantidad de horas extra Mixta: ";
                cin >> horas;
                ingresoBuilder->agregarHorasExtraMixta(horas);
                pausarPantalla();
                break;
            }
            case 8: {
                system("cls");
                int horas;
                cout << "Ingrese cantidad de horas extra nocturna: ";
                cin >> horas;
                ingresoBuilder->agregarHorasExtraNocturna(horas);
                pausarPantalla();
                break;
            }
            case 9: {
                system("cls");
                int horas;
                cout << "Ingrese cantidad de horas dobles diurna: ";
                cin >> horas;
                ingresoBuilder->agregarHorasDoblesDiurnas(horas);
                pausarPantalla();
                break;
            }
            case 10: {
                system("cls");
                int horas;
                cout << "Ingrese cantidad de horas dobles Mixta: ";
                cin >> horas;
                ingresoBuilder->agregarHorasDoblesMixta(horas);
                pausarPantalla();
                break;
            }
            case 11: {
                system("cls");
                int horas;
                cout << "Ingrese cantidad de horas dobles nocturna: ";
                cin >> horas;
                ingresoBuilder->agregarHorasDoblesNocturna(horas);
                pausarPantalla();
                break;
            }
            case 12: {
                system("cls");
                int horas;
                cout << "Ingrese cantidad de horas feriadas laboradas: ";
                cin >> horas;
                ingresoBuilder->agregarHorasFeriadoLaborado(horas);
                pausarPantalla();
                break;
            }
            case 13: {
                system("cls");
                int horas;
                cout << "Ingrese cantidad de horas extra feriadas laboradas: ";
                cin >> horas;
                ingresoBuilder->agregarHorasExtraFeriadoLaborado(horas);
                pausarPantalla();
                break;
            }
            case 0:
                break;
            default:
                cout << "Opcion invalida en el submenu de ingresos." << endl;
                pausarPantalla();
                break;
            }
        }

        case 2: {
            pausarPantalla();
            system("cls");
            cout << "----[Deducciones Adicionales]----" << endl << endl;
            cout << "NOTA: Las deducciones de CCSS y Renta ya estan aplicadas automaticamente" << endl << endl;
            cout << "0. Volver al submenu de calculo" << endl;
            cout << "1. Registrar deduccion por monto fijo (adicional)" << endl;
            cout << "2. Registrar deduccion por porcentaje (adicional)" << endl;
            cout << "3. Registrar deduccion por embargo" << endl;
            cout << "4. Registrar deduccion por maternidad" << endl;
			cout << "5. modifcar Deduccion de la caja costarricense del seguro social" << endl;
            int subOpcion;
            cout << "Seleccione una opcion: ";
            cin >> subOpcion;

            switch (subOpcion) {
            case 1: {
                system("cls");
                double montoFijo;
                cout << "Ingrese monto fijo de deduccion: ";
                cin >> montoFijo;
                deduccionBuilder->conMontoFijo(montoFijo);
                pausarPantalla();
                break;
            }
            case 2: {
                system("cls");
                double porcentaje;
                cout << "Ingrese porcentaje de deduccion: ";
                cin >> porcentaje;
                deduccionBuilder->conPorcentaje(porcentaje);
                pausarPantalla();
                break;

            }
            case 3: {
                system("cls");
                deduccionBuilder->conTipoEmbargo();
                pausarPantalla();
                break;

            }
            case 4: {
                system("cls");
                deduccionBuilder->conMaternidad();
                pausarPantalla();
                break;

            }
            case 5: {
                system("cls");
                float nuevoPorcentaje;
                cout << "Ingrese el nuevo porcentaje de CCSS (ej. 26.5): ";
                cin >> nuevoPorcentaje;

                if (deduccionesCompuestas) {
                    deduccionesCompuestas->modificarPorcentajeCCSS(nuevoPorcentaje);
                    cout << "Porcentaje de CCSS actualizado a " << nuevoPorcentaje << "%" << endl;
                }
                else {
                    cout << "Error: Primero debe calcular al menos una vez." << endl;
                }
                pausarPantalla();
                break;
            }
            case 0:
                break;
            default:
                cout << "Opcion invalida en el submenu de deducciones." << endl;
                pausarPantalla();
            }
            break;
        }
        case 3: { // Calcular
            system("cls");
            if (!ingresoBuilder->tieneComponentes()) {
                cout << "Error: No se han registrado ingresos." << endl;
                cout << "Por favor, registre al menos un ingreso." << endl;
                pausarPantalla();
                break;
            }


            Deduccion* deducciones = deduccionBuilder->build();
            deduccionesCompuestas = dynamic_cast<DeduccionCompuesta*>(deducciones);

            double salarioBruto = ingresoBuilder->calcularSalarioBruto();
            double salarioParaDeducciones = salarioBruto;

            if (deduccionesCompuestas) {
                deduccionesCompuestas->aplicar(salarioParaDeducciones);
            }

            float totalDeducciones = salarioBruto - salarioParaDeducciones;
            float salarioNeto = salarioBruto - totalDeducciones;
            emp->setSalariobruto(salarioBruto);
            emp->setSalarioNeto(salarioNeto);

            cout << fixed << setprecision(2);
            cout << "RESUMEN DE SALARIO PARA: " << emp->getNombre() << endl;
            cout << "----------------------------------------" << endl;
            cout << "SALARIO BRUTO: \t\t" << salarioBruto << endl;
            cout << "TOTAL DEDUCCIONES: \t" << totalDeducciones << endl;
            cout << "----------------------------------------" << endl;
            cout << "SALARIO NETO: \t\t" << salarioNeto << endl << endl;
            pausarPantalla();
            break;
        }
        case 4:
            break;
        default:
            cout << "Opcion invalida en el submenu." << endl;
            pausarPantalla();
        }
    } while (opcion != 4);
}

void Controladora::pausarPantalla() {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Presione ENTER para continuar...";
        cin.get(); 
}

Empleado* Controladora::buscarEmpleadoPorCedula(const string& cedula) {
    for (int i = 0; i < empleados.size(); ++i) {
        Empleado* emp = dynamic_cast<Empleado*>(empleados.get(i));
        if (emp && emp->getCedula() == cedula) {
            return emp;
        }
    }
    return nullptr;
}

void Controladora::salir() {
    system("cls");
    cout << "Saliendo del programa..." << endl << endl;
    cout << " Proyecto hecho por:" << endl;
    cout << " -------------------------------------------" << endl;
    cout << "|            Isaac Sibaja Cortes            |" << endl;
    cout << "|            Minor Castillo Loria           |" << endl;
    cout << " -------------------------------------------" << endl;
}
