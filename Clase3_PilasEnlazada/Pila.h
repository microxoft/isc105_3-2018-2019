#include <stdlib.h>
#ifndef _PILAH
#define _PILAH

typedef struct sNodo
{
    float data;
    struct sNodo *siguiente; // Probar si funciona con Nodo *siguiente.
}Nodo;

typedef struct
{
    Nodo *tope;
    int cantidad;
}Pila;

Pila* IniciarPila();
float Pop(Pila*);
void Push(Pila*, float);
float Peek(Pila*);
short isEmpty(Pila*);

#endif // _PILAH
