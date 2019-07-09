#include <stdlib.h>
#ifndef _LISTADOBLECIRCULARH
#define _LISTADOBLECIRCULARH

typedef struct
{
    int Id;
    char *Titulo;
    int Anyo;
    char *Clasificacion;
    float Calificacion;
    float Duracion;
    char **Generos;
    char *Sinopsis;
}Pelicula;

typedef struct sNodo
{
    Pelicula data;
    struct sNodo *anterior;
    struct sNodo *siguiente;
}Nodo;

typedef struct
{
    Nodo *Cabeza;
    int Cantidad;
}Lista;

Lista* InicializarLista();
void AgregarPelicula(Lista*, Pelicula);
void EliminarPelicula(Lista*, int);
void InsertarPelicula(Lista*, Pelicula, int);
Nodo* BuscarPelicula(Lista*, int);
Lista* OrdenarPelicula(Lista*);

#endif // _LISTADOBLECIRCULARH
