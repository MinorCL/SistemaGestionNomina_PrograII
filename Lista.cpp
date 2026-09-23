#include "Lista.h"
#include <sstream>
#include "IteradorLista.h"
using namespace std;

Lista::Lista() {
    root = NULL;
}

void Lista::agregar(ObjectAdaptador* dato) {
    root = new Nodo(dato, root);
}

bool Lista::removerInicio() {
    if (!vacio()) {
        Nodo* tmp = root;
        root = root->getSiguiente();
        delete tmp;
        return true;
    }
    return false;
}

void Lista::clear() {
    while (!vacio()) {
        removerInicio();
    }
}

int Lista::size() const {


    int contador = 0;
    IIterador* it = getIterador();
    while (it->hasMore()) {
        contador++;
        it->next();
    }
    return contador;
}

ObjectAdaptador* Lista::get(int pos) const {
    // Nodo* tmp = root;
    // while (tmp != NULL && pos > 0) {
    //     pos--;
    //     tmp = tmp->getSiguiente();
    // }
    // if (pos == 0) {
    //     return tmp->getDato();
    // }
    // throw exception("Elemento no encontrado");


    IIterador* it = getIterador();
    while (it->hasMore()) {
        ObjectAdaptador* actual = it->next();
        if (pos-- == 0) {
            return actual;
        }
    }
    throw exception("Elemento no encontrado");
}

string Lista::toString() const {
    // stringstream r;
    // Nodo* tmp = root;
    // r << "{";
    // while (tmp != NULL) {
    //     r << tmp->getDato()->toString();
    //     if (tmp->getSiguiente() != NULL) {
    //         r << ", ";
    //     }
    //     tmp = tmp->getSiguiente();
    // }
    // r << "}";
    // return r.str();

    stringstream r;
    IIterador* it = getIterador();
    r << "{";
    while (it->hasMore()) {
        r << it->next()->toString();
        if (it->hasMore()) {
            r << ", ";
        }
    }
    r << "}";
    return r.str();
}

IIterador* Lista::getIterador() const {
    return new IteradorLista(root);
}

bool Lista::vacio() const {
    return root == NULL;
}

void Lista::remover(ObjectAdaptador* dato) {
    root = remover(root, dato);
}

void Lista::agregarFinal(ObjectAdaptador* dato) {
    if (vacio()) {
        agregar(dato);
    }
    else {
        Nodo* actual = root;
        while (actual->getSiguiente() != NULL) {
            actual = actual->getSiguiente();
        }
        actual->setSiguiente(new Nodo(dato));
    }
}

Nodo* Lista::remover(Nodo* actual, ObjectAdaptador* dato) {
    if (actual == NULL) {
        return NULL;
    }
    else if (actual->getDato()->equals(dato)) {
        return actual->getSiguiente();
    }
    actual->setSiguiente(remover(actual->getSiguiente(), dato));
    return actual;
}

// void Lista::remover(ObjectAdaptador* porEliminar) {
//     root = remover(root, porEliminar);
// }
// 
// Nodo* Lista::remover(Nodo* actual, ObjectAdaptador* porEliminar) {
//     if (actual == NULL) {
//         return NULL;
//     }
//     else if (actual->getDato()->equals(porEliminar)) {
//         return actual->getSiguiente();
//     }
//     actual->setSiguiente(remover(actual->getSiguiente(), porEliminar));
//     return actual;
// }
