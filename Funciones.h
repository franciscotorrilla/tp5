#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>
#include "Grafo.h"

using namespace std;

//pre: recibe un puntero al grafo
//post: crea el grafo con los datos del archivo
void lecturaArchivo(Grafo *ptrGrafo);

/*

//pre: recibe un puntero al grafo
//post: muestra en la pantalla el menu de opciones
void menu(Grafo* ptrGrafo);

//pre: recibe un puntero al grafo y el numero de opcion a ejecutar
//post: llama a la funcion que corresponde ejecutar
void opciones(char i,Grafo* ptrGrafo);

*/

//pre: recibe un puntero a string
//post: quita los guiones del string
void limpiarGuiones(string* dato);

//pre: recibe un puntero a string
//post: pone a mayusculas todos los caracteres
void datoAMayuscula(string* dato);


#endif // FUNCIONES_H_INCLUDED
