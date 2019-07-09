#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "conio.h"
#include "ListaDobleCircular.h"

typedef enum
{
    Salir = 0,
    Agregar = 1,
    Modificar,
    Eliminar,
    Insertar,
    Explorar,
    Ordenar,
    Buscar
}eSeleccionMenu;

void MostrarMarco();
void MostrarMarco3Columnas();
eSeleccionMenu MostrarMenu();
void AgregarNuevaPelicula(Lista*);
void ExplorarPeliculas(Lista*);
void MostrarPeliculaEnColumna(Pelicula, int);
void MostrarSinopsis(int col, int fila, int limite, char *texto);
const int COL2 = 26, COL3 = 51, LIMCOLUMNA = 24;

int main()
{
    Lista *listadoPeliculas = InicializarLista();
    eSeleccionMenu opcionActual;

    do
    {
        opcionActual = MostrarMenu();
        switch(opcionActual)
        {
            case Agregar:
                AgregarNuevaPelicula(listadoPeliculas);
                break;
            case Modificar:
                break;
            case Eliminar:
                break;
            case Insertar:
                break;
            case Explorar:
                ExplorarPeliculas(listadoPeliculas);
                break;
            case Ordenar:
                break;
            case Buscar:
                break;
        }
    }while(opcionActual != Salir);


    return 0;
}

void MostrarMarco()
{
    int i;
    system("cls");
    // Bloque de título:
    printf("%c", 201); // Esquina superior izquierda.
    for(i=0;i<63;i++)
        printf("%c", 205); // Líneas horizontales.
    printf("%c\n", 187); // Esquina superior derecha.

    // Espacio para el título:
    for(i=0;i<3;i++)
        printf("%c\t\t\t\t\t\t\t\t%c\n", 186, 186); // Laterales.

    // Separador del bloque de título:
    printf("%c", 204); // Esquina superior izquierda.
    for(i=0;i<63;i++)
        printf("%c", 205); // Líneas horizontales.
    printf("%c\n", 185); // Esquina superior derecha.

    for(i=0;i<18;i++)
        printf("%c\t\t\t\t\t\t\t\t%c\n", 186, 186); // Laterales.
    printf("%c", 200); // Esquina inferior izquierda.
    for(i=0;i<63;i++)
        printf("%c", 205); // Líneas horizontales.
    printf("%c\n", 188); // Esquina inferior derecha.
}

eSeleccionMenu MostrarMenu()
{
    int seleccion;
    do
    {
        MostrarMarco();
        gotoxy(25,3);
        printf("Gesti%cn de Pel%cculas", 162, 161);
        gotoxy(5,7);
        printf("1: Agregar una pel%ccula al final.", 161);
        gotoxy(5,9);
        printf("2: Modificar una pel%ccula dado un ID.", 161);
        gotoxy(5,11);
        printf("3: Eliminar una pel%ccula dado un ID.", 161);
        gotoxy(5,13);
        printf("4: Agregar una pel%ccula en orden de a%co.", 161, 164);
        gotoxy(5,15);
        printf("5: Explorar las pel%cculas registradas.", 161);
        gotoxy(5,17);
        printf("6: Buscar una pel%ccula por a%co.", 161, 164);
        gotoxy(5,19);
        printf("7: Ordenar pel%cculas por a%co.", 161, 164);
        gotoxy(5,22);
        printf("0: Salir de la aplicaci%cn.", 162);

        fflush(stdin);
        _setcursortype(0);
        seleccion = getch() - 48;
    }while(seleccion < 0 || seleccion > 7);

    _setcursortype(1);
    return seleccion;
}

void AgregarNuevaPelicula(Lista *listado)
{
    short generosSeleccionados[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int seleccion, i, j=0;
    Pelicula nuevaPelicula;
    system("cls");
    MostrarMarco();
    gotoxy(10,3);
    printf("Agregando nueva pel%cula al final de la lista.", 161);
    gotoxy(5,7);
    printf("Id: ");
    scanf("%d", &nuevaPelicula.Id);
    gotoxy(5,9);
    printf("T%ctulo (hasta 100 letras): ", 161);
    nuevaPelicula.Titulo = (char*)malloc(100);
    fflush(stdin);
    gets(nuevaPelicula.Titulo);
    gotoxy(5, 11);
    printf("A%co: ", 164);
    scanf("%d", &nuevaPelicula.Anyo);
    gotoxy(5, 13);
    do
    {
        printf("Seleccione una clasificaci%cn: \n\t\t", 162);
        printf("1: G (prop%csito general)\n\t\t", 162);
        printf("2: PG (supervisi%cn parental)\n\t\t", 162);
        printf("3: PG-13 (no apta para menores de 13 a%cos.)\n\t\t", 164);
        printf("4: R (restringido para mayor de edad)\n\t\t");
        printf("5: NC-17 (solo adultos)\n\t\t");
        printf("Seleccione: ");
        seleccion = getch() - 48;
    }while(seleccion < 1 || seleccion > 5);
    nuevaPelicula.Clasificacion = (char*)calloc(6, sizeof(char));
    switch(seleccion)
    {
        case 1:
            strcpy(nuevaPelicula.Clasificacion, "G");
            break;
        case 2:
            strcpy(nuevaPelicula.Clasificacion, "PG");
            break;
        case 3:
            strcpy(nuevaPelicula.Clasificacion, "PG-13");
            break;
        case 4:
            strcpy(nuevaPelicula.Clasificacion, "R");
            break;
        case 5:
            strcpy(nuevaPelicula.Clasificacion, "NC-17");
            break;
    }
    gotoxy(5, 21);
    printf("Calificaci%cn: ", 162);
    scanf("%f", &nuevaPelicula.Calificacion);
    gotoxy(5, 23);
    printf("Duraci%cn (minutos): ", 162);
    scanf("%f", &nuevaPelicula.Duracion);

    do
    {
        do
        {
            system("CLS");
            MostrarMarco();
            gotoxy(10,3);
            printf("Agregando nueva pel%cula al final de la lista.", 161);
            // Mostramos los géneros:
            gotoxy(5, 7);
            printf("Seleccione los g%cneros de la pel%cula:\n\t", 130, 161);
            printf("1: Acci%cn\t", 162);
            printf("2: Aventura\t");
            printf("3: Comedia\n\t");
            printf("4: Drama\t");
            printf("5: Terror\t");
            printf("6: Musical\n\t");
            printf("7: C. ficci%cn\t", 162);
            printf("8: Suspenso\t");
            printf("9: Infantil\n\n\t");
            printf("0: Salir\n\n\t");
            printf("Seleccione: ");
            fflush(stdin);
            seleccion = getch() - 48;
        }while(seleccion < 0 || seleccion > 9);

        if(seleccion != 0)
            generosSeleccionados[seleccion - 1] = generosSeleccionados[seleccion - 1] > 0 ? 0 : 1;
    }while(seleccion != 0);

    nuevaPelicula.Generos = (char**)malloc(sizeof(char*)*9);
    for(i=0, j=0; i<9; i++)
    {
        if(generosSeleccionados[i])
        {
            nuevaPelicula.Generos = (char**)realloc(nuevaPelicula.Generos, j+1);
            *(nuevaPelicula.Generos+j) = (char*)calloc(20, sizeof(char));
            switch(i)
            {
                case 0:
                    strcpy(*(nuevaPelicula.Generos+j), "Accion");
                    break;
                case 1:
                    strcpy(*(nuevaPelicula.Generos+j), "Aventura");
                    break;
                case 2:
                    strcpy(*(nuevaPelicula.Generos+j), "Comedia");
                    break;
                case 3:
                    strcpy(*(nuevaPelicula.Generos+j), "Drama");
                    break;
                case 4:
                    strcpy(*(nuevaPelicula.Generos+j), "Terror");
                    break;
                case 5:
                    strcpy(*(nuevaPelicula.Generos+j), "Musical");
                    break;
                case 6:
                    strcpy(*(nuevaPelicula.Generos+j), "Ciencia Ficcion");
                    break;
                case 7:
                    strcpy(*(nuevaPelicula.Generos+j), "Suspenso");
                    break;
                case 8:
                    strcpy(*(nuevaPelicula.Generos+j), "Infantil");
                    break;
            }
            j++;
        }
    }

    printf("\n\n\tSinopsis (hasta 200 letras): ");
    nuevaPelicula.Sinopsis = (char*)malloc(200);
    fflush(stdin);
    gets(nuevaPelicula.Sinopsis);

    AgregarPelicula(listado, nuevaPelicula);
}

void MostrarMarco3Columnas()
{
    int i;
    system("cls");
    printf("%c", 201); // Esquina superior izquierda.
    for(i=0;i<24;i++)
        printf("%c", 205); // Líneas horizontales.
    printf("%c", 203);
    for(i=0;i<24;i++)
        printf("%c", 205); // Líneas horizontales.
    printf("%c", 203);
    for(i=0;i<24;i++)
        printf("%c", 205); // Líneas horizontales.
    printf("%c\n", 187); // Esquina superior derecha.

    for(i=2;i<24;i++)
    {
        gotoxy(0, i);
        printf("%c", 186); // Laterales.
        gotoxy(COL2, i);
        printf("%c", 186); // Laterales.
        gotoxy(COL3, i);
        printf("%c", 186); // Laterales.
        gotoxy(76, i);
        printf("%c\n", 186);
    }

    printf("%c", 200); // Esquina inferior izquierda.
    for(i=0;i<24;i++)
        printf("%c", 205); // Líneas horizontales.
    printf("%c", 202);
    for(i=0;i<24;i++)
        printf("%c", 205); // Líneas horizontales.
    printf("%c", 202);
    for(i=0;i<24;i++)
        printf("%c", 205); // Líneas horizontales.
    printf("%c\n", 188); // Esquina inferior derecha.
}

void ExplorarPeliculas(Lista *listado)
{
    char seleccion;
    Nodo *nodoActual = listado->Cabeza->siguiente;

    do
    {
        MostrarMarco3Columnas();

        if(nodoActual->data.Id == -1) // if(listado->Cantidad == 0)
        {
            printf("No hay pel%cculas registradas.", 161);
            break;
        }
        MostrarPeliculaEnColumna(nodoActual->data, 2);
    }while(tolower(seleccion) != 'x');
}

void MostrarPeliculaEnColumna(Pelicula aMostrar, int numeroColumna)
{
    int colActual, i=0;
    if(numeroColumna <= 1)
        colActual = 0;
    else if(numeroColumna == 2)
        colActual = COL2;
    else
        colActual = COL3;

    gotoxy(colActual + 1, 3);
    printf("%4.4d - %.*s", aMostrar.Id, LIMCOLUMNA, aMostrar.Titulo);

    gotoxy(colActual + 1, 5);
    printf("%4d - %.1f/10 - %.1fmins.",
           aMostrar.Anyo, aMostrar.Calificacion, aMostrar.Duracion);
    gotoxy(colActual + 1, 7);
    printf("Clasif.: %.20s", aMostrar.Clasificacion);
    gotoxy(colActual + 1, 9);
    while(aMostrar.Generos+i != EOF) // o NULL.
    {
        printf("%.*s", LIMCOLUMNA, *(aMostrar.Generos+i));
        i++;
        gotoxy(colActual + 1, 9 + i);
    }
    gotoxy(colActual + 1, 10 + i);
    MostrarSinopsis(colActual + 1, 10+i, LIMCOLUMNA, aMostrar.Sinopsis);
}

void MostrarSinopsis(int col, int fila, int limite, char *texto)
{
    int i = 0;
    while(strlen(texto) > 0)
    {
        gotoxy(col, fila+i);
        printf("%.*s", limite, texto);
        texto = strcpy(texto, texto+limite);//texto+=limite;

        i++;
    }
}













