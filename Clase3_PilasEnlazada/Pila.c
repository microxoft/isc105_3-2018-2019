#include <stdlib.h>
#include "Pila.h"

Pila* IniciarPila()
{
    Pila *nueva = (Pila*)malloc(sizeof(Pila));
    nueva->cantidad = 0;
    nueva->tope = NULL;

    return nueva;
}

float Pop(Pila *pila)
{
    float resultado = pila->tope->data;

    Nodo *aBorrar = pila->tope;
    pila->tope = pila->tope->siguiente;
    free(aBorrar);
    pila->cantidad--;

    return resultado;
}

void Push(Pila *pila, float elemento)
{
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->data = elemento;
    nuevo->siguiente = pila->tope;
    pila->tope = nuevo;
    pila->cantidad++;
}

float Peek(Pila *pila)
{
    return pila->tope->data;
}

short isEmpty(Pila *pila)
{
    return pila->cantidad == 0;
}








