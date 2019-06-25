#include <stdlib.h>
#ifndef _PILATRIPLEH
#define _PILATRIPLEH

typedef struct
{
    int TamanoPila;
    float *PilaTriple;
    int PosicionesPilas[3];
}PilaTriple;

PilaTriple* IniciarPilaTriple();
void Push(PilaTriple*, int, float);
void VerificarEspacio(PilaTriple*, int);
float Pop(PilaTriple*, int);
int Size(PilaTriple*, int);
float Peek(PilaTriple*, int);
short isEmpty(PilaTriple*, int);
#endif // _PILATRIPLEH
