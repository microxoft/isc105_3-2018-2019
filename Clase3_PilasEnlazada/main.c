#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"

int main()
{
    Pila *miPila = IniciarPila();
    Push(miPila, 88.7);
    Push(miPila, 15.8);
    Push(miPila, 16.9);
    Push(miPila, 10.3);
    Push(miPila, 11.8);
    Push(miPila, 90.3);
    Push(miPila, 56.7);
    Push(miPila, 23.5);
    Push(miPila, 7.0);
    Push(miPila, 8.7);

    while(!isEmpty(miPila))
    {
        printf("%.2f\t", Pop(miPila));
    }
    return 0;
}
