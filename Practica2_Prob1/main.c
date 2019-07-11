#include <stdio.h>
#include <stdlib.h>
#include "LISTA.h"

void Particionar(Lista*, int);

int main()
{
    int x, n, i, valor;
    Lista *listado = InicializarLista();
    Nodo *nodoActual;

    scanf("%d %d", &x, &n);

    for(i=0; i<n; i++)
    {
        scanf("%d", &valor);
        AgregarEnCola(listado, valor);
    }

    Particionar(listado, x);

    nodoActual = listado->Cabeza;
    for(i=0; i<n; i++)
    {
        printf("%d\t", nodoActual->data);
        nodoActual = nodoActual->siguiente;
    }

    return 0;
}

void Particionar(Lista *listado, int pivote)
{
    Nodo *nodoActual = listado->Cabeza;
    Nodo *nodoPivote = nodoActual;

    while(nodoActual != NULL)
    {
        if(nodoActual->data < pivote)
        {
            Intercambiar(nodoActual, nodoPivote);
            nodoPivote = nodoPivote->siguiente;
        }
        nodoActual = nodoActual->siguiente;
    }
}















