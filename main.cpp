#include <iostream>
#include "funciones.h"
using namespace std;


int main()
{
    Grafo grafo;
    Grafo *ptrGrafo=&grafo;
    lecturaArchivo(ptrGrafo);
    ptrGrafo->rutaMinima("EZE", "TXL");
}

