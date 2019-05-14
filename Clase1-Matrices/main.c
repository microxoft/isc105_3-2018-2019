#include <stdio.h>
#include <stdlib.h>

void CapturarMatriz(int filas, int columnas, int matr[filas][columnas]);
void MostrarMatriz(int filas, int columnas, int matr[filas][columnas]);

int main()
{
    const int COL = 3, FIL = 2;
    int matriz[FIL][COL];

    CapturarMatriz(FIL, COL, matriz);
    MostrarMatriz(FIL, COL, matriz);
    MostrarMatrizInversa(FIL, COL, matriz);

    return 0;
}

void CapturarMatriz(int filas, int columnas, int matr[filas][columnas])
{
    int i, j;

    for(i=0; i<filas; i++)
    {
        for(j=0; j<columnas; j++)
        {
            printf("Digite el valor de %d,%d: ", i, j);
            scanf("%d", *(matr+i)+j);
            //scanf("%d", &matr[i][j]);
            printf("%x %x\n", (matr+j+(i*columnas)), &matr[i][j]);
        }
    }
}

void MostrarMatriz(int filas, int columnas, int matr[filas][columnas])
{
    int i, j;

    for(i=0; i<filas; i++)
    {
        for(j=0; j<columnas; j++)
        {
            printf("%d\t", matr[i][j]);
        }
        printf("\n");
    }
}

void MostrarMatrizInversa(int filas, int columnas, int matr[filas][columnas])
{
    int i, j;

    for(j=0; j<columnas; j++)
    {
        for(i=0; i<filas; i++)
        {
            printf("%d\t", matr[i][j]);
        }
        printf("\n");
    }
}
