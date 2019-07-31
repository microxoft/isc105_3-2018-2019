#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAX = 1000, MIN = 0;
void CapturarValores(int[], int);
void GenerarValores(int[], int);
long GenerarValoresRecursivo(int[], int, int);
void MostrarValores(int[], int);
int BusquedaLineal(int[], int, int);
int BusquedaLinealRecursiva(int[], int, int, int);
int BusquedaBinaria(int[], int, int);
int BusquedaBinariaRecursiva(int[], int, int, int);
void MergeSortRecursivo(int[], int, int);
void Merge(int[], int, int, int[], int, int[], int);
void Quicksort(int[], int);
void QuicksortRec(int[], int, int);
int Particionar(int[], int, int);
void Swap(int[], int, int);
void SwapPunteros(int*, int*);

int main()
{
    srand(time(NULL));
    int n, destino, posicion;
    printf("Digite el tama%co del arreglo: ", 164);
    scanf("%d", &n);
    int arreglo[n];

    //CapturarValores(arreglo, n);
    GenerarValores(arreglo, n);
    MostrarValores(arreglo, n);
    printf("\nDigite el valor que desea buscar: ");
    scanf("%d", &destino);

    //MergeSortRecursivo(arreglo, 0, n-1);
    Quicksort(arreglo, n);
    MostrarValores(arreglo, n);

    posicion = BusquedaLineal(arreglo, n, destino);

    if(posicion >= 0)
        printf("Usando b%csqueda lineal fue encontrado en: %d\n", 163, posicion);
    else
        printf("Usando b%csqueda lineal el valor %d no existe en el listado.\n", 163, destino);

    posicion = BusquedaBinaria(arreglo, n, destino);

    if(posicion >= 0)
        printf("Usando b%csqueda binaria fue encontrado en: %d\n", 163, posicion);
    else
        printf("Usando b%csqueda binaria el valor %d no existe en el listado.\n", 163, destino);

    return 0;
}

void CapturarValores(int arreglo[], int tamano)
{
    int i;
    for(i=0; i<tamano; i++)
    {
        printf("%d: ", i+1);
        scanf("%d", &arreglo[i]);
    }
}

void GenerarValores(int arreglo[], int tamano)
{
    long sumatoria = GenerarValoresRecursivo(arreglo, tamano, 0);
    printf("\nLa sumatoria de los aleatorios es: %ld\n", sumatoria);
}

long GenerarValoresRecursivo(int arreglo[], int tamano, int pos)
{
    if(pos >= tamano)
        return 0;

    arreglo[pos] = rand() % (MAX - MIN + 1) + MIN; // Se puede colocar esto en una función.

    return arreglo[pos] + GenerarValoresRecursivo(arreglo, tamano, pos+1);
}

void MostrarValores(int arreglo[], int tamano)
{
    int i;
    printf("\nValores:\n");
    for(i=0; i<tamano; i++)
    {
        printf("%d\t", arreglo[i]);
    }
}

int BusquedaLineal(int arreglo[], int tamano, int destino)
{
    return BusquedaLinealRecursiva(arreglo, tamano, destino, 0);
}

int BusquedaLinealRecursiva(int arreglo[], int tamano, int destino, int pos)
{
    if(pos >= tamano)
        return -1;

    return arreglo[pos] == destino ? pos : BusquedaLinealRecursiva(arreglo, tamano, destino, pos+1);
}

int BusquedaBinaria(int arreglo[], int tamano, int destino)
{
    return BusquedaBinariaRecursiva(arreglo, destino, 0, tamano - 1);
}

int BusquedaBinariaRecursiva(int arreglo[], int destino, int limI, int limS)
{
    int centro;
    if(limI>limS)
        return -1;

    centro = (float)limI/2 + (float)limS/2;

    if(arreglo[centro] == destino)
        return centro;
    else if(arreglo[centro] > destino) // Asumiento que están en orden creciente.
        return BusquedaBinariaRecursiva(arreglo, destino, limI, centro-1);
    else
        return BusquedaBinariaRecursiva(arreglo, destino, centro+1, limS);
}

void MergeSortRecursivo(int arreglo[], int limI, int limS)
{
    int i;
    if(limI == limS)
        return;
    int tamanoIzquierdo, tamanoDerecho;

    if(((limS - limI) + 1) % 2)
    {
        tamanoIzquierdo = ((limS - limI) / 2);
        tamanoDerecho = ((limS - limI) / 2) + 1;
    }
    else
        tamanoIzquierdo = tamanoDerecho = (limS - limI) / 2 + 1;

    int izquierdo[tamanoIzquierdo], derecho[tamanoDerecho];

    // Copiando la mitad izquierda:
    for(i=limI; i<tamanoIzquierdo; i++)
        izquierdo[i-limI] = arreglo[i];

    // Copiando la mitad derecha:
    for(; i<=limS; i++)
        derecho[i-limI-tamanoIzquierdo] = arreglo[i];

    MergeSortRecursivo(izquierdo, 0, tamanoIzquierdo-1);
    MergeSortRecursivo(derecho, 0, tamanoDerecho-1);

    Merge(arreglo, limI, limS, izquierdo, tamanoIzquierdo, derecho, tamanoDerecho);
}

void Merge(int arreglo[], int limI, int limS, int izq[], int tamanoI, int der[], int tamanoD)
{
    int i = 0, j = 0;

    while(i<tamanoI && j<tamanoD)
    {
        if(izq[i] <= der[j])
            arreglo[limI] = izq[i++];
        else
            arreglo[limI] = der[j++];

        limI++;
    }

    // Copiando los remanentes;
    while(i<tamanoI)
        arreglo[limI++] = izq[i++];
    while(j<tamanoD)
        arreglo[limI++] = der[j++];
}

void Quicksort(int arreglo[], int tamano)
{
    QuicksortRec(arreglo, 0, tamano-1);
}

void QuicksortRec(int arreglo[], int limI, int limS)
{
    int indicePivote;

    if(limI>=limS)
        return;

    indicePivote = Particionar(arreglo, limI, limS);
    QuicksortRec(arreglo, limI, indicePivote-1);
    QuicksortRec(arreglo, indicePivote+1, limS);
}

int Particionar(int arreglo[], int limI, int limS)
{
    int pivote = arreglo[limI];
    int i = limI+1;
    int j = i;

    for(; i<=limS; i++)
    {
        if(arreglo[i] < pivote)
        {
            Swap(arreglo, i, j);
            j++;
        }
    }
    SwapPunteros(&arreglo[limI], &arreglo[j-1]);
    return j-1;
}

void Swap(int arreglo[], int indiceInicio, int indiceFinal)
{
    int burbuja;
    burbuja = arreglo[indiceInicio];
    arreglo[indiceInicio] = arreglo[indiceFinal];
    arreglo[indiceFinal] = burbuja;
}

void SwapPunteros(int *a, int *b)
{
    int *burbuja = (int*)malloc(sizeof(int));
    *burbuja = *a;
    *a = *b;
    *b = *burbuja;
}



















