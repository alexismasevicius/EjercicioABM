#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "datawarehouse.h"


static char nombres[10][30]={
            "Donato",
            "German",
            "Damian",
            "Gaston",
            "Daniela",
            "Andrea",
            "Daniel",
            "Candela",
            "Georgina",
            "Maria"};

static char sexos[10]={'m', 'm', 'm', 'm', 'f', 'm', 'm', 'f', 'f', 'f'};

//static char edades[10]={57, 52, 37, 30, 30, 40, 55, 27, 70, 30};

static float sueldos[10]={19000,65000,163300,25000,50000,45000,11000,14040,45555,54000};

static eFecha fechas[10]={{10,6,2021}, {25,8,2019}, {25,12,2018}, {25,5,2020}, {25,5,2016}, {20,10,2020}, {13,11,2021}, {25,5,2020}, {12,3,2020}, {11,1,2017}};

static int idSectores[10]={101, 102, 103, 104, 101, 101, 104, 102, 102, 103};

static int sectoresId[5]={101, 102, 103, 104, 105};

static char descripcionSectores[5][30]={
            "Ventas",
            "RRHH",
            "Legales",
            "Sistemas",
            "Mantenimiento"
};

//static int legajoEmpleados[10]={2000,2000,2003,2004,2004,2006,2009,2008, 2007, 2004, 2005, 2006, 2008, 2009, 2004, 2005, 2006, 2004, 2000, 2002};

static int idComidas[5]={1000, 1001, 1002, 1003, 1004};

static float precioComidas[5]={100, 150, 120, 90, 80};

static char descripcionComidas[5][50]={
            "Milanesa",
            "Fideos",
            "Ensalada",
            "Pizza",
            "Sopa"
};

//static eFecha fechas2[20]={{10,6,2021}, {25,8,2019}, {25,12,2018}, {25,5,2020}, {25,5,2016}, {20,10,2020}, {13,11,2021}, {25,5,2020}, {12,3,2020}, {11,1,2017}, {13,11,2021}, {13,11,2021}, {13,11,2021}, {13,11,2021}, {13,11,2021}, {13,11,2021}, {13,11,2021}, {13,11,2021}, {13,11,2021}, {13,11,2021}};


int harcodearEmpleados(eEmpleado lista[], int tam, int cant, int* pLegajo)
{
    int cantidad = 0;

    if(lista!=NULL && tam>0 && cant>=0 && cant<=tam && pLegajo!=NULL)
    {

        for(int i=0; i<cant; i++)
        {
            lista[i].legajo=*pLegajo;
            (*pLegajo)++;
            strcpy(lista[i].nombre, nombres[i]);
            lista[i].sexo=sexos[i];
            lista[i].salario=sueldos[i];
            lista[i].sector=idSectores[i];
            lista[i].isEmpty=0;
            lista[i].fIngreso=fechas[i];
            cantidad++;
        }
    }
    return cantidad;
}



void harcodearComidas(eComida lista[], int len, int cantidad)
{

    if(lista!=NULL && len>0 && cantidad>=0 && cantidad<=len)
    {
        for(int i=0; i<cantidad; i++)
        {
            lista[i].id=idComidas[i];
            strcpy(lista[i].descripcion, descripcionComidas[i]);
            lista[i].precio=precioComidas[i];
            lista[i].isEmpty=0;
        }
    }
}

int harcodearSectores(eSector lista[], int len, int cant)
{
    int cantidad = 0;

    if(lista!=NULL && len>0 && cant>=0 && cant<=len)
    {

        for(int i=0; i<cant; i++)
        {
            lista[i].id=sectoresId[i];
            strcpy(lista[i].descripcion, descripcionSectores[i]);
            lista[i].isEmpty=0;
            cantidad++;
        }
    }
    return cantidad;
}
