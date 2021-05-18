#include "sectores.h"
#include "fecha.h"

#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED


typedef struct{
    int legajo;
    char nombre[51];
    char sexo;
    float salario;
    int sector;
    eFecha fIngreso;
    int isEmpty;
}eEmpleado;

#endif // EMPLEADO_H_INCLUDED

void inicializar (eEmpleado lista[], int tam);
int buscarEmpleado(eEmpleado lista[], int len,int legajo);

int altaEmpleado(eEmpleado lista[], int len,int* pLegajo, eSector listaSector[], int lenSector);
int buscarLibre(eEmpleado lista[], int len);

int modificarEmpleados(eEmpleado lista[], int len, eSector listaSector[], int lenSector);
int modificarEmpleado(eEmpleado lista[], int len, eSector listaSector[], int lenSector, int opcion, int indice);

int mostarEmpleados(eEmpleado lista[], int len, eSector listaSector[], int lenSector);
int mostarEmpleado(eEmpleado lista[], int indice, eSector listaSector[],int lenSector);
int mostarEmpleadosDeUnSector(eEmpleado lista[], int len, eSector listaSector[], int lenSector);
int mostrarEmpleadosTodosSectores(eEmpleado lista[], int len, eSector listaSector[], int lenSector);

int cargarDescripcionSector(eSector listaSectores[], int tamSector, int idSector, char descripcionCargar[]);

int cargarNombreEmpleado(int legajo, eEmpleado listaEmpleado[], int tamEmpleado, char descripcionCargar[]);

int bajaEmpleado (eEmpleado lista[], int len,eSector listaSector[], int lenSector);


int totalSueldosSector(eEmpleado lista[], int len,eSector listaSector[], int lenSector);
int totalADepositar(eEmpleado lista[], int len,eSector listaSector[], int lenSector);
int sectorMayorSueldo(eEmpleado lista[], int len,eSector listaSector[], int lenSector);





