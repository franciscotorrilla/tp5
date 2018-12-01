#ifndef GRAFO_H
#define GRAFO_H
#include "Aeropuerto.h"

class Grafo {
	//atributos
	private:
		Aeropuerto* primerAeropuerto;

    //metodos
	public:
        Grafo(Aeropuerto* primerAeropuerto);
        Aeropuerto* obtenerPrimerAeropuerto();
        ~Aeropuerto();
};

#endif // GRAFO_H
