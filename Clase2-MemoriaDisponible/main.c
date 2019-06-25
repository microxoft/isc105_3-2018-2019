#include <stdio.h>
#include <stdlib.h>

int main()
{
    long contador = 0;
    int *puntero;

    while((puntero = (int*)malloc(sizeof(int)))!= NULL)
    {
        contador++;
    }

    printf("%ld MB\n", (contador*sizeof(int))/1073741824);
    return 0;
}
