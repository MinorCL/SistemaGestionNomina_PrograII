#pragma once
#include "ObjectAdaptador.h"
#include "Lista.h"
#include "Menu.h"

class Consola : public ObjectAdaptador {
private:
	Lista* listaOpciones;
	string titulo;
	string instrucciones;
public:
	Consola();
	virtual ~Consola();
	virtual void setTitulo(string);
	virtual void setInstrucciones(string);
	virtual void agregarOpcion(OpcionMenu*);
	virtual void show();
	virtual void lanzar(int) = 0;
	static void limpiar();
};