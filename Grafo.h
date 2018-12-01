#ifndef GRAFO_H
#define GRAFO_H
#include "Aeropuerto.h"

class Grafo {
	//atributos
	private:
		Aeropuerto* primerAeropuerto;

	public:
	//metodos
	Grafo(Aeropuerto* primerAeropuerto);
	Aeropuerto* obtenerPrimerAeropuerto();
	~Aeropuerto();
};

#endif // GRAFO_H
