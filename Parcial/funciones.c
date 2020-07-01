#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "pais.h"

int cargarDatos(LinkedList* lista,char* file)
{
    int retorno=0;
    char buffer[5][20];
    ePais* aux;
    FILE* f;

    f=fopen(file,"r");

    if(f != NULL)
    {
        fscanf(f,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);

        while(!feof(f))
        {
            fscanf(f,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);

            aux = nuevoPaisStr(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);
            if(aux!=NULL)
            {
                ll_add(lista,aux);
            }
            else
            {
                printf("Error\n");
            }
        }
    }

    if(!(ll_isEmpty(lista)))
    {
        retorno=1;
    }

    fclose(f);

    return retorno;
}

int guardarDatos(char* file, LinkedList* lista)
{
    int retorno=0;
    FILE* f = fopen(file,"w");
    int tam;
    ePais* aux;

    tam=ll_len(lista);

    if(lista != NULL && f != NULL)
    {
        retorno=1;

        fprintf(f,"id,pais,recuperados,infectados,muertos\n");

        for(int i=0; i<tam; i++)
        {
            aux = (ePais*) ll_get(lista,i);
            if(aux!= NULL)
            {
                fprintf(f,"%d,%s,%d,%d,%d\n",aux->id,aux->pais,aux->recuperados,aux->infectados,aux->muertos );
            }
        }
        fclose(f);
    }

    return retorno;
}

int listarPaises(LinkedList* lista)
{
    int retorno=0;
    int tam;
    ePais* aux;

    tam= ll_len(lista);

    printf("Id   Pais               Recuperados   Infectados    Muertos\n");
    for(int i=0; i<tam; i++)
    {
        aux = ll_get(lista,i);
        if(aux!=NULL)
        {
            retorno=1;
            printf("%-4d %-18s   %4d            %d           %d\n",aux->id,aux->pais,aux->recuperados,aux->infectados,aux->muertos);
        }


    }

    return retorno;
}

int asignarEstadisticas(LinkedList* lista)
{
    int retorno;
    ePais* aux;

    if(lista!=NULL)
    {
        ll_map(lista,infectadosSeteado);
        ll_map(lista,muertosSeteado);
        ll_map(lista,recuperadosSeteado);
        retorno=1;
    }

    return retorno;
}

int paisesExitosos(LinkedList* lista)
{
    int retorno=0;
    LinkedList* listaAux;

    if(lista!=NULL && listaAux!=NULL)
    {
        listaAux=ll_newLinkedList();
        listaAux=ll_filter(lista,filtrarPaisesExitosos);

        guardarDatos("paisesExitosos.csv",listaAux);

        retorno=1;

    }

    return retorno;
}

int paisesHorno(LinkedList* lista)
{
    int retorno=0;
    LinkedList* listaAux;

    if(lista!=NULL && listaAux!=NULL)
    {
        listaAux=ll_newLinkedList();
        listaAux=ll_filter(lista,filtrarPaisesHorno);

        guardarDatos("paisesHorno.csv",listaAux);
        retorno=1;

    }

    return retorno;
}

int ordenarPaises(LinkedList* lista)
{
    int retorno=0;
    if(lista!=NULL)
    {
        ll_sort(lista,ordenarInfectados,0);
        retorno=1;
    }

    return retorno;
}

int paisCastigado(LinkedList* lista)
{
    int retorno=0;
    ePais* aux;
    int tam=ll_len(lista);
    char nombrePais[100];
    int mayorMuertos=-1;
    int flag=0;

    for(int i=0; i<tam; i++)
    {
        aux=ll_get(lista,i);
        if(aux->muertos > mayorMuertos)
        {
            mayorMuertos=aux->muertos;
            strcpy(nombrePais,aux->pais);
            retorno=1;
        }
        if(aux->muertos == mayorMuertos)
        {
            strcat(nombrePais,", ");
            strcat(nombrePais,aux->pais);
            flag=1;
        }
    }

    if(flag)
    {
        printf("Los paises mas castigados son: %s",nombrePais);
    }
    else
    {
        printf("El pais mas castigado es %s",nombrePais);
    }

    return retorno;
}

