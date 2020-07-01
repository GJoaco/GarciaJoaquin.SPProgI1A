
#include <stdio.h>
#include <stdlib.h>
#include "pais.h"

ePais* nuevoPais()
{
    ePais* nuevo = (ePais*) malloc(sizeof(ePais));

    if(nuevo!= NULL)
    {
        nuevo->id=0;
        nuevo->infectados=0;
        nuevo->muertos=0;
        nuevo->recuperados=0;
        strcpy(nuevo->pais, "");
    }

    return nuevo;
}

/** \brief Asigna los datos pasados como parametros a un nuevo empleado
 *
 * \param Id
 * \param Nombre
 * \param Horas trabajadas
 * \param Sueldo
 * \return Empleado cargado
 *
 */

ePais* nuevoPaisParam(int id,char* pais,int recuperados,int infectados,int muertos)
{
    ePais* nuevo = nuevoPais();

    if(nuevo!=NULL)
    {
        if(!(setId(nuevo,id)
           && setPais(nuevo,pais)
           && setInfectados(nuevo,infectados)
           && setMuertos(nuevo,muertos)
           && setRecuperados(nuevo,recuperados)))
        {
            free(nuevo);

            nuevo = NULL;
        }
    }

    return nuevo;
}
ePais* nuevoPaisStr (char* idStr,char* pais,char* recuperadosStr,char* infectadosStr, char* muertosStr)
{

    return nuevoPaisParam(atoi(idStr),pais,atoi(recuperadosStr),atoi(infectadosStr),atoi(muertosStr));
}

int setId (ePais* lista,int id)
{
    int retorno=0;

    if(lista!=NULL && id>=0)
    {
        lista->id=id;
        retorno=1;
    }

    return retorno;
}
/** \brief Asigna un nombre a un empleado
 *
 * \param Empleado al que se le asigna el nombre
 * \param nombre que se le quiere asignar
 * \return 1 si la asignacion fue realizada 0 si no
 *
 */
int setPais(ePais* lista,char* pais)
{
    int retorno=0;

    if(lista!=NULL && pais!=NULL && strlen(pais) > 1 && strlen(pais) < 20)
    {
        strcpy(lista->pais,pais);
        retorno=1;
    }

    return retorno;
}
/** \brief Asigna un numero de horas a un empleado
 *
 * \param Empleado al que se le asignan las horas
 * \param horas que se le quiere asignar
 * \return 1 si la asignacion fue realizada 0 si no
 *
 */
int setMuertos(ePais* lista,int muertos)
{
    int retorno=0;

    if(lista!=NULL && muertos>=0)
    {
        lista->muertos=muertos;
        retorno=1;
    }

    return retorno;
}
/** \brief Asigna un sueldo a un empleado
 *
 * \param Empleado al que se le asigna el sueldo
 * \param sueldo que se le quiere asignar
 * \return 1 si la asignacion fue realizada 0 si no
 *
 */
int setInfectados(ePais* lista,int infectados)
{
    int retorno=0;

    if(lista!=NULL && infectados>=0)
    {
        lista->infectados=infectados;
        retorno=1;

    }

    return retorno;
}

int setRecuperados(ePais* lista,int recuperados)
{
    int retorno=0;

    if(lista!=NULL && recuperados>=0)
    {
        lista->recuperados=recuperados;
        retorno=1;

    }

    return retorno;
}

int getId(ePais* lista,int* id)
{
    int retorno=0;

    if(lista!=NULL && id!=NULL)
    {
        *id=lista->id;
        retorno=1;
    }

    return retorno;
}

int getPais(ePais* lista,char* pais)
{
    int retorno=0;

    if(lista!=NULL && pais!=NULL)
    {
        *pais=lista->pais;
        retorno=1;
    }

    return retorno;
}

int getMuertos(ePais* lista,int* muertos)
{
    int retorno=0;

    if(lista!=NULL && muertos!=NULL)
    {
        *muertos=lista->muertos;
        retorno=1;
    }

    return retorno;
}

int getInfectados(ePais* lista,int* infectados)
{
    int retorno=0;

    if(lista!=NULL && infectados!=NULL)
    {
        *infectados=lista->infectados;
        retorno=1;
    }

    return retorno;
}

int getRecuperados(ePais* lista,int* recuperados)
{
    int retorno=0;

    if(lista!=NULL && recuperados!=NULL)
    {
        *recuperados=lista->recuperados;
        retorno=1;
    }

    return retorno;
}

int getRandomMuertos()
{
    int aleatorio;

    aleatorio = rand()% 49001 + 1000;

    return aleatorio;
}

int getRandomInfectados()
{
    int aleatorio;

    aleatorio = rand()% 1960001 + 40000;

    return aleatorio;
}

int getRandomRecuperados()
{
    int aleatorio;

    aleatorio = rand()% 950001 + 50000;

    return aleatorio;
}

void muertosSeteado(void* muertos)
{
    ePais* auxMuertos;

    auxMuertos = (ePais*)muertos;
    setMuertos(auxMuertos, getRandomMuertos());

    return auxMuertos;
}

void infectadosSeteado(void* infectados)
{
    ePais* auxInfectados;

    auxInfectados = (ePais*)infectados;
    setInfectados(auxInfectados, getRandomInfectados());

    return auxInfectados;
}

void recuperadosSeteado(void* recuperados)
{
    ePais* auxRecuperados;

    auxRecuperados = (ePais*)recuperados;
    setRecuperados(auxRecuperados, getRandomRecuperados());

    return auxRecuperados;
}

int filtrarPaisesExitosos(void* pais)
{
    int retorno=0;
    ePais* aux;

    if(pais!=NULL)
    {
        aux=(ePais*) pais;
        if(aux->muertos < 5000)
        {
            retorno=1;
        }
    }

    return retorno;
}
int filtrarPaisesHorno(void* pais)
{
    int retorno=0;
    ePais* aux;

    if(pais!=NULL)
    {
        aux=(ePais*) pais;
        if(aux->infectados > aux->recuperados*3)
        {
            retorno=1;
        }
    }

    return retorno;
}

int ordenarInfectados(void* a, void* b)
{
    int retorno=0;
    ePais* p1;
    ePais* p2;

    if(a!=NULL && b!=NULL)
    {
        p1=(ePais*) a;
        p2=(ePais*) b;

         if(p1->infectados > p2->infectados)
         {
             retorno=1;
         }
         else if(p1->infectados < p2->infectados)
         {
             retorno=-1;
         }

    }



    return retorno;
}
