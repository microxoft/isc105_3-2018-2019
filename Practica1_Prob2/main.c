#include <stdio.h>
#include <stdlib.h>
#include "Colas.h"

int main()
{
    int opcion;
    int secuencial = 1;
    Cola *perros;
    Cola *gatos;
    perros = InicializarCola();
    gatos = InicializarCola();

    do
    {
        printf("\n\n\n1: Agregar perro.\n");
        printf("2: Agregar gato.\n");
        printf("3: Sacar perro.\n");
        printf("4: Sacar gato.\n");
        printf("5: Sacar cualquiera.\n");
        printf("0: Salir.\n");
        printf("Seleccione: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                printf("Agregando %d como perro.\n", secuencial);
                enqueue(perros, secuencial++);
                break;
            case 2:
                printf("Agregando %d como gato.\n", secuencial);
                enqueue(gatos, secuencial++);
                break;
            case 3:
                if(isEmpty(perros))
                    printf("No hay perros.\n");
                else
                    printf("%.2f\n", dequeue(perros));
                break;
            case 4:
                if(isEmpty(gatos))
                    printf("No hay gatos.\n");
                else
                    printf("%.2f\n", dequeue(gatos));
                break;
            case 5:
                if(!isEmpty(perros) && getFront(perros) < getFront(gatos))
                    printf("%.2f\n", dequeue(perros));
                else if(!isEmpty(gatos))
                    printf("%.2f\n", dequeue(gatos));
                else
                    printf("No hay animales");
                break;
        }
    }while(opcion != 0);
    return 0;
}
