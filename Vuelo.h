#ifndef VUELO_H
#define VUELO_H
#include "Aeropuerto.h"

class Aeropuerto;
class Vuelo {
	//atributos
	private:
	    unsigned precio;
		Aeropuerto* aeropuertoLlegada;
		Vuelo* siguienteVuelo;

    //metodos
	public:
        Vuelo(unsigned precio, Aeropuerto* aeropuertoLlegada);
        void asignarSiguienteVuelo(Vuelo* siguienteVuelo);
        unsigned obtenerPrecio();
        Aeropuerto* obtenerAeropuertoLlegada();
        Vuelo* obtenerSiguienteVuelo();
};

#endif // VUELO_H
