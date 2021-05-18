#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "almuerzo.h"
#include "comida.h"
#include "empleado.h"
#include "utn.h"
#include "datawarehouse.h"


void inicializarAlmuerzo (eAlmuerzo listaAlmuerzo[], int tamAlmuerzo)
{
    int i;

    for(i=0;i<tamAlmuerzo;i++)
    {
       listaAlmuerzo[i].isEmpty=1;
    }
}


int altaAlmuerzo(eAlmuerzo listaAlmuerzo[], int tamAlmuerzo, eComida listaComida[], int tamComida, eEmpleado listaEmpleado[], int tamEmpleado, eSector listaSector[], int tamSector, int* pNextId)
{
    int indice;
    eAlmuerzo auxAlmuerzo;
    int todoOk = -1;
    int meal;
    int idEmployee;
    int day;
    int month;
    int year;

    if(listaAlmuerzo!=NULL && pNextId!=NULL && tamAlmuerzo>0)
    {
        indice=buscarLibreAlmuerzo(listaAlmuerzo,tamAlmuerzo);
        if(indice!=-1)
        {
            auxAlmuerzo.id=*pNextId;

            mostrarComidas(listaComida,tamComida);
            utn_getNumero(&meal,"Ingrese el id de comida: \n","Error, ingrese nuevamente\n",1000,1004,100);
            auxAlmuerzo.idComida=meal;

            mostarEmpleados(listaEmpleado,tamEmpleado,listaSector,tamSector);
            utn_getNumero(&idEmployee,"Ingrese el legajo de empleado al cual adjudicar comida: \n","Error, ingrese nuevamente\n",2000,3000,100);
            while(buscarEmpleado(listaEmpleado,tamEmpleado,idEmployee)==-1)
            {
                mostarEmpleados(listaEmpleado,tamEmpleado,listaSector,tamSector);
                utn_getNumero(&idEmployee,"Ingrese el legajo de empleado al cual adjudicar comida: \n","Error, ingrese nuevamente\n",2000,3000,100);
            }
            auxAlmuerzo.legEmpleado=idEmployee;

            utn_getNumero(&day,"Ingrese el dia de la comida: \n","Error, ingrese nuevamente\n",1,31,100);
            auxAlmuerzo.fecha.dia=day;

            utn_getNumero(&month,"Ingrese el mes de la comida: \n","Error, ingrese nuevamente\n",1,12,100);
            auxAlmuerzo.fecha.mes=month;

            utn_getNumero(&year,"Ingrese el anio de la comida: \n","Error, ingrese nuevamente\n",2021,3000,100);
            auxAlmuerzo.fecha.anio=year;


            auxAlmuerzo.isEmpty=0;

            listaAlmuerzo[indice] = auxAlmuerzo;

            (*pNextId)++;

            todoOk = 1;
        }
        else
        {
            printf("No Hay lugar en el sistema. \n");
        }
    }
    return todoOk;


}


int mostrarAlmuerzos(eAlmuerzo listaAlmuerzo[], int tamAlmuerzo, eComida listaComida[], int tamComida, eEmpleado listaEmpleado[], int tamEmpleado)
{
    int retorno=0;

    printf("\nLos almuerzos son: \n\n");
    printf("%-10s|%-15s %-25s %-20s %-15s |\n","ID","LEGAJO","NOMBRE","COMIDA","FECHA");

    for(int i=0 ; i<tamAlmuerzo ; i++)
    {
        if(mostrarAlmuerzo(listaAlmuerzo,tamAlmuerzo,listaComida,tamComida,listaEmpleado,tamEmpleado,i)==1)
        {
            retorno=1;
        }
    }

    return retorno;



}
int mostrarAlmuerzo(eAlmuerzo listaAlmuerzo[], int tamAlmuerzo, eComida listaComida[], int tamComida, eEmpleado listaEmpleado[], int tamEmpleado, int indice)
{

    int retorno=0;

    char nombreEmpleado[50];
    char nombreComida[50];



    if(listaAlmuerzo[indice].isEmpty==0)
    {
        cargarNombreEmpleado(listaAlmuerzo[indice].legEmpleado,listaEmpleado,tamEmpleado,nombreEmpleado);
        cargarDescripcionComida(listaComida,tamComida,listaAlmuerzo[indice].idComida,nombreComida);
        printf("%-10d|%-15d %-25s %-20s %02d/%02d/%d      |\n",
               listaAlmuerzo[indice].id,
               listaAlmuerzo[indice].legEmpleado,
               nombreEmpleado,
               nombreComida,
               listaAlmuerzo[indice].fecha.dia,
               listaAlmuerzo[indice].fecha.mes,
               listaAlmuerzo[indice].fecha.anio
               );

        retorno=1;
    }

    return retorno;



}

int buscarLibreAlmuerzo(eAlmuerzo listaAlmuerzo[], int len)
{
    int indice=-1;
    for(int i=0; i<len ; i++)
    {
        if(listaAlmuerzo[i].isEmpty==1)
        {
            indice=i;
            break;
        }
    }

    return indice;
}
