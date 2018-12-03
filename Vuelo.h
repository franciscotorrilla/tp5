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
	    //constructor
	    //pre: recibe el precio y un puntero al aeropuerto de llegada
	    //pos: se crea el vuelo
        Vuelo(unsigned precio, Aeropuerto* aeropuertoLlegada);

        //pre: recibe un puntero al siguiente vuelo
        //pos: coloca el vuelo recibido como siguiente vuelo
        void asignarSiguienteVuelo(Vuelo* siguienteVuelo);

        //pre: -
        //pos: devuelve el precio del vuelo
        unsigned obtenerPrecio();

        //pre: -
        //pos: devuelve un puntero al aeropuerto de llegada
        Aeropuerto* obtenerAeropuertoLlegada();

        //pre: -
        //pos: devuelve un puntero al siguiente vuelo
        Vuelo* obtenerSiguienteVuelo();
};

#endif // VUELO_H
