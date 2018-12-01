#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include "Nodo.h"
#include "Grafo.h"
using namespace std;

//pre: recibe un puntero al grafo
//post: crea el grafo con los datos del archivo
void lecturaArchivo(Grafo *ptrGrafo);

//pre: recibe un puntero al grafo
//post: muestra en la pantalla el menu de opciones
void menu(Grafo* ptrGrafo);

//pre: recibe un puntero al grafo y el numero de opcion a ejecutar
//post: llama a la funcion que corresponde ejecutar
void opciones(char i,Grafo* ptrGrafo);

//pre: recibe un puntero al grafo
//post: muestra en la pantalla el menu de opciones de consulta
void menuConsulta(Grafo *ptrGrafo);

//pre: recibe un puntero al grafo y el numero de opcion a ejecutar
//post: llama a la funcion que corresponde ejecutar
void opcionesConsulta(char i, Grafo *ptrGrafo);

//pre: recibe un puntero al grafo
//post: agrega un aeropuerto al grafo
void darDeAlta(Grafo *ptrGrafo);

//pre: recibe un puntero al grafo
//post: elimina un aeropuerto del grafo
void darDeBaja(Grafo *ptrGrafo);

//pre: recibe un puntero al grafo
//post: devuelve la informacion del aeropuerto solicitado por codigo IATA
void consultaCodigo(Grafo *ptrGrafo);


//pre: recibe un puntero al grafo
//post: devuelve la informacion del aeropuerto solicitado por nombre del aeropuerto
void consultaNombre(Grafo *ptrGrafo);

//pre: recibe un puntero a nodo y un nombre a buscar
//post: imprime los datos del aeropuerto
void buscarNombre(Nodo* actual, Tipo dato);


//pre: recibe un puntero al grafo
//post: devuelve la informacion del aeropuerto solicitado por el nombre de la ciudad
void consultaCiudad(Grafo *ptrGrafo);

//pre: recibe un puntero a nodo y un nombre de ciudad a buscar
//post: imprime los datos del aeropuerto
void buscarCiudad(Nodo* actual, Tipo dato);

//pre: recibe un puntero al grafo
//post: devuelve la informacion del aeropuerto solicitado por el nombre del pais
void consultaPais(Grafo *ptrGrafo);

//pre: recibe un puntero a nodo y un nombre de pais a buscar
//post: imprime los datos del aeropuerto
void buscarPais(Nodo* actual, Tipo dato);

//pre: recibe un puntero a nodo
//post: imprime la informacion del aeropuerto
void mostrarDatos(Nodo* nodo);

//pre: recibe un puntero a nodo y un dato
//post: muestra el codigo del nodo
void mostrarCodigo(Nodo* actual,Tipo dato);

//pre: recibe un puntero al grafo
//post: muestra un listado de los codigos de aeropuertos
void mostrarListado(Grafo *ptrGrafo);


//pre: recibe un puntero a string
//post: quita los guiones del string
void limpiarGuiones(string* dato);

//pre: recibe un puntero a string
//post: pone a mayusculas todos los caracteres
void datoAMayuscula(string* dato);


#endif // FUNCIONES_H_INCLUDED
