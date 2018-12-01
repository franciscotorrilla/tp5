#include "Nodo.h"


Nodo::Nodo ( Tipo* dato) {
	this->dato = dato;
	siguiente = 0;
}

void Nodo::asignarSiguiente ( Nodo* punteroNodo) {
	siguiente = punteroNodo;
}

Tipo* Nodo::obtener() {
	return dato;
}

Nodo* Nodo::obtenerSiguiente(){
	return siguiente;
}

Nodo::~Nodo(){
    delete dato;
}
