#ifndef AEROPUERTO_H
#define AEROPUERTO_H
#include <iostream>
#include "Vuelo.h"
using namespace std;

class Vuelo;
struct dato{
    string nombre;
    string ciudad;
    string pais;
};


class Aeropuerto {
	//atributos
	private:
	    string codigo;
	    dato* datos;
		Vuelo* primerVuelo;
		Aeropuerto* siguienteAeropuerto;

    //metodos
	public:
        Aeropuerto(string codigo, dato* datos);
        void asignarCodigo(string codigo);
        void asignarDatos(dato* datos);
        void asignarPrimerVuelo(Vuelo* primerVuelo);
        void asignarSiguienteAeropuerto(Aeropuerto* siguienteAeropuerto);
        string obtenerCodigo();
        dato* obtenerDatos();
        Vuelo* obtenerPrimerVuelo();
        Aeropuerto* obtenerSiguienteAeropuerto();
        void asignarVuelo(Vuelo* vuelo);
        ~Aeropuerto();
};

#endif // AEROPUERTO_H
