#include "Grafo.h"


Grafo::Grafo(){
	primerAeropuerto = 0;
}

void Grafo::asignarSiguienteAeropuerto(Aeropuerto* aeropuerto){

	if (!primerAeropuerto)
        primerAeropuerto = aeropuerto;
    else{
        Aeropuerto* aeropuertoActual=primerAeropuerto;
        while(aeropuertoActual->obtenerSiguienteAeropuerto())
            aeropuertoActual= aeropuertoActual->obtenerSiguienteAeropuerto();
        aeropuertoActual->asignarSiguienteAeropuerto(aeropuerto);
    }

}

Aeropuerto* Grafo::obtenerPrimerAeropuerto() {
	return primerAeropuerto;
}

Aeropuerto* Grafo::buscarAeropuerto(string codigo) {
    Aeropuerto* actual = primerAeropuerto;
    while(actual) {
        if(codigo == actual->obtenerCodigo())
            return actual;
        else
            actual = actual->obtenerSiguienteAeropuerto();

