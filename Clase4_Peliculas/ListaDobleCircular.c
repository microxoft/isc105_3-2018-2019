#include <stdlib.h>
#include "ListaDobleCircular.h"

Lista* InicializarLista()
{
    Lista *nuevaLista = (Lista*)malloc(sizeof(Lista));
    nuevaLista->Cantidad = 0;
    nuevaLista->Cabeza = (Nodo*)malloc(sizeof(Nodo));
    nuevaLista->Cabeza->data.Id = -1;
    nuevaLista->Cabeza->siguiente = nuevaLista->Cabeza;
    nuevaLista->Cabeza->anterior = nuevaLista->Cabeza;
    return nuevaLista;
}

void AgregarPelicula(Lista *listado, Pelicula elemento)
{
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->data = elemento;
    nuevo->siguiente = listado->Cabeza;
    nuevo->anterior = listado->Cabeza->anterior;
    listado->Cabeza->anterior->siguiente = nuevo;
    listado->Cabeza->anterior = nuevo;
}

void EliminarPelicula(Lista*, int);
void InsertarPelicula(Lista*, Pelicula, int);
Nodo* BuscarPelicula(Lista*, int);
Lista* OrdenarPelicula(Lista*);
