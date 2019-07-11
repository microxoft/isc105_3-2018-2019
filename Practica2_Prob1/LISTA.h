#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct sNodo
{
    int data;
    struct sNodo *siguiente;
}Nodo;

typedef struct
{
    Nodo *Cabeza;
    int tamano;
}Lista;

Lista* InicializarLista();
void AgregarEnCola(Lista*, int);
void Intercambiar(Nodo*, Nodo*);

#endif // LISTA_H_INCLUDED
