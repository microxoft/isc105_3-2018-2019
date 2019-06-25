#include <stdlib.h>
#include "PilaTripe.h"

const int TAMANOINICIAL = 99;

PilaTriple* IniciarPilaTriple()
{
    PilaTriple *nuevaPila = (PilaTriple*)malloc(sizeof(PilaTriple));
    nuevaPila->TamanoPila = TAMANOINICIAL;
    nuevaPila->PilaTriple = (float*)calloc(TAMANOINICIAL, sizeof(float));
    nuevaPila->PosicionesPilas[0] = 0;
    nuevaPila->PosicionesPilas[1] = TAMANOINICIAL/3;
    nuevaPila->PosicionesPilas[2] = 2*TAMANOINICIAL/3;
    /*
     * for(i = 0; i<3; i++)
     * {
     *      nuevaPila->PosicionesPilas[i] = i * TAMANOINICIAL / 3;
     * }
     */
     return nuevaPila;
}

void Push(PilaTriple *pilaTriple, int numeroPila, float elemento)
{
    VerificarEspacio(pilaTriple, numeroPila);

    *(pilaTriple->PilaTriple+(pilaTriple->PosicionesPilas[numeroPila])) = elemento;
    pilaTriple->PosicionesPilas[numeroPila]++;
}

void VerificarEspacio(PilaTriple *pilaTriple, int numeroPila)
{
    // Verificar si posición de la pila llega al inicio de la siguiente pila,
    // y no estoy al inicio del número de pila actual.
    //if(pilaTriple->PosicionesPilas[numeroPila] == (numeroPila+1)*pilaTriple->TamanoPila/3)
    if(pilaTriple->PosicionesPilas[numeroPila] % (pilaTriple->TamanoPila/3) == 0 &&
       pilaTriple->PosicionesPilas[numeroPila] != numeroPila*pilaTriple->TamanoPila/3)
    {
        // Copiar:
        float nuevoArreglo[pilaTriple->TamanoPila * 3];
        int i, j;
        for(i=0; i<3; i++)
        {
            for(j=i*pilaTriple->TamanoPila/3; j<pilaTriple->PosicionesPilas[i]; j++)
            {
                nuevoArreglo[pilaTriple->TamanoPila * i + j] = *(pilaTriple->PilaTriple+j);
            }
        }

        // Pila llena.
        pilaTriple->PilaTriple = nuevoArreglo;
        pilaTriple->TamanoPila *= 3;

    }
}

float Pop(PilaTriple *pilaTriple, int numeroPila)
{
    if(isEmpty(pilaTriple, numeroPila))
        return 0;

    pilaTriple->PosicionesPilas[numeroPila]--;

    return *(pilaTriple->PilaTriple+pilaTriple->PosicionesPilas[numeroPila]);
}

short isEmpty(PilaTriple *pilaTriple, int numeroPila)
{
    return pilaTriple->PosicionesPilas[numeroPila] == pilaTriple->TamanoPila/3 * numeroPila;
}

float Peek(PilaTriple *pilaTriple, int numeroPila)
{
    float valor = Pop(pilaTriple, numeroPila);
    Push(pilaTriple, numeroPila, valor);
    return valor;
}

int Size(PilaTriple *pilaTriple, int numeroPila)
{
    return (pilaTriple->PosicionesPilas[numeroPila] - (pilaTriple->TamanoPila/3) * numeroPila);
}








