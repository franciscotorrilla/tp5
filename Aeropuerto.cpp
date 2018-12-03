#include "Aeropuerto.h"

Aeropuerto::Aeropuerto (string codigo, dato* datos){
	this->codigo = codigo;
	this->datos = datos;
	primerVuelo = 0;
	siguienteAeropuerto = 0;
}

void Aeropuerto::asignarCodigo(string codigo){
	this->codigo = codigo;
}

void Aeropuerto::asignarDatos(dato* datos){
	this->datos = datos;
}

void Aeropuerto::asignarPrimerVuelo(Vuelo* primerVuelo){
	this->primerVuelo = primerVuelo;
}

void Aeropuerto::asignarSiguienteAeropuerto(Aeropuerto* siguienteAeropuerto){
	this->siguienteAeropuerto = siguienteAeropuerto;
}

string Aeropuerto::obtenerCodigo(){
    return codigo;
}

dato* Aeropuerto::obtenerDatos(){
    return datos;
}

Vuelo* Aeropuerto::obtenerPrimerVuelo(){
    return primerVuelo;
}

Aeropuerto* Aeropuerto::obtenerSiguienteAeropuerto(){
    return siguienteAeropuerto;
}

void Aeropuerto::asignarVuelo(Vuelo* vuelo){
    if (!primerVuelo)
        asignarPrimerVuelo(vuelo);
    else{
        Vuelo* vueloActual = primerVuelo;
        while(vueloActual->obtenerSiguienteVuelo())
            vueloActual=vueloActual->obtenerSiguienteVuelo();
        vueloActual->asignarSiguienteVuelo(vuelo);
    }
}

Aeropuerto::~Aeropuerto(){
    delete datos;
}
