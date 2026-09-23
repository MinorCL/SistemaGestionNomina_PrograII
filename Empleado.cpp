#include "Empleado.h"

Empleado::Empleado() {
    nombre = "";
    cedula = "";
    puesto = "";
    salarioBase = 0.0;
	salarioNeto = 0.0;
	salariobruto = 0.0;
}

Empleado::Empleado(string id, string name, string position, float salary) {
    this->cedula = id;
    this->nombre = name;
    this->puesto = position;
    this->salarioBase = salary;
    salarioNeto = 0.0;
    salariobruto = 0.0;
}

Empleado::~Empleado() {}

string Empleado::getNombre() const {
    return nombre;
}

string Empleado::getCedula() const {
    return cedula;
}

string Empleado::getPuesto() const {
    return puesto;
}

float Empleado::getSalarioBase() const {
    return salarioBase;
}

void Empleado::setSalarioBase(float salary)
{
	this->salarioBase = salary;
}

void Empleado::setNombre(const string& name)
{
	this->nombre = name;
}

void Empleado::setCedula(const string& id) {
	this->cedula = id;
}

void Empleado::setPuesto(const string& position) {
	this->puesto = position;
}

void Empleado::setSalarioNeto(float salary)
{
	this->salarioNeto = salary;
}

void Empleado::setSalariobruto(float salary)
{
	this->salariobruto = salary;
}

float Empleado::getSalarioNeto() const
{
    return salarioNeto;
}

float Empleado::getSalariobruto() const
{
    return salariobruto;
}
string Empleado::toString() const {
    return "Cedula: " + cedula + " | Nombre: " + nombre + " | Puesto: " + puesto + " | Salario: " + to_string(salarioBase);
}

bool Empleado::equals(IObjeto* ref) {
    Empleado* otro = dynamic_cast<Empleado*>(ref);
    if (otro != nullptr) {
        return this->cedula == otro->cedula;
    }
    return false;
}

string Empleado::getType() const {
    return "Empleado";
}

Empleado* Empleado::getEmpleado()
{
    return this;
};
