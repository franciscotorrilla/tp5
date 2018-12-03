#ifndef GRAFO_H
#define GRAFO_H
#include "Aeropuerto.h"

class Grafo {
	//atributos
	private:
		Aeropuerto* primerAeropuerto;

    //metodos
	public:
	    //constructor
	    //pre: -
	    //pos: construye un grafo vacio, con primerAeropuerto = 0
        Grafo();

        //pre: recibe un puntero a un aeropuerto
        //post: asigna ese aeropuerto como primerAeropuerto
        void asignarPrimerAeropuerto(Aeropuerto* aeropuerto);

        //pre: -
        //pos: devuelve un puntero al primer aeropuerto
        Aeropuerto* obtenerPrimerAeropuerto();

        //pre: recibe un codigo IATA
        //pos: de existir en el grafo, devuelve el aeropuerto al que pertenece
        // ese codigo, sino devuelve el ultimo aeropueto del grafo.
        Aeropuerto* aeropuertoIncluido(string codigo);

        //pre: recibe un puntero a un nuevo aeropuerto
        //pos: agrega el nuevo aeropuerto al final
        void agregarAeropuertoFinal(Aeropuerto* aeropuertoNuevo);

        //pre: recibe el codigo IATA de un aeropuerto
        //pos: devuelve la posicion dentro del grafo del aeropuerto
        unsigned obtenerPosicion(string codigo);

        //pre: recibe un codigo IATA
        //pos: devuelve un puntero al aeropuerto que le pertenece ese codigo
        Aeropuerto* obtenerAeropuerto(string codigo);

        //pre: recibe el codigo IATA del aeropuerto de partida y del de llegada
        //pos: devuelve, de existir, la ruta de menor costo entre los dos aeropuertos con su costo total
        void rutaMinima(string codigo1, string codigo2);

        //destructor
        ~Grafo();


    private:

        //pre: -
        //pos: devuelve la cantidad de aeropuertos del grafo
        unsigned cantidadAeropuertos();

        void incluirCodigos(string *vec);
};

#endif // GRAFO_H
