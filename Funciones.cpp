#include "Funciones.h"
#include <stdlib.h>
#include "Aeropuerto.h"
#include "Vuelo.h"


void lecturaArchivo(Grafo *ptrGrafo){
    ifstream archivo;
    archivo.open("vuelos.txt");
    dato *datosSalida, *datosLlegada;
    string *ptrDato, datoString, claveSalida, claveLlegada;
    ptrDato = &datoString;
    unsigned costo;
    Aeropuerto* ptrAeropuertoLlegada,*ptrAeropuertoSalida;
    Vuelo* ptrVuelo;

    while (archivo >> claveSalida){

        //Datos aeropuerto Salida
        datosSalida=new dato();
        archivo >> datoString;
        limpiarGuiones(ptrDato);
        datosSalida->nombre = datoString;
        archivo >> datoString;
        limpiarGuiones(ptrDato);
        datosSalida->ciudad = datoString;
        archivo >> datoString;
        limpiarGuiones(ptrDato);
        datosSalida->pais = datoString;

        //Datos aeropuerto llegada
        datosLlegada=new dato();
        archivo >> claveLlegada;
        archivo >> datoString;
        limpiarGuiones(ptrDato);
        datosLlegada->nombre = datoString;
        archivo >> datoString;
        limpiarGuiones(ptrDato);
        datosLlegada->ciudad = datoString;
        archivo >> datoString;
        limpiarGuiones(ptrDato);
        datosLlegada->pais = datoString;
        archivo >> costo;

        ptrAeropuertoLlegada= new Aeropuerto(claveLlegada,datosLlegada);
        ptrAeropuertoSalida = new Aeropuerto(claveSalida,datosSalida);
        ptrGrafo->agregarAeropuertoFinal(ptrAeropuertoSalida);
        ptrGrafo->agregarAeropuertoFinal(ptrAeropuertoLlegada);
        ptrVuelo = new Vuelo(costo,ptrGrafo->aeropuertoIncluido(claveLlegada));
        ptrGrafo->aeropuertoIncluido(claveSalida)->asignarVuelo(ptrVuelo);
    }
	archivo.close();
	ptrAeropuertoLlegada=0;
	ptrAeropuertoSalida=0;
	ptrDato=0;
	ptrVuelo=0;

}


void menu(Grafo *ptrGrafo){

    char i = '1';
    while (i != '0'){
        cout << "Ingrese 0 para cerrar el menu." <<endl;
		cout << "Ingrese 1 para mostrar el listado de aeropuertos disponibles." <<endl;
		cout << "Ingrese 2 para buscar la ruta optima entre dos aeropuertos." <<endl;
		cin >> i;
        cin.ignore(1024, '\n');
        system("cls");
		opciones(i, ptrGrafo);
    	}
}

void opciones(char i, Grafo *ptrGrafo){

    switch (i){
        case '0':
            break;
        case '1': listarAeropuertos(ptrGrafo);
            break;
        case '2': llamarRutaMinima(ptrGrafo);
            break;
        default: cout << "Dato ingresado invalido" << endl;
        }
    }




void limpiarGuiones(string* dato){

    for(unsigned i=0; i<dato->length(); i++){
        if (dato[0][i]=='-')
            dato[0][i]=' ';
    }
}

void datoAMayuscula(string* dato){

    for (unsigned i=0 ; i < dato[0].length() ; i++){
        dato[0][i]=toupper(dato[0][i]);
    }
}

void listarAeropuertos(Grafo* ptrGrafo){
    Aeropuerto* actual = ptrGrafo->obtenerPrimerAeropuerto();
    while (actual){
    cout << actual->obtenerCodigo()<<endl;
    actual = actual->obtenerSiguienteAeropuerto();
     }
}

void llamarRutaMinima(Grafo *ptrGrafo){
string codigoSalida, codigoLlegada, *ptrSalida, *ptrLlegada;
ptrSalida = &codigoSalida;
ptrLlegada = &codigoLlegada;
cout << "Ingrese el codigo IATA del aeropuerto de salida: "<<endl;
cin >> codigoSalida;
cout << "Ingrese el codigo IATA del aeropuerto de llegada: "<<endl;
cin>> codigoLlegada;
datoAMayuscula(ptrSalida);
datoAMayuscula(ptrLlegada);
ptrGrafo->rutaMinima(codigoSalida,codigoLlegada);

}

