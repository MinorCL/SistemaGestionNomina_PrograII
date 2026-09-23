#pragma once
#include <string>
#include "ObjectAdaptador.h"

class Nodo : public ObjectAdaptador {
private:
	Nodo* siguiente;
	ObjectAdaptador* dato;
public:
	Nodo(ObjectAdaptador*, Nodo* = NULL);
	virtual void setSiguiente(Nodo*);
	virtual void setDato(ObjectAdaptador*);
	virtual Nodo* getSiguiente() const;
	virtual ObjectAdaptador* getDato() const;
};
