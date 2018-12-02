#include "Grafo.h"


Grafo::Grafo(){
	primerAeropuerto = 0;
}

Aeropuerto* Grafo::obtenerPrimerAeropuerto() {
	return primerAeropuerto;
}

void Grafo::asignarPrimerAeropuerto(Aeropuerto* primerAeropuerto) {
	this->primerAeropuerto = primerAeropuerto;
}


Aeropuerto* Grafo::aeropuertoIncluido (string codigo){
    if (!primerAeropuerto)
        return 0;
    else {
        Aeropuerto* aeropuertoActual = primerAeropuerto;
        while (aeropuertoActual->obtenerSiguienteAeropuerto()) {
            if (aeropuertoActual->obtenerCodigo() == codigo)
                return aeropuertoActual;
            else
                aeropuertoActual = aeropuertoActual->obtenerSiguienteAeropuerto();
    }
    return aeropuertoActual;
}
}


void Grafo::agregarAeropuertoFinal(Aeropuerto* aeropuertoNuevo){
    Aeropuerto* actual = aeropuertoIncluido(aeropuertoNuevo->obtenerCodigo());
    if(actual){
        if (actual->obtenerCodigo() != aeropuertoNuevo->obtenerCodigo())
            actual->asignarSiguienteAeropuerto(aeropuertoNuevo);
    }
    else
        asignarPrimerAeropuerto(aeropuertoNuevo);

    }
