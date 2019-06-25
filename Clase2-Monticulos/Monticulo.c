#include <stdlib.h>
#include <math.h>
#include "Monticulo.h"
const int ALTURA = 10;

Monticulo* Inicializar(short esMin)
{
    Monticulo *nuevoHeap = (Monticulo*)malloc(sizeof(Monticulo));
    nuevoHeap->tamano = pow(2, ALTURA) - 1;
    nuevoHeap->posicionActual = 0;
    nuevoHeap->altura = ALTURA;
    nuevoHeap->esMin = esMin;
    nuevoHeap->elementos = (float*)calloc(nuevoHeap->tamano, sizeof(float));
    return nuevoHeap;
}

void VerificarEspacio(Monticulo *heap)
{
    if(heap->posicionActual < heap->tamano)
        return;

    heap->altura++;
    heap->tamano = pow(2, heap->altura);
    heap->elementos = (float*)realloc(heap->elementos, heap->tamano);
}

void Insertar(Monticulo *heap, float elemento)
{
    VerificarEspacio(heap);

    *(heap->elementos+heap->posicionActual) = elemento;
    heap->posicionActual++;
    HeapifyUp(heap, heap->posicionActual-1);
}

int IndicePadre(int indice)
{
    int result = (indice-1)/2;
    return result < 0 ? 0 : result;
}

int IndiceHijoIzquierdo(Monticulo* heap, int indice)
{
    int result = (indice*2)+1;
    return result < heap->posicionActual ? result : -1;
}

int IndiceHijoDerecho(Monticulo* heap, int indice)
{
    int result = (indice*2)+2;
    return result < heap->posicionActual ? result : -1;
}

void Swap(float* desde, float* hasta)
{
    float burbuja;
    burbuja = *desde;
    *desde = *hasta;
    *hasta = burbuja;
}

void HeapifyUp(Monticulo *heap, int indice)
{
    // Axiomas:
    if(indice == 0)
        return;
    int indicePadre = IndicePadre(indice);
    if(heap->esMin &&
       *(heap->elementos+indicePadre) < *(heap->elementos+indice))
       return;
    if(!heap->esMin &&
       *(heap->elementos+indicePadre) > *(heap->elementos+indice))
        return;

    // Cuerpo:
    Swap(heap->elementos+indicePadre, heap->elementos+indice);

    // Llamada recursiva con cambios:
    HeapifyUp(heap, indicePadre);
}

float GetTop(Monticulo *heap)
{
    return *(heap->elementos);
}

void HeapifyDown(Monticulo *heap, int indice)
{
    int indiceMenor = IndiceHijoIzquierdo(heap, indice);
    int indiceDerecho = IndiceHijoDerecho(heap, indice);
    // Primer axioma (tanto de min como de max heaps)
    if(indiceMenor < 0)
        return;

    // Evaluando índice menor con Min Heaps:
    if(heap->esMin && indiceDerecho >= 0 &&
       *(heap->elementos+indiceMenor) > *(heap->elementos+indiceDerecho))
        indiceMenor = indiceDerecho;

    // Segundo axioma para el Min Heap:
    if(heap->esMin && *(heap->elementos+indice) < *(heap->elementos+indiceMenor))
        return;

    // Evaluando índice menor con Max Heaps:
    if(!heap->esMin && indiceDerecho >= 0 &&
       *(heap->elementos+indiceMenor) < *(heap->elementos+indiceDerecho))
        indiceMenor = indiceDerecho;

    // Segundo axioma para el Max Heap:
    if(!heap->esMin && *(heap->elementos+indice) > *(heap->elementos+indiceMenor))
        return;

    // Cuerpo de la función recursiva.
    Swap(heap->elementos+indice, heap->elementos+indiceMenor);

    // Llamada recursiva con cambio.
    HeapifyDown(heap, indiceMenor);
}

float Poll(Monticulo *heap)
{
    if(heap->posicionActual == 0)
        return *heap->elementos;

    float raiz = GetTop(heap);

    Swap(heap->elementos, heap->elementos+(heap->posicionActual-1));
    heap->posicionActual--;

    HeapifyDown(heap, 0);

    return raiz;
}

int Size(Monticulo *heap)
{
    return heap->posicionActual;
}

short isEmpty(Monticulo *heap)
{
    return heap->posicionActual == 0;
}










