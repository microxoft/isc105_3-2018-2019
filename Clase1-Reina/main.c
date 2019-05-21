#include <stdio.h>
#include <stdlib.h>
#include "versionPunteros.h"
#include "versionMatriz.h"

int main()
{
    int filaReina, columnaReina;

    printf("Digite la posici%cn inicial: ", 162);
    scanf("%d %d", &filaReina, &columnaReina);

    //mainMatriz(filaReina, columnaReina);
    mainPunteros(filaReina, columnaReina);

    return 0;
}
