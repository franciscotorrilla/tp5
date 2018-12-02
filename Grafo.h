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
        Aeropuerto* buscarAeropuerto(string codigo);
        Aeropuerto* aeropuertoIncluido(Aeropuerto* aeropuertoNuevo);
        void agregarAeropuertoFinal(Aeropuerto* aeropuertoNuevo);
};

#endif // GRAFO_H
