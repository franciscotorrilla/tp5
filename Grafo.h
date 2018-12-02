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
        void asignarPrimerAeropuerto(Aeropuerto* aeropuerto);
        Aeropuerto* obtenerPrimerAeropuerto();

        //pre: recibe un codigo
        //post: de ser posible devuelve el aeropuerto al que pertenece
        // ese codigo, sino devuelve el ultimo aeropueto del grafo.
        Aeropuerto* aeropuertoIncluido(string codigo);
        void agregarAeropuertoFinal(Aeropuerto* aeropuertoNuevo);
};

#endif // GRAFO_H
