
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "sectores.h"
#include "utn.h"
#include "datawarehouse.h"



int mostarSectores(eSector listaSector[], int lenSector)
{
    int retorno=0;

    printf("\nLos sectores son: \n\n");
    printf("%-10s| %-25s |\n","ID","SECTOR");

    for(int i=0 ; i<lenSector ; i++)
    {
        if(mostarSector(listaSector, i)==1)
        {
            retorno=1;
        }
    }

    return retorno;
}

//retorna 1 si encontro  y 0 si no lo encontro
int mostarSector(eSector listaSector[], int indice)
{
    int retorno=0;

    if(listaSector[indice].isEmpty==0)
    {
        printf("%-10d| %-25s  |\n",
               listaSector[indice].id,listaSector[indice].descripcion);

        retorno=1;
    }

    return retorno;
}
