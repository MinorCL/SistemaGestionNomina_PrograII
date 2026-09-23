#include "Consola.h"
#include <iostream>

Consola::Consola() {
	listaOpciones = new Lista();
	titulo = "";
	instrucciones = "";
}

Consola::~Consola() {
	delete listaOpciones;
}

void Consola::setTitulo(string t) {
	titulo = t;
}

void Consola::setInstrucciones(string i) {
	instrucciones = i;
}

void Consola::agregarOpcion(OpcionMenu* opcion) {
	listaOpciones->agregarFinal(opcion);
}

void Consola::show() {
	limpiar();
	cout << "==================================" << endl;
	cout << "=== " << titulo << endl;
	cout << "==================================" << endl;

	if (!instrucciones.empty()) {
		cout << instrucciones << endl;
	}
	cout << endl;

	for (int i = 0; i < listaOpciones->size(); i++) {
		cout << "\t" << (i + 1) << ". " << listaOpciones->get(i)->toString() << endl;
	}
	cout << endl;
}

void Consola::limpiar() {
#ifdef _WIN32
	system("cls");
#endif
}
