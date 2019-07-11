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

void AgregarPelicula(Pelicula elemento, Nodo *despuesDe)
{
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->data = elemento;
    nuevo->siguiente = despuesDe->siguiente;
    nuevo->anterior = despuesDe;
    despuesDe->siguiente->anterior = nuevo;
    despuesDe->siguiente = nuevo;
    //despuesDe->anterior = nuevo;
}

Nodo* BuscarPorId(Lista *listadoPeliculas, int id)
{
    Nodo *nodoActual = listadoPeliculas->Cabeza->siguiente;

    while(nodoActual->data.Id != -1)
    {
        if(nodoActual->data.Id == id)
            return nodoActual;

        nodoActual = nodoActual->siguiente;
    }
    return NULL;
}

void EliminarPelicula(Lista *listadoPeliculas, Nodo *aEliminar)
{
    if(aEliminar->data.Id == -1)
        return;
    aEliminar->anterior->siguiente = aEliminar->siguiente;
    aEliminar->siguiente->anterior = aEliminar->anterior;
    free(aEliminar);
}

Nodo* BuscarPorAnyo(Lista *listadoPeliculas, int anyo)
{
    Nodo *nodoActual = listadoPeliculas->Cabeza->siguiente;

    while(nodoActual->data.Id != -1)
    {
        if(nodoActual->data.Anyo > anyo)
            return nodoActual->anterior;

        nodoActual = nodoActual->siguiente;
    }
    return nodoActual->anterior;
}

Nodo* CopiarNodo(Nodo *original)
{
    Nodo *copia = (Nodo*)malloc(sizeof(Nodo));

    copia->data = original->data;
    copia->anterior = original->anterior;
    copia->siguiente = original->siguiente;

    return copia;
}

void Intercambiar(Nodo *primero, Nodo *segundo)
{
    Nodo *auxPrimero = CopiarNodo(primero);

    primero->anterior->siguiente = segundo;
    primero->anterior = segundo->anterior;
    primero->siguiente->anterior = segundo;
    primero->siguiente = segundo->siguiente;
    segundo->siguiente = auxPrimero->siguiente;
    segundo->anterior->siguiente = primero;
    segundo->anterior = auxPrimero->anterior;
    primero->siguiente->anterior = primero;

    free(auxPrimero);
}

Lista* OrdenarPeliculaSeleccion(Lista *listadoPeliculas)
{
    Nodo *nodoActual = listadoPeliculas->Cabeza->siguiente;
    Nodo *nodoMenor;
    Nodo *temporal;

    while(nodoActual->data.Id != -1)
    {
        nodoMenor = nodoActual;
        temporal = nodoActual->siguiente;
        while(temporal->data.Id != -1)
        {
            if(temporal->data.Anyo < nodoMenor->data.Anyo)
            {
                nodoMenor = temporal;
            }
            temporal = temporal->siguiente;
        }
        Intercambiar(nodoActual, nodoMenor);
        nodoActual = nodoActual->siguiente;
    }
}

void InsertarPelicula(Lista*, Pelicula, int);





















