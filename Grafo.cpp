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
    }
}

Aeropuerto* Grafo::aeropuertoIncluido (Aeropuerto* aeropuertoNuevo){
    if (!primerAeropuerto)
        return 0;
    else {
        Aeropuerto* aeropuertoActual = primerAeropuerto;
        while (aeropuertoActual->obtenerSiguienteAeropuerto()) {
            if (aeropuertoActual->obtenerCodigo() == aeropuertoNuevo->obtenerCodigo())
                return aeropuertoActual;
            else
                aeropuertoActual = aeropuertoActual->obtenerSiguienteAeropuerto();
    }
    return aeropuertoActual;
}
}


void Grafo::agregarAeropuertoFinal(Aeropuerto* aeropuertoNuevo){
    Aeropuerto* actual = aeropuertoIncluido(aeropuertoNuevo);
    if (actual->obtenerCodigo() != aeropuertoNuevo->obtenerCodigo())
        actual->asignarSiguienteAeropuerto(aeropuertoNuevo);
    }
