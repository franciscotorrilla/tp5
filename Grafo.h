#ifndef GRAFO_H
#define GRAFO_H
#include "Aeropuerto.h"

class Grafo {
	//atributos
	private:
		Aeropuerto *primerAeropuerto;

	public:
	//metodos
	Nodo(Tipo* dato);
	Tipo* obtener();
	Nodo* obtenerSiguiente();
	void asignarSiguiente(Nodo* punteroNodo);
	void asignarDato(Tipo* dato);
	~Nodo();
};

#endif // GRAFO_H
