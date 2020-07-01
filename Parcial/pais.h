#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED
typedef struct
{
    int id;
    char pais[20];
    int recuperados;
    int infectados;
    int muertos;
}ePais;


#endif // PAIS_H_INCLUDED

ePais* nuevoPaisStr (char* idStr,char* pais,char* recuperadosStr,char* infectadosStr, char* muertosStr);
ePais* nuevoPaisParam(int id,char* pais,int recuperados,int infectados,int muertos);
ePais* nuevoPaisStr (char* idStr,char* pais,char* recuperadosStr,char* infectadosStr, char* muertosStr);
int setId (ePais* lista,int id);
int setPais(ePais* lista,char* pais);
int setMuertos(ePais* lista,int muertos);
int setInfectados(ePais* lista,int infectados);
int setRecuperados(ePais* lista,int recuperados);
int getId(ePais* lista,int* id);
int getPais(ePais* lista,char* pais);
int getMuertos(ePais* lista,int* muertos);
int getInfectados(ePais* lista,int* infectados);
int getRecuperados(ePais* lista,int* recuperados);
int getRandomMuertos();
int getRandomInfectados();
int getRandomRecuperados();
void muertosSeteado(void* muertos);
void infectadosSeteado(void* infectados);
void recuperadosSeteado(void* recuperados);
int filtrarPaisesExitosos(void* pais);
int filtrarPaisesHorno(void* pais);
int ordenarInfectados(void* a, void* b);
