#include <stdio.h>
#include <string.h>
#include "PilaEstatica.h"

const int TAM = 5;

Pila* IniciarPila()
{
    Pila *nuevaPila = (Pila*)malloc(sizeof(Pila));
    nuevaPila->PosicionActual = 0;
    nuevaPila->TamanoPila = TAM;
    nuevaPila->Pila = (float*)malloc(TAM * sizeof(float));
    return nuevaPila;
}

void VerificarEspacio(Pila *pila)
{
    if((pila->PosicionActual + 1) < pila->TamanoPila)
        return;

    pila->Pila = (float*)realloc(pila->Pila, pila->TamanoPila + TAM);
    pila->TamanoPila = pila->TamanoPila + TAM;
}

void Push(Pila *pila, float elemento)
{
    VerificarEspacio(pila);
    *(pila->Pila+pila->PosicionActual) = elemento;
    //pila->Pila[pila->PosicionActual] = elemento;
    pila->PosicionActual++;
}

float Pop(Pila *pila)
{
    if(isEmpty(pila))
        return -1;

    float valor = *(pila->Pila+pila->PosicionActual-1);
    pila->PosicionActual--;
    return valor;
}

int Size(Pila *pila)
{
    return pila->PosicionActual;
}

short isEmpty(Pila *pila)
{
    return pila->PosicionActual == 0;
}

float Peek(Pila *pila)
{
    float valor = Pop(pila);
    Push(pila, valor);
    return valor;
}









