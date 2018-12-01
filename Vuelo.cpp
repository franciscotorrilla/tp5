#include "Vuelo.h"


Vuelo::Vuelo(unsigned precio, Aeropuerto* aeropuertoLlegada){
	this->precio = precio;
	this->aeropuertoLlegada = aeropuertoLlegada;
	siguienteVuelo = 0;
}


void Vuelo::asignarSiguienteVuelo(Vuelo* siguienteVuelo) {
	this->siguienteVuelo = siguienteVuelo;
}

unsigned Vuelo::obtenerPrecio(){
	return precio;
}

Aeropuerto* Vuelo::obtenerAeropuertoLlegada(){
	return aeropuertoLlegada;
}

Vuelo* Vuelo::obtenerSiguienteVuelo(){
    return siguienteVuelo;
}
