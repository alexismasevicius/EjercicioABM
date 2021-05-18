
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "empleado.h"
#include "utn.h"
#include "datawarehouse.h"


void inicializar (eEmpleado lista[], int tam)
{
    int i;


    for(i=0;i<tam;i++)
    {
       lista[i].isEmpty=1;
    }
}


int buscarLibre(eEmpleado lista[], int len)
{
    int indice=-1;
    for(int i=0; i<len ; i++)
    {
        if(lista[i].isEmpty==1)
        {
            indice=i;
            break;
        }
    }

    return indice;
}



int buscarEmpleado(eEmpleado lista[], int len,int legajo)
{
    int indice=-1;

    for(int i=0 ; i<len ; i ++)
    {
        if(lista[i].legajo == legajo && lista[i].isEmpty==0)
        {
           indice=i;
           break;
        }
    }
    return indice;

}

int altaEmpleado(eEmpleado lista[], int len,int* pLegajo, eSector listaSector[], int lenSector)
{
    int indice;
    eEmpleado auxEmpleado;
    int todoOk = -1;
    char name[50];
    int sector;
    float salary;
    char gender;
    int day;
    int month;
    int year;

    if(lista!=NULL && pLegajo!=NULL && len>0)
    {
        indice=buscarLibre(lista,len);
        if(indice!=-1)
        {
            auxEmpleado.legajo=*pLegajo;

            utn_getNombre("ingrese el nombre: \n","Error\n", 50 ,name);
            strcpy(auxEmpleado.nombre,name);

            mostarSectores(listaSector,lenSector);
            utn_getNumero(&sector,"Ingrese el numero de sector: \n","Error, ingrese nuevamente\n",101,105,100);
            auxEmpleado.sector=sector;

            utn_getNumeroFloat(&salary,"Ingrese el salario\n","Error, ingrese nuevamente\n",1,10000000,100);
            auxEmpleado.salario=salary;

            printf("Ingrese sexo f o m: ");
            fflush(stdin);
            scanf("%c",&gender);
            while(gender!='f' && gender!='m')
            {
                printf("Error. ingrese sexo f o m: ");
                fflush(stdin);
                scanf("%c",&gender);
            }
            auxEmpleado.sexo=gender;

            utn_getNumero(&day,"Ingrese el dia de ingreso: \n","Error, ingrese nuevamente\n",1,31,100);
            auxEmpleado.fIngreso.dia=day;

            utn_getNumero(&month,"Ingrese el mes de ingreso: \n","Error, ingrese nuevamente\n",1,12,100);
            auxEmpleado.fIngreso.mes=month;

            utn_getNumero(&year,"Ingrese el anio de ingreso: \n","Error, ingrese nuevamente\n",1999,2021,100);
            auxEmpleado.fIngreso.anio=year;


            auxEmpleado.isEmpty=0;

            lista[indice] = auxEmpleado;

            (*pLegajo)++;

            todoOk = 1;
        }
        else
        {
            printf("No Hay lugar en el sistema. \n");
        }
    }
    return todoOk;
}

int modificarEmpleados(eEmpleado lista[], int len, eSector listaSector[], int lenSector)
{
    int retorno = 0;
    int eleccion;
    int indice;

    mostarEmpleados(lista,len,listaSector,lenSector);

    utn_getNumero(&eleccion,"\nIngrese el legajo del empleado a modificar\n", "\nError. Ingrese un numero\n", 2000, 3000, 100);

    indice=buscarEmpleado(lista,len,eleccion);

    if(indice!=-1 && lista!=NULL && listaSector!=NULL)
    {
        utn_getNumero(&eleccion,"\nIngrese el dato a modificar:\n1-Nombre.\n2-Sexo.\n3-Salario.\n4-Sector.\n5-Fecha de ingreso.\n",
                  "\nError. Ingrese un numero correcto\n", 1, 5, 100);
        retorno=modificarEmpleado(lista,len,listaSector,lenSector,eleccion,indice);
    }

    return retorno;
}


int modificarEmpleado(eEmpleado lista[], int len, eSector listaSector[], int lenSector, int opcion, int indice)
{
    int retorno = 0;

    char name[50];
    int sector;
    float salary;
    char gender;
    int day;
    int month;
    int year;

    if(lista!=NULL && listaSector!=NULL && opcion>0 && opcion<6)
    {
        switch(opcion)
        {
            case 1:
                utn_getNombre("ingrese el nombre: \n","Error\n", 50 ,name);
                strcpy(lista[indice].nombre,name);
                break;
            case 2:
                printf("Ingrese sexo f o m: ");
                fflush(stdin);
                scanf("%c",&gender);
                while(gender!='f' && gender!='m')
                {
                    printf("Error. ingrese sexo f o m: ");
                    fflush(stdin);
                    scanf("%c",&gender);
                }
                lista[indice].sexo=gender;
                break;
            case 3:
                utn_getNumeroFloat(&salary,"Ingrese el salario\n","Error, ingrese nuevamente\n",1,1000000,100);
                lista[indice].salario=salary;
                break;
            case 4:
                mostarSectores(listaSector,lenSector);
                utn_getNumero(&sector,"Ingrese el numero de sector: \n","Error, ingrese nuevamente\n",101,105,100);
                lista[indice].sector=sector;
                break;
            case 5:
                utn_getNumero(&day,"Ingrese el dia de ingreso: \n","Error, ingrese nuevamente\n",1,31,100);
                lista[indice].fIngreso.dia=day;

                utn_getNumero(&month,"Ingrese el mes de ingreso: \n","Error, ingrese nuevamente\n",1,12,100);
                lista[indice].fIngreso.mes=month;

                utn_getNumero(&year,"Ingrese el anio de ingreso: \n","Error, ingrese nuevamente\n",1999,2021,100);
                lista[indice].fIngreso.anio=year;
                break;
        }
        retorno=1;
    }
    return retorno;
}

//retorna 1 si encontro algun elemento en lista y 0 si no lo encontro
int mostarEmpleados(eEmpleado lista[], int len, eSector listaSector[], int lenSector)
{
    int retorno=0;

    printf("\nLos empleados son: \n\n");
    printf("%-10s| %-25s %-6s %-15s %-20s %-15s |\n","LEGAJO","NOMBRE","SEXO","SALARIO","SECTOR","FECHA");

    for(int i=0 ; i<len ; i++)
    {
        if(mostarEmpleado(lista, i,listaSector, lenSector)==1)
        {
            retorno=1;
        }
    }

    return retorno;
}


int mostarEmpleadosDeUnSector(eEmpleado lista[], int len, eSector listaSector[], int lenSector)
{
    int retorno=0;
    int opcion;

    mostarSectores(listaSector,lenSector);
    utn_getNumero(&opcion,"Ingrese el numero de sector: \n","Error, ingrese nuevamente\n",101,105,100);

    printf("\nLos empleados del sector %d son: \n\n",opcion);
    printf("%-10s| %-25s %-6s %-15s %-20s %-15s |\n","LEGAJO","NOMBRE","SEXO","SALARIO","SECTOR","FECHA");

    for(int i=0 ; i<len ; i++)
    {

        if(lista[i].sector==opcion)
        {
            if(mostarEmpleado(lista, i,listaSector, lenSector)==1)
            {
                retorno=1;
            }
        }
    }
    return retorno;
}


int mostrarEmpleadosTodosSectores(eEmpleado lista[], int len, eSector listaSector[], int lenSector)
{
    int flag = 0;

    printf("\nLISTADO DE EMPLEADOS DE TODOS LOS SECTORES: \n");

    for(int i=0 ; i<lenSector ; i++)
    {
        printf("\nSector: %s \n", listaSector[i].descripcion);

        for(int j=0 ; j<len ; j++)
        {
            if(lista[j].isEmpty==0 && lista[j].sector==listaSector[i].id)
            {
                mostarEmpleado(lista,j,listaSector,lenSector);
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("No hay empleados en este sector.\n");
        }
        flag=0;
    }

    return 0;

}

//retorna 1 si encontro el empleado y 0 si no lo encontro
int mostarEmpleado(eEmpleado lista[], int indice, eSector listaSector[],int lenSector)
{
    int retorno=0;

    char descripcionSector[40];


    if(lista[indice].isEmpty==0)
    {
        cargarDescripcionSector(listaSector,lenSector,lista[indice].sector,descripcionSector);
        printf("%-10d| %-25s %-6c %-15.2f %-20s %02d/%02d/%d      |\n",
               lista[indice].legajo,lista[indice].nombre,
               lista[indice].sexo,lista[indice].salario,
               descripcionSector,lista[indice].fIngreso.dia,
               lista[indice].fIngreso.mes, lista[indice].fIngreso.anio);

        retorno=1;
    }

    return retorno;
}


int cargarDescripcionSector(eSector listaSectores[], int tamSector, int idSector, char descripcionCargar[])
{
    int todoOk=0;


    if(listaSectores!=NULL && descripcionCargar!=NULL && idSector>100 && idSector<106)
    {
        for(int i=0;i<tamSector;i++)
        {
            if(listaSectores[i].id==idSector)
            {
                strcpy(descripcionCargar,listaSectores[i].descripcion);
                todoOk=1;
                break;
            }
        }
    }


    return todoOk;
}



int bajaEmpleado (eEmpleado lista[], int len,eSector listaSector[], int lenSector)
{
    int todoOk=0;
    int legajo;
    int indice;
    int respuesta;


    mostarEmpleados(lista,len,listaSector,lenSector);
    utn_getNumero(&legajo, "\nSeleccione el numero de legajo del empleado a borrar: \n", "\nError ingrese numero valido...\n",0,40000,100);
    indice=buscarEmpleado(lista,len,legajo);

    if(indice==-1)
    {
        printf("\n No hay ningun empleado con ese legajo %d \n",legajo);
    }
    else
    {
        mostarEmpleado(lista,indice,listaSector,lenSector);
        utn_getNumero(&respuesta,"\nConfirma baja? Ingrese 1 para confirmar, 0 para cancelar:\n",
                      "\nError seleccione opcion valida: 1 para confirmar, 0 para cancelar\n",0,1,100);
        if(respuesta==1)
        {
            lista[indice].isEmpty=1;
            todoOk=1;
        }
        else
        {
            printf("\nBaja cancelada\n");
        }
    }

    return todoOk;

}


int cargarNombreEmpleado(int legajo, eEmpleado listaEmpleado[], int tamEmpleado, char descripcionCargar[])
{
    int todoOk=0;
    int indice;


    if(listaEmpleado!=NULL && descripcionCargar!=NULL && legajo>2000 && tamEmpleado>0)
    {
            indice=buscarEmpleado(listaEmpleado,tamEmpleado,legajo);
            if(indice!=-1)
            {
                strcpy(descripcionCargar,listaEmpleado[indice].nombre);
                todoOk=1;
            }

    }

    return todoOk;
}


