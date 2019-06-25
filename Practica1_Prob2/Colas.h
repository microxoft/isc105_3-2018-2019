#include <stdlib.h>
#ifndef _Colash
#define _Colash

typedef struct
{
    int tamano;
    int primerIndice;
    int ultimoIndice;
    float *elementos;
    int cantidad;
}Cola;

Cola* InicializarCola();
void enqueue(Cola*, float);
int TamanoCola(Cola*);
void VerificarEspacio(Cola*);
float dequeue(Cola*);
short isEmpty(Cola*);
float getFront(Cola*);


#endif // _Colash
