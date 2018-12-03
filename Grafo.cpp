#include "Grafo.h"
#include <sstream>

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
    if(actual || primerAeropuerto){
        if (actual->obtenerCodigo() != aeropuertoNuevo->obtenerCodigo())
            actual->asignarSiguienteAeropuerto(aeropuertoNuevo);
        else
            delete aeropuertoNuevo;
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

int Grafo::obtenerPosicion(string codigo){

    Aeropuerto* aeropuertoActual= primerAeropuerto;
    for (unsigned i=0; i<cantidadAeropuertos(); i++){
        if (aeropuertoActual->obtenerCodigo()==codigo)
            return i;
        aeropuertoActual= aeropuertoActual->obtenerSiguienteAeropuerto();
    }
    return -1;
}

void Grafo::rutaMinima(string codigo1, string codigo2){

    if(obtenerPosicion(codigo1) == -1 || obtenerPosicion(codigo2) == -1) {
        cout<<"No hay conexiones disponibles entre "<<codigo1 <<" y "<< codigo2<<endl;
        return;
    }
    unsigned MAX=999999999, posValorMinimo, posLlegada, posActual, posSalida;
    string *vecCodigos, viajeCompleto;
    unsigned *vecMinimos, *vecActual, *vecTrasbordos, i, valorMinimo;
    vecCodigos= new string[cantidadAeropuertos()];
    incluirCodigos(vecCodigos);
    vecMinimos= new unsigned[cantidadAeropuertos()];
    vecActual= new unsigned[cantidadAeropuertos()];
    vecTrasbordos= new unsigned[cantidadAeropuertos()];
    Aeropuerto* aeropuertoActual;
    Vuelo* vueloActual;
    bool continuar = true;
    for(unsigned e=0; e<cantidadAeropuertos(); e++){
        vecMinimos[e]=MAX;
        vecTrasbordos[e]=MAX;
    }
    posSalida=obtenerPosicion(codigo1);
    posValorMinimo=posSalida;
    vecMinimos[posValorMinimo]=0;
    posLlegada=obtenerPosicion(codigo2);
    posActual=posValorMinimo;
    aeropuertoActual= aeropuertoIncluido(codigo1);
    while (posActual!=posLlegada && continuar ){
        continuar = false;
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


        // ---- ACTUALIZA LA LISTA DE VALORES MINIMOS -----
        valorMinimo=MAX;
        for(unsigned e=0; e<cantidadAeropuertos(); e++){
            if(vecActual[e]+vecMinimos[posActual]<vecMinimos[e]){
                vecMinimos[e]=vecMinimos[posActual]+vecActual[e];
                vecTrasbordos[e]=posActual;
                if (vecMinimos[e]< valorMinimo){
                    valorMinimo=vecMinimos[e];
                    posValorMinimo=e;
                }
            }
        }

        vecMinimos[vecTrasbordos[posValorMinimo]]=MAX;

        // ---- BUSCO EL VALOR MINIMO QUE TENGA CONEXIONES Q NO SE HAYAN VISTO AUN ----
        if (posValorMinimo==posActual)
            vecMinimos[posValorMinimo]=MAX;
        for(unsigned e=0; e<cantidadAeropuertos(); e++){
            if (vecMinimos[e]< valorMinimo){
                valorMinimo=vecMinimos[e];
                posValorMinimo=e;
            }
        }

        // ----  SELECCIONO EL AEROPUERTO QUE CORRESPONDE AL     ----
        // ---- ULTIMO VALOR MINIMO PARA CONTINUAR CON EL BUCLE  ----
        aeropuertoActual=primerAeropuerto;
        for (unsigned e=0; e<posValorMinimo;e++){
            aeropuertoActual = aeropuertoActual->obtenerSiguienteAeropuerto();
        }
        posActual=posValorMinimo;

        for(unsigned e=0; e<cantidadAeropuertos(); e++) {
            if(vecMinimos[e] != MAX)
                continuar = true;
        }
    }
    if(valorMinimo == MAX) {
        cout <<"No hay vuelos disponibles entre "<<codigo1 <<" y "<<codigo2<<endl;
        return;
    }
    // ----MUESTRA COMO SE FORMA EL VIAJE COMPLETO Y EL VALOR DEL MISMO ----

    cout << "Costo total: " << valorMinimo <<endl;
    viajeCompleto = static_cast<ostringstream*>(&(ostringstream() << vecTrasbordos[posActual]))->str();
    while (vecTrasbordos[posActual]!=posSalida){
        posActual=vecTrasbordos[posActual];
        viajeCompleto += static_cast<ostringstream*>(&(ostringstream() << vecTrasbordos[posActual]))->str();
    }
    char x;
    int ix;
    for(int e=viajeCompleto.length()-1; e>=0; e--){
        x= viajeCompleto[e];
        ix = x - '0';
        cout << vecCodigos[ix]<< "-->";
    }
    cout << codigo2<<endl;

    delete[] vecCodigos; vecCodigos=0;
    delete[] vecMinimos; vecMinimos=0;
    delete[] vecActual; vecActual=0;
    delete[] vecTrasbordos; vecTrasbordos=0;
}


Grafo::~Grafo() {

    Aeropuerto* aeropuertoActual = primerAeropuerto;
    Aeropuerto* aux = 0;
    Vuelo* auxVuelo = 0;
    while (aeropuertoActual) {
        aux = aeropuertoActual;
        aeropuertoActual = aeropuertoActual->obtenerSiguienteAeropuerto();
        while(aux->obtenerPrimerVuelo()){
            auxVuelo = aux->obtenerPrimerVuelo();
            aux->asignarPrimerVuelo(aux->obtenerPrimerVuelo()->obtenerSiguienteVuelo());
            delete auxVuelo;
        }
        delete aux;
    }

}

Aeropuerto* Grafo::obtenerAeropuerto(string codigo) {

    Aeropuerto* actual = primerAeropuerto;
    while (actual) {
        if (actual->obtenerCodigo() == codigo)
            return actual;
        else
            actual = actual->obtenerSiguienteAeropuerto();
    }
    return actual;
}
