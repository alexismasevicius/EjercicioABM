#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "empleado.h"
#include "utn.h"
#include "informes.h"





int totalSueldosSector(eEmpleado lista[], int len,eSector listaSector[], int lenSector)
{
    int opcion;
    int acumulador=0;
    char nombreSector[50];
    int flag  = 0;
    int flag2 = 0;

    system("cls");
    mostarSectores(listaSector,lenSector);
    utn_getNumero(&opcion,"Ingrese el numero de sector que desea saber el numero de sueldos: \n","Error, ingrese nuevamente\n",101,105,100);

    for(int i=0; i<lenSector; i++)
    {
        if(opcion==listaSector[i].id && listaSector[i].isEmpty==0)
        {
            strcpy(nombreSector,listaSector[i].descripcion);
            flag=1;
        }
    }

    for(int j=0 ; j<len ; j++)
    {
        if(lista[j].isEmpty==0 && opcion==lista[j].sector)
        {
            acumulador=acumulador+lista[j].salario;
            flag2=1;
        }
    }

    if(flag==0 || flag2==0)
    {
        printf("No hay empleados en este sector o el sector no está cargado.\n");
    }
    else
    {
        printf("La suma de los sueldos del sector %s, es de: %d", nombreSector, acumulador );
    }

    return 0;

}



int totalADepositar(eEmpleado lista[], int len,eSector listaSector[], int lenSector)
{
    int acumuladorParcial=0;
    int acumuladorTotal=0;

    int auxId;

    system("cls");

    for(int i; i<lenSector ; i++)
    {
        if(listaSector[i].isEmpty==0)
        {
            auxId=lista[i].sector;
            printf("\n------SECTOR: %s ---------------------------\n", listaSector[i].descripcion);

            for(int j=0 ; j<len ; j++)
            {
                if(lista[j].isEmpty==0 && auxId==lista[j].sector)
                {
                    mostarEmpleado(lista,j,listaSector,lenSector);
                    acumuladorParcial=acumuladorParcial+lista[j].salario;
                    acumuladorTotal=acumuladorTotal+lista[j].salario;

                }
            }
            printf("El total a depositar en el sector %s es de = %d",listaSector[i].descripcion,acumuladorParcial);
            acumuladorParcial=0;
            printf("\n---------------------------------------------\n");
        }
    }

    printf("El total de sueldos a depositar es de = %d",acumuladorTotal);


    return 0;

}


int sectorMayorSueldo(eEmpleado lista[], int len,eSector listaSector[], int lenSector)
{
    float acumuladorParcial=0;
    float totales[lenSector];
    float auxMayorSueldo=0;
    int flag;

    int auxId;

    system("cls");

    for(int i; i<lenSector ; i++)
    {
        if(listaSector[i].isEmpty==0)
        {
            auxId=lista[i].sector;
            for(int j=0 ; j<len ; j++)
            {
                if(lista[j].isEmpty==0 && auxId==lista[j].sector)
                {
                    acumuladorParcial=acumuladorParcial+lista[j].salario;
                }
            }
            totales[i]=acumuladorParcial;
            acumuladorParcial=0;
        }
    }


    for(int k=0; k<lenSector;k++)
    {
        if(flag==0 || totales[k]>auxMayorSueldo)
        {
            auxMayorSueldo=totales[k];
            flag=1;
        }
    }
    printf("\nLos sectores que mas ganan son:\n");
     for(int i=0; i<lenSector;i++)
    {
        if(auxMayorSueldo == totales[i])
        {
            printf("\n%s.\n", listaSector[i].descripcion);
        }

    }



    return 0;

}

