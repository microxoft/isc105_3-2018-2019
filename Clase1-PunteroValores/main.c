#include <stdio.h>
#include <stdlib.h>

void capturarTamano(int*);
void capturarValores(int*, int*);
void mostrarValores(int*, int*);
void OrdenarInsercion(int*, int*);

int main()
{
    int tam;
    int *valores;
    capturarTamano(&tam);
    valores = (int*)calloc(tam, sizeof(int));
    capturarValores(&tam, valores);
    mostrarValores(&tam, valores);
    OrdenarInsercion(&tam, valores);
    printf("\n");
    mostrarValores(&tam, valores);

    return 0;
}

void capturarTamano(int *tamano)
{
    do
    {
        printf("Digite un valor positivo para el tama%co del arreglo: ", 164);
        scanf("%d", tamano);
    }while(*tamano <= 0);
}

void capturarValores(int *tamano, int *vals)
{
    int i;

    for(i=0; i<*tamano; i++)
    {
        printf("Digite el valor %d de %d: ", i+1, *tamano);
        scanf("%d", (vals+i));
    }
}

void mostrarValores(int *tamano, int *vals)
{
    int i;

    for(i=0; i<*tamano; i++)
    {
        printf("%d\t", *(vals+i));
    }
}

void OrdenarInsercion(int *tam, int *arreglo)
{
    int i, j, valorActual;

    for(i=1; i<*tam; i++)
    {
        valorActual = *(arreglo+i);
        j=i-1;
        while(j>=0 && *(arreglo+j) > valorActual)
        {
            *(arreglo+j+1) = *(arreglo+j);
            j--;
        }
        *(arreglo+j+1) = valorActual;
    }
}
















