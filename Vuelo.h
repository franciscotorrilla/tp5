#ifndef VUELO_H
#define VUELO_H
#include "Aeropuerto.h"

class Vuelo {
	//atributos
	private:
	    unsigned precio;
		Aeropuerto* aeropuertoLlegada;
		Vuelo* siguienteVuelo;

	public:
	//metodos
	Vuelo(unsigned precio, Aeropuerto* aeropuertoLlegada);
    void asignarSiguienteVuelo(Vuelo* siguienteVuelo);
	unsigned obtenerPrecio();
	Aeropuerto* obtenerAeropuertoLlegada();
	Vuelo* obtenerSiguienteVuelo();
};

#endif // VUELO_H
