#ifndef GRAFO_H
#define GRAFO_H
#include "Aeropuerto.h"

class Grafo {
	//atributos
	private:
		Aeropuerto* primerAeropuerto;

    //metodos
	public:
        Grafo();
        void asignarSiguienteAeropuerto(Aeropuerto* aeropuerto);
        Aeropuerto* obtenerPrimerAeropuerto();
};

#endif // GRAFO_H
