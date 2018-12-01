#include "Grafo.h"


Grafo::Grafo (Aeropuerto* primerAeropuerto) {
	this->primerAeropuerto = primerAeropuerto;
}

Aeropuerto* Grafo::obtenerPrimerAeropuerto() {
	return primerAeropuerto;
}

