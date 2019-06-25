#include <stdio.h>
#include <stdlib.h>
#include "Monticulo.h"

int main()
{
    float nuevoValor;
    Monticulo *miHeap;
    miHeap = Inicializar(1);

    do
    {
        printf("Digite un valor (0 para salir): ");
        scanf("%f", &nuevoValor);

        if(nuevoValor != 0)
            Insertar(miHeap, nuevoValor);
    }while(nuevoValor != 0);
    // 5, 10, 20, 35, 2, 8, 15, 100, 9, 1

    while(!isEmpty(miHeap))
    {
        printf("%.2f\t", Poll(miHeap));
    }

    return 0;
}
