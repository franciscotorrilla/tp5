#include "Funciones.h"
#include <stdlib.h>

bool SE_ENCONTRO = false;

void lecturaArchivo(Grafo *ptrGrafo){
    ifstream archivo;
    archivo.open("aeropuertos.txt");
    datos* auxDatosPartida,auxDatosLlegada;
    string *ptrDato, datoString, clave, claveLlegada;
    ptrDato = &datoString;
    float datoFloat;
    int costo;
    Nodo *ptrNodo;
    aeropuerto* ptrAeropuertoLlegada,ptrAeropuertoPartida;
    Vuelo* ptrVuelo;
    while (archivo >> clave){

        //Datos aeropuerto Salida
        archivo >> datoString;
        limpiarGuiones(ptrDato);
        auxDatosPartida->nombre = datoString;
        archivo >> datoString;
        limpiarGuiones(ptrDato);
        auxDatosPartida->ciudad = datoString;
        archivo >> datoString;
        limpiarGuiones(ptrDato);
        auxDatosPartida->pais = datoString;
        //Datos aeropuerto llegada
        archivo >> claveLlegada;
        archivo >> datoString;
        limpiarGuiones(ptrDato);
        auxDatosLlegada->nombre;
        archivo >> datoString;
        limpiarGuiones(ptrDato);
        auxDatosLlegada->ciudad;
        archivo >> datoString;
        limpiarGuiones(ptrDato);
        auxDatosLlegada->pais;
        archivo >> costo;
        ptrAeropuertoLlegada= new Aeropuerto(claveLlegada,auxDatosLlegada);
        ptrVuelo = new Vuelo(costo,ptrAeropuertoLlegada);
        ptrAeropuertoPartida = new Aeropuerto(clave,auxDatosPartida,ptrVuelo,ptrAeropuertoLlegada);
        ptrGrafo->asignarPrimerAeropuerto(ptrAeropuertoPartida);
    }
	archivo.close();
	ptrNodo=0, ptrAeropuerto=0;

}


void menu(Grafo *ptrGrafo){

    char i = '1';
    while (i != '0'){
        cout << "Ingrese 0 para cerrar el menu." <<endl;
		cout << "Ingrese 1 para consultar por un aeropuerto." <<endl;
		cout << "Ingrese 2 para dar de alta un nuevo aeropuerto." <<endl;
		cout << "Ingrese 3 para dar de baja un aeropuerto." <<endl;
		cout << "Ingrese 4 para mostrar el listado de aeropuertos." <<endl;
		cin >> i;
        cin.ignore(1024, '\n');
        system("cls");
		opciones(i, ptrArbol);
    	}
    }


void opciones(char i, Grafo *ptrGrafo){

    switch (i){
        case '0':
            break;
        case '1': menuConsulta(ptrArbol);
            break;
        case '2': darDeAlta(ptrArbol);
            break;
        case '3': darDeBaja(ptrArbol);
            break;
        case '4': mostrarListado(ptrArbol);
            break;
        default: cout << "Dato ingresado invalido" << endl;
        }
    }

void darDeAlta(Grafo *ptrGrafo){
    string datoString, clave;
    int datoInt;
    float datoFloat;
    Nodo *ptrNodo;
    aeropuerto *ptrAeropuerto;
    ptrAeropuerto= new aeropuerto();
    cout << "Ingrese el codigo IATA: ";
    cin >> clave;
    cout <<"Ingrese el nombre del aeropuerto: ";
    cin >> datoString;
    ptrAeropuerto->nombre = datoString;
    cout <<"Ingrese el nombre de la ciudad: ";
    cin >> datoString;
    ptrAeropuerto->ciudad = datoString;
    cout <<"Ingrese el nombre del pais: ";
    cin >> datoString;
    ptrAeropuerto->pais = datoString;
    cout <<"Ingrese la superficie: ";
    cin >> datoFloat;
    ptrAeropuerto->superficie = datoFloat;
    cout <<"Ingrese la cantidad de terminales: ";
    cin >> datoInt;
    ptrAeropuerto->cantidadTerminales = datoInt;
    cout <<"Ingrese la cantidad de destinos nacionales: ";
    cin >>  datoInt;
    ptrAeropuerto->destinosNacionales = datoInt;
    cout <<"Ingrese la cantidad de destinos internacionales: ";
    cin >> datoInt;
    ptrAeropuerto->destinosInternacionales = datoInt;
    ptrNodo= new Nodo(clave, ptrAeropuerto);
    ptrArbol->agregarElemento(ptrNodo, ptrArbol->obtenerRaiz());
    system("cls");
    cout << "El aeropuerto se ha agregado correctamente" <<endl;
}

void darDeBaja(Grafo *ptrGrafo){
    Tipo *ptrCodigo, codigo;
    ptrCodigo = &codigo;
    cout << "Ingrese codigo IATA del aeropuerto que quiere eliminar: ";
    cin >> codigo;
    datoAMayuscula(ptrCodigo);
    if(!(ptrArbol->obtenerRaiz()))
        cout << "No quedan mas aeropuertos :(" <<endl;
    else{
        if (ptrArbol->eliminarElemento(codigo))
            cout << "El aeropuerto se ha eliminado correctamente" << endl;
        else
            cout << "No se encontro tal aeropuerto" <<endl;
    }
}


void menuConsulta(Grafo *ptrGrafo){

    SE_ENCONTRO = false;
    char i = '1';
    while (i != '0'){
        cout << "Ingrese 0 para volver al menu principal"<<endl;
		cout << "Ingrese 1 para consultar por codigo IATA (La consulta mas rapida)." <<endl;
		cout << "Ingrese 2 para consultar por nombre." <<endl;
		cout << "Ingrese 3 para consultar por ciudad." <<endl;
		cout << "Ingrese 4 para consultar por pais." <<endl;
		cin >> i;
        cin.ignore(1024, '\n');
        system("cls");
		opcionesConsulta(i, ptrArbol);
    	}
    }


void opcionesConsulta(char i, Grafo *ptrGrafo){

    switch (i){
        case '0':
            break;
        case '1': consultaCodigo(ptrArbol);
            break;
        case '2': consultaNombre(ptrArbol);
            break;
        case '3': consultaCiudad(ptrArbol);
            break;
        case '4': consultaPais(ptrArbol);
            break;
        default: cout << "Dato ingresado invalido" << endl;
        }
    if ((i=='2' || i=='3' || i=='4')&& SE_ENCONTRO==false)
        cout << "No se encontro ese aeropuerto" << endl << endl;
    }

void consultaCodigo(Grafo *ptrGrafo){

    Tipo *ptr, codigo;
    ptr= &codigo;
    cout << "Ingrese el codigo IATA: ";
    cin >> codigo;
    datoAMayuscula(ptr);
    if (Nodo* buscado = ptrArbol->buscar(codigo)){
        aeropuerto* aeropuertoBuscado = buscado->obtenerDatos();
        cout<< "El codigo ingresado corresponde al aeropuerto de "<<aeropuertoBuscado->ciudad <<", " << aeropuertoBuscado->pais<<endl
        <<"que tiene una superficie de " << aeropuertoBuscado->superficie <<" km^2" <<endl <<aeropuertoBuscado->cantidadTerminales
        <<" terminales, " << aeropuertoBuscado->destinosNacionales <<" destinos nacionales y " << aeropuertoBuscado->destinosInternacionales <<
        " internacionales" << endl << endl;
    }
    else
        cout << "El aeropuerto no esta incluido"<< endl << endl;
    }

void consultaNombre(Grafo *ptrGrafo){

    Tipo *ptr, s, dato;
    ptr= &dato;
    cout << "Ingrese el nombre: ";
    cin.getline((char*)s.c_str(), 256);
    dato= s.c_str();
    datoAMayuscula(ptr);
    ptrArbol->inOrder(ptrArbol->obtenerRaiz(), buscarNombre, dato);
}

void buscarNombre(Nodo* actual, Tipo nombre){

    Tipo *ptr, thisNombre;
    ptr= &thisNombre;
    thisNombre=actual->obtenerDatos()->nombre;
    datoAMayuscula(ptr);
    if(thisNombre == nombre){
        SE_ENCONTRO = true;
        mostrarDatos(actual);
    }
}

void consultaCiudad(Grafo *ptrGrafo){

    Tipo *ptr, s, dato;
    ptr= &dato;
    cout << "Ingrese la ciudad: ";
    cin.getline((char*)s.c_str(), 256);
    dato= s.c_str();
    datoAMayuscula(ptr);
    ptrArbol->inOrder(ptrArbol->obtenerRaiz(), buscarCiudad, dato);
}

void buscarCiudad(Nodo* actual, Tipo ciudad){

    Tipo *ptr, thisCiudad;
    ptr= &thisCiudad;
    thisCiudad=actual->obtenerDatos()->ciudad;
    datoAMayuscula(ptr);
    if(thisCiudad == ciudad){
        SE_ENCONTRO = true;
        mostrarDatos(actual);
    }
}

void consultaPais(Grafo *ptrGrafo){
    Tipo *ptr, s, dato;
    ptr= &dato;
    cout << "Ingrese el pais: ";
    cin.getline((char*)s.c_str(), 256);
    dato= s.c_str();
    datoAMayuscula(ptr);
    ptrArbol->inOrder(ptrArbol->obtenerRaiz(), buscarPais, dato);
}

void buscarPais(Nodo* actual, Tipo pais){

    Tipo *ptr, thisPais;
    ptr= &thisPais;
    thisPais=actual->obtenerDatos()->pais;
    datoAMayuscula(ptr);
    if(thisPais== pais){
        SE_ENCONTRO = true;
        mostrarDatos(actual);
    }
}

void mostrarDatos(Nodo* nodo){
    aeropuerto* aeropuerto = nodo->obtenerDatos();
    cout << aeropuerto->nombre << ", codigo: " <<  nodo->obtenerClave() << ", de "<< aeropuerto->ciudad<<", " << aeropuerto->pais<<endl
        <<"que tiene una superficie de " << aeropuerto->superficie <<" km^2, con" <<endl <<aeropuerto->cantidadTerminales
        <<" terminales, " << aeropuerto->destinosNacionales <<" destinos nacionales y " << aeropuerto->destinosInternacionales <<
        " internacionales" <<endl<<endl;
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

void mostrarListado(Grafo *ptrGrafo){
    Tipo dato;
    ptrArbol->inOrder(ptrArbol->obtenerRaiz(), mostrarCodigo, dato);
}

void mostrarCodigo(Nodo* actual,Tipo dato){
cout << actual->obtenerClave() <<endl;
}

