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
    int CantidadGeneros;
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
void AgregarPelicula(Pelicula, Nodo*);
void EliminarPelicula(Lista*, Nodo*);
void InsertarPelicula(Lista*, Pelicula, int);
Nodo* BuscarPorId(Lista*, int);
Nodo* BuscarPorAnyo(Lista*, int);
Lista* OrdenarPeliculaSeleccion(Lista*);
Nodo* CopiarNodo(Nodo*);
void Intercambiar(Nodo*, Nodo*);

#endif // _LISTADOBLECIRCULARH





