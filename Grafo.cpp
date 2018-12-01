#include "Grafo.h"


Grafo::Grafo (Aeropuerto* primerAeropuerto) {
	this->primerAeropuerto = primerAeropuerto;
}

Aeropuerto* Aeropuerto::obtenerPrimerAeropuerto() {
	return primerAeropuerto;
}

Aeropuerto::~Aeropuerto(){
    delete dato;
}
