#pragma once
#include "ObjectAdaptador.h"
#include <iostream>
using namespace std;

class Empleado : public ObjectAdaptador {
private:
    string nombre;
    string cedula;
    string puesto;
    float salarioBase;
	float salariobruto;
	float salarioNeto;
    float deducciones;

public:
    Empleado();
    Empleado(string, string, string, float);
    ~Empleado();

    
    string getNombre() const;
    string getCedula() const;
    string getPuesto() const;
    float getSalarioBase() const;
	void setSalarioBase(float salary);
    void setNombre(const string& name);
    void setCedula(const string& id);
    void setPuesto(const string& position);
    void setSalarioNeto(float salary);
	void setSalariobruto(float salary);
	float getSalarioNeto() const;
	float getSalariobruto() const;
    virtual string toString() const override;
    virtual bool equals(IObjeto* ref) override;
    virtual string getType() const override;
    Empleado* getEmpleado();
};


