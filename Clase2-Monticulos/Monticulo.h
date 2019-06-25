#include <stdlib.h>
#ifndef _Monticuloh
#define _Monticuloh

typedef struct
{
    int tamano;
    int posicionActual;
    int altura;
    short esMin;
    float *elementos;
}Monticulo;

void VerificarEspacio(Monticulo *heap);
Monticulo* Inicializar(short esMin);
void Insertar(Monticulo *heap, float elemento);
float GetTop(Monticulo *heap);
float Poll(Monticulo *heap);
void Swap(float* desde, float* hasta);
void HeapifyUp(Monticulo *heap, int indice);
void HeapifyDown(Monticulo *heap, int indice);
int IndicePadre(int indice);
int IndiceHijoIzquierdo(Monticulo* heap, int indice);
int IndiceHijoDerecho(Monticulo* heap, int indice);
int Size(Monticulo *heap);
short isEmpty(Monticulo *heap);

#endif // _Monticuloh
