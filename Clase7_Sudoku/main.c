#include <stdio.h>
#include <stdlib.h>

const int DIM = 9;

void capturarMatriz(short matrizSudoku[DIM][DIM]);
void mostrarMatriz(short matrizSudoku[DIM][DIM]);
short resolverSudoku(short matrizSudoku[DIM][DIM]);
short resolverSudokuBT(short matrizSudoku[DIM][DIM], int, int);
short esValido(short matrizSudoku[DIM][DIM], int, int);

int main()
{
    short matrizSudoku[9][9] = {{0, 6, 0, 0, 0, 0, 0, 0, 8},
                                {9, 0, 0, 3, 0, 0, 0, 6, 0},
                                {8, 7, 0, 0, 0, 0, 0, 0, 0},
                                {7, 0, 0, 0, 5, 0, 0, 0, 0},
                                {0, 0, 0, 7, 0, 3, 0, 0, 0},
                                {0, 0, 4, 2, 8, 0, 0, 3, 0},
                                {3, 9, 0, 4, 0, 0, 0, 0, 0},
                                {0, 0, 7, 0, 0, 0, 5, 0, 6},
                                {0, 0, 5, 0, 0, 1, 2, 9, 0}};
    /*short matrizSudoku[9][9] = {{0, 6, 0, 5, 0, 0, 0, 0, 8},
                                {9, 0, 0, 3, 0, 0, 0, 6, 0},
                                {8, 7, 0, 0, 0, 5, 0, 0, 0},
                                {7, 0, 0, 0, 5, 0, 0, 0, 0},
                                {0, 0, 0, 7, 0, 3, 0, 0, 0},
                                {0, 0, 4, 2, 8, 0, 0, 3, 0},
                                {3, 9, 0, 4, 0, 0, 0, 0, 0},
                                {0, 0, 7, 0, 0, 0, 5, 0, 6},
                                {0, 0, 5, 0, 0, 1, 2, 9, 0}};*/
    printf("\n\nValidez: %d\n\n", esValido(matrizSudoku, 3, 0));
    //capturarMatriz(matrizSudoku);
    mostrarMatriz(matrizSudoku);

    if(!resolverSudoku(matrizSudoku))
        printf("\nSudoku no es v%clido.\n", 160);
    else
        mostrarMatriz(matrizSudoku);

    return 0;
}

void capturarMatriz(short matrizSudoku[DIM][DIM])
{
    int i, j;
    for(i=0; i<DIM; i++)
    {
        for(j=0; j<DIM; j++)
        {
            printf("%d, %d: ", i+1, j+1);
            scanf("%d", &matrizSudoku[i][j]);
        }
    }
}

void mostrarMatriz(short matrizSudoku[DIM][DIM])
{
    int i, j;
    for(i=0; i<DIM; i++)
    {
        for(j=0; j<DIM; j++)
        {
            printf("%d\t", matrizSudoku[i][j]);
        }
        printf("\n");
    }
}

short resolverSudoku(short matrizSudoku[DIM][DIM])
{
    return resolverSudokuBT(matrizSudoku, 0, 0);
}

short resolverSudokuBT(short matrizSudoku[DIM][DIM], int x, int y)
{
    int tanteoActual;
    if(y >= DIM)
        return 1;
    if(x >= DIM)
        return resolverSudokuBT(matrizSudoku, 0, y+1);
    if(matrizSudoku[y][x] != 0)
        return resolverSudokuBT(matrizSudoku, x+1, y);

    for(tanteoActual = 1; tanteoActual <= DIM; tanteoActual++)
    {
        matrizSudoku[y][x] = tanteoActual;
        if(esValido(matrizSudoku, x, y))
        {
            if(resolverSudokuBT(matrizSudoku, x+1, y))
                return 1;
        }
    }
    matrizSudoku[y][x] = 0;
    return 0;
}

short esValido(short matrizSudoku[DIM][DIM], int x, int y)
{
    int i, j;
    short encontrado = 0;
    // Fila:
    for(i=0; i<DIM; i++)
        encontrado += matrizSudoku[y][i] == matrizSudoku[y][x] ? 1 : 0;
    if(encontrado > 1)
    {
        //printf("\nFila invalida.\n");
        return 0;
    }

    // Columna:
    encontrado = 0;
    for(i=0; i<DIM; i++)
        encontrado += matrizSudoku[i][x] == matrizSudoku[y][x] ? 1 : 0;
    if(encontrado > 1)
    {
        //printf("\nColumna invalida.\n");
        return 0;
    }

    // Bloque:
    encontrado = 0;
    for(i=y-(y%3); i<(y-(y%3)+3); i++)
    {
        for(j=x-(x%3); j<(x-(x%3)+3); j++)
        {
            encontrado += matrizSudoku[i][j] == matrizSudoku[y][x] ? 1 : 0;
        }
    }
    if(encontrado > 1)
    {
        //printf("\nBloque invalido.\n");
        return 0;
    }

    return 1;
}













