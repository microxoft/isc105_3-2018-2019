#include <stdio.h>
#include <stdlib.h>
#include "PilaTripe.h"

int main()
{
    int i;
    PilaTriple *miPilaTriple = IniciarPilaTriple();

    Push(miPilaTriple, 0, 88.7);
    Push(miPilaTriple, 1, 15.8);
    Push(miPilaTriple, 2, 16.9);
    Push(miPilaTriple, 1, 10.3);
    Push(miPilaTriple, 1, 11.8);
    Push(miPilaTriple, 0, 90.3);
    Push(miPilaTriple, 0, 56.7);
    Push(miPilaTriple, 2, 23.5);
    Push(miPilaTriple, 2, 7.0);
    Push(miPilaTriple, 1, 8.7);

    for(i=0; i<3; i++)
    {
        printf("\n");
        while(!isEmpty(miPilaTriple, i))
        {
            printf("%.2f\t", Pop(miPilaTriple, i));
            /*fflush(stdin);
            getche();*/
        }
    }

    return 0;
}
