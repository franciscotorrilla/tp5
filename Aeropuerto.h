#ifndef AEROPUERTO_H
#define AEROPUERTO_H
#include "Vuelo.h"

struct datos{
    string nombre;
    string ciudad;
    string pais;
};

class Aeropuerto {
	//atributos
	private:
	    string codigo;
	    datos* datos;
		Vuelo* primerVuelo;
		Aeropuerto* siguienteAeropuerto;

    //metodos
	public:
        Aeropuerto(string codigo, datos* datos, Vuelo* primerVuelo, Aeropuerto* siguienteAeropuerto);
        Aeropuerto(string codigo, datos* datos);
        void asignarCodigo(string codigo);
        void asignarDatos(datos* datos);
        void asignarPrimerVuelo(Vuelo* primerVuelo);
        void asignarSiguienteAeropuerto(Aeropuerto* siguienteAeropuerto);
        string obtenerCodigo();
        datos* obtenerDatos();
        Vuelo* obtenerPrimerVuelo();
        Aeropuerto* obtenerSiguienteAeropuerto();
        ~Aeropuerto();
};

#endif // AEROPUERTO_H
