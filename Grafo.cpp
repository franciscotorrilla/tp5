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


unsigned Grafo::cantidadAeropuertos(){
    unsigned contador=0;
    if (primerAeropuerto){
        contador++;
        Aeropuerto* aeropuertoActual = primerAeropuerto;
        while (aeropuertoActual->obtenerSiguienteAeropuerto()) {
            contador++;
            aeropuertoActual = aeropuertoActual->obtenerSiguienteAeropuerto();
        }
    }
    return contador;
}

void Grafo::incluirCodigos(string *vec){

    Aeropuerto* aeropuertoActual= primerAeropuerto;
    for (unsigned i=0; i<cantidadAeropuertos(); i++){
        vec[i]=aeropuertoActual->obtenerCodigo();
        aeropuertoActual= aeropuertoActual->obtenerSiguienteAeropuerto();
    }
}

unsigned Grafo::obtenerPosicion(string codigo){

    Aeropuerto* aeropuertoActual= primerAeropuerto;
    for (unsigned i=0; i<cantidadAeropuertos(); i++){
        if (aeropuertoActual->obtenerCodigo()==codigo)
            return i;
        aeropuertoActual= aeropuertoActual->obtenerSiguienteAeropuerto();
    }
}



void Grafo::rutaMinima(string codigo1, string codigo2){

    unsigned MAX=999999999, pos, posLlegada;
    string *vecCodigos;
    unsigned *vecMinimos, *vecActual, i, valorMinimo, ultimoValorMinimo=0;
    int trasbordos=-1;
    vecCodigos= new string[cantidadAeropuertos()];
    incluirCodigos(vecCodigos);
    vecMinimos= new unsigned[cantidadAeropuertos()];
    vecActual= new unsigned[cantidadAeropuertos()];
    Aeropuerto* aeropuertoActual;
    Vuelo* vueloActual;

    for(unsigned e=0; e<cantidadAeropuertos(); e++){
        vecMinimos[e]=MAX;
    }

    pos=obtenerPosicion(codigo1);
    vecMinimos[pos]=0;
    posLlegada=obtenerPosicion(codigo2);

    aeropuertoActual= aeropuertoIncluido(codigo1);

    while (pos!=posLlegada){

        trasbordos++;

        // -----INICIALIZO EL VECTOR DE LOS PRECIOS EN MAX----
        for(unsigned e=0; e<cantidadAeropuertos(); e++){
            vecActual[e]=MAX;
        }

        // ----GUARDO TODOS LOS PRECIOS DE LOS VIAJES DEl AEROPUERTO----
        vueloActual = aeropuertoActual->obtenerPrimerVuelo();
        while(vueloActual){
            i=0;
            while(vecCodigos[i]!=vueloActual->obtenerAeropuertoLlegada()->obtenerCodigo()){
                i++;
            }
            vecActual[i]=vueloActual->obtenerPrecio();
            vueloActual= vueloActual->obtenerSiguienteVuelo();
        }


        // ----BUSCO EL VALOR MINIMO-----
        valorMinimo=MAX;
        for(unsigned e=0; e<cantidadAeropuertos(); e++){
            if(vecMinimos[e]==MAX){
                if (vecActual[e]<valorMinimo){
                    valorMinimo=vecActual[e];
                    pos=e;
                }
            }
        }
        vecMinimos[pos]=valorMinimo+ultimoValorMinimo;
        ultimoValorMinimo+=valorMinimo;

        // ----  SELECCIONO EL AEROPUERTO QUE CORRESPONDE AL     ----
        // ---- ULTIMO VALOR MINIMO PARA CONTINUAR CON EL BUCLE  ----
        aeropuertoActual=primerAeropuerto;
        for (unsigned e=0; e<pos;e++){
            aeropuertoActual = aeropuertoActual->obtenerSiguienteAeropuerto();
        }
    }

    // ----MUESTRA COMO SE FORMA EL VIAJE COMPLETO Y EL VALOR DEL MISMO ----

    valorMinimo=MAX;
    cout << "Costo total: " << ultimoValorMinimo <<endl;
    cout << codigo1 << "-->";
    for (int e=0; e<=trasbordos; e++){

        for (unsigned e=0; e<cantidadAeropuertos(); e++){
            if (vecMinimos[e]!=0 && vecMinimos[e]<valorMinimo){
                valorMinimo= vecMinimos[e];
                vecMinimos[e]=MAX;
                pos=e;
            }
        }
        valorMinimo=MAX;
        if (trasbordos!=e)
            cout << vecCodigos[pos]<< "-->";
        else
            cout << codigo2 <<endl;
    }

    delete vecCodigos; vecCodigos=0;
    delete vecMinimos; vecMinimos=0;
    delete vecActual; vecActual=0;
}
