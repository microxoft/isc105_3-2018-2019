#include <stdlib.h>
#include <stdio.h>

#ifndef _mainMatriz
#define _mainMatriz

void mainMatriz(int filaReina, int columnaReina)
{
    const int FIL = 8, COL = 8;
    int tablero[FIL][COL];
    int i, j;

    for(i=0; i<FIL; i++)
    {
        for(j=0; j<COL; j++)
        {
            if (i == filaReina || j == columnaReina)
                tablero[i][j] = '*';
            else if(i-j == filaReina - columnaReina || i+j == filaReina + columnaReina)
                tablero[i][j] = '*';
            else
                tablero[i][j] = ' ';
        }
    }

    tablero[filaReina][columnaReina] = 'R';

    for(i=0; i<FIL; i++)
    {
        for(j=0; j<COL; j++)
        {
            printf("%c", tablero[i][j]);
        }
        printf("\n");
    }
}
#endif // _mainMatriz
