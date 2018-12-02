#include <iostream>
#include "funciones.h"
using namespace std;


int main()
{
    Grafo grafo;
    Grafo *ptrGrafo=&grafo;
    lecturaArchivo(ptrGrafo);
    Aeropuerto *ptrAeropuerto;
    Vuelo *ptrVuelo;
    ptrAeropuerto= ptrGrafo->obtenerPrimerAeropuerto();
    cout << ptrAeropuerto->obtenerCodigo() <<endl;
    while (ptrAeropuerto->obtenerSiguienteAeropuerto()){
        if(ptrAeropuerto->obtenerPrimerVuelo()){
            ptrVuelo=ptrAeropuerto->obtenerPrimerVuelo();
            cout << ptrVuelo->obtenerPrecio() <<endl;
        }
        while(ptrVuelo->obtenerSiguienteVuelo()){
            ptrVuelo= ptrVuelo->obtenerSiguienteVuelo();
            cout << ptrVuelo->obtenerPrecio() <<endl;
        }
        ptrAeropuerto=ptrAeropuerto->obtenerSiguienteAeropuerto();
        cout <<ptrAeropuerto->obtenerCodigo()<<endl;
    }
}

