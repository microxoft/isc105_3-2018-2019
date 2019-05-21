#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int MAX = 8;
    char tablero[MAX][MAX];

    int fila, columna, i, j;
    scanf("%d %d", &fila, &columna);

    for(i=0; i<MAX; i++)
    {
        for(j=0; j<MAX; j++)
        {
            if(i == fila || j == columna)
                tablero[i][j] = '*';
            else if((i-j) == (fila-columna) || (i+j) == (fila+columna))
                tablero[i][j] = '*';
            else
                tablero[i][j] = ' ';
        }
    }

    tablero[fila][columna] = 'R';

    for(i=0; i<MAX; i++)
    {
        for(j=0; j<MAX; j++)
        {
            printf("%c", tablero[i][j]);
        }
        printf("\n");
    }

    return 0;
}
