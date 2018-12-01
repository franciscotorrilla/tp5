#include <iostream>
#include "funciones.h"
using namespace std;


int main()
{
    Grafo grafo;
    Grafo *ptrGrafo=&grafo;
    lecturaArchivo(ptrGrafo);
    Aeropuerto *ptrAeropuerto;
    ptrAeropuerto= ptrGrafo->obtenerPrimerAeropuerto();
    cout << ptrAeropuerto->obtenerCodigo() <<endl;
    while (ptrAeropuerto->obtenerSiguienteAeropuerto()){
        ptrAeropuerto=ptrAeropuerto->obtenerSiguienteAeropuerto();
        cout <<ptrAeropuerto->obtenerCodigo()<<endl;
    }

}

