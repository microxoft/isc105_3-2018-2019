#include <stdlib.h>

#ifndef _PilaEstatica
#define _PilaEstatica

typedef struct
{
    int TamanoPila;
    float *Pila;
    int PosicionActual;
}Pila;

Pila* IniciarPila();
void Push(Pila*, float);
void VerificarEspacio(Pila*);
float Pop(Pila*);
int Size(Pila*);
float Peek(Pila*);
short isEmpty(Pila*);

#endif // _PilaEstatica












