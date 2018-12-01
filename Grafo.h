#ifndef GRAFO_H
#define GRAFO_H
#include "Aeropuerto.h"
#include "Lista.h"

class Grafo {
	//atributos
	private:
		Aeropuerto* primerAeropuerto;

    //metodos
	public:
        Grafo(Aeropuerto* primerAeropuerto);
        Aeropuerto* obtenerPrimerAeropuerto();
};

#endif // GRAFO_H
