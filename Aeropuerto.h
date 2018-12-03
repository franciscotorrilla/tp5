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
	    //constructor
	    //pre: recibe el codigo IATA y los datos del aeropuerto
	    //post: crea el aeropuerto
        Aeropuerto(string codigo, dato* datos);

        //pre: recibe un codigo IATA
        //pos: le asigna el codigo
        void asignarCodigo(string codigo);


        //pre: recibe los datos del aeropuerto
        //pos: le asigna los datos al aeropuerto
        void asignarDatos(dato* datos);

        //pre: recibe un puntero a un vuelo
        //pos: le asigna ese vuelo como primer vuelo del aeropuerto
        void asignarPrimerVuelo(Vuelo* primerVuelo);

        //pre: recibe un puntero a un aeropuerto
        //pos: le asigna al aeropuerto su suiguiente aeropuerto
        void asignarSiguienteAeropuerto(Aeropuerto* siguienteAeropuerto);

        //pre:-
        //post: devuelve el codigo IATA del aeropuerto
        string obtenerCodigo();

        //pre: -
        //post: devuelve un puntero a los datos del aeropuerto
        dato* obtenerDatos();

        //pre: -
        //post: devuelve un puntero al primer vuelo del aeropuerto
        Vuelo* obtenerPrimerVuelo();

        //pre: -
        //post: devuelve un puntero al siguiente aeropuerto
        Aeropuerto* obtenerSiguienteAeropuerto();

        //pre: recibe un puntero a un vuelo
        //post: le asigna el vuelo despues del ultimo vuelo que tenia el aeropuerto
        void asignarVuelo(Vuelo* vuelo);

        //destructor
        //pre: -
        //pos: borra los datos del aeropuerto
        ~Aeropuerto();
};

#endif // AEROPUERTO_H
