#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "time.h"
#include "utn.h"
#include "pais.h"
#include "funciones.h"



int menu();

int main()
{
    LinkedList* lista = ll_newLinkedList();
    int opcion;
    cargarDatos(lista,"pandemia.csv");

    srand(time(NULL));

    do
    {
        system("cls");
        opcion=menu();

        switch(opcion)
        {
        case 1:
            system("cls");
            if(cargarDatos(lista,"pandemia.csv"))
            {
                printf("Archivo cargado con exito.\n");
            }
            else
            {
                printf("No se a podido cargar el archivo.\n");
            }
            system("pause");
            break;
        case 2:
            system("cls");
            if(listarPaises(lista))
            {

            }
            else
            {
                printf("No hay paises que mostrar\n");
            }
            system("pause");

            break;
        case 3:
            system("cls");
            if(asignarEstadisticas(lista))
            {
                printf("Estadisticas asignadas con exito\n");
            }
            else
            {
                printf("Error al asignar estadisticas\n");
            }
            system("pause");

            break;
        case 4:
            system("cls");
            if(paisesExitosos(lista))
            {
                printf("Paises filtrados con exito\n");
            }
            else
            {
                printf("Error al filtrar\n");
            }
            system("pause");
            break;
        case 5:
            system("cls");
            if(paisesHorno(lista))
            {
                printf("Paises filtrados con exito\n");
            }
            else
            {
                printf("Error al filtrar\n");
            }
            system("pause");
            break;
        case 6:
            system("cls");
            if(ordenarPaises(lista))
            {
                printf("Paises ordenados con exito\n");
            }
            else
            {
                printf("Error al ordenar\n");
            }
            system("pause");
            break;
        case 7:
            system("cls");
            if(paisCastigado(lista))
            {
            }
            else
            {
                printf("Error al buscar el pais mas castigado\n");
            }
            system("pause");

            break;
        }
    }while(opcion!=8);

    return 0;
}

int menu()
{
    int opcion;

    printf("                               *****MENU*****\n\n");
    printf("1. Cargar archivo\n");
    printf("2. Imprimir lista\n");
    printf("3. Asignar estadisticas\n");
    printf("4. Filtrar por paises exitosos\n");
    printf("5. Filtrar por paises en el horno\n");
    printf("6. Ordenar por nivel de infeccion\n");
    printf("7. Mostrar el mas castigado\n");
    printf("8. Salir\n");
    utn_getEntero(&opcion,20,"\nElija una opcion: ","Error. Vuelva a intentarlo: ",1,8);

    return opcion;
}

