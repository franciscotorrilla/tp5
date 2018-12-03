#include <iostream>
#include "Funciones.h"
using namespace std;


int main()
{
    Grafo grafo;
    Grafo *ptrGrafo=&grafo;
    lecturaArchivo(ptrGrafo);
    ptrGrafo->rutaMinima("EZE", "OSA");
}

