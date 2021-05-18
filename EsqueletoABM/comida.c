
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "empleado.h"
#include "utn.h"
#include "datawarehouse.h"
#include "comida.h"





int mostrarComidas(eComida lista[], int lenC)
{
    int retorno=0;

    printf("\nLas comidas son: \n\n");
    printf("%-10s| %-25s  %-10s |\n","ID","DESCRIPCION", "PRECIO");

    for(int i=0 ; i<lenC ; i++)
    {

        if(mostrarComida(lista, i)==1)
        {
            retorno=1;
        }
    }

    return retorno;
}



int mostrarComida(eComida lista[], int indice)
{

    int retorno=0;

    if(lista[indice].isEmpty==0)
    {
        printf("%-10d| %-25s  %-10f |\n",
               lista[indice].id,
               lista[indice].descripcion,
               lista[indice].precio);
        retorno=1;
    }

    return retorno;
}


int cargarDescripcionComida(eComida listacomidas[], int tamCom, int idCom, char descripcionCargar[])
{
    int todoOk=0;


    if(listacomidas!=NULL && descripcionCargar!=NULL)
    {
        for(int i=0;i<tamCom;i++)
        {
            if(listacomidas[i].id==idCom)
            {
                strcpy(descripcionCargar,listacomidas[i].descripcion);
                todoOk=1;
                break;
            }
        }
    }


    return todoOk;
}
