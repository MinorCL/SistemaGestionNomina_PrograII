#include "Nodo.h"

Nodo::Nodo(ObjectAdaptador* dato, Nodo* sig) {
    this->dato = dato;
    this->siguiente = sig;
}

void Nodo::setSiguiente(Nodo* sig) {
    this->siguiente = sig;
}

void Nodo::setDato(ObjectAdaptador* dato) {
    this->dato = dato;
}

Nodo* Nodo::getSiguiente() const {
    return siguiente;
}

ObjectAdaptador* Nodo::getDato() const {
    return dato;
}
