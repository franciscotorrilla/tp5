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

