#include "fecha.h"
#include "comida.h"
#include "empleado.h"


#ifndef ALMUERZO_H_INCLUDED
#define ALMUERZO_H_INCLUDED

typedef struct{
    int id;
    int idComida;
    int legEmpleado;
    eFecha fecha;
    int isEmpty;


}eAlmuerzo;

#endif // ALMUERZO_H_INCLUDED

void inicializarAlmuerzo (eAlmuerzo listaAlmuerzo[], int tamAlmuerzo);

int altaAlmuerzo(eAlmuerzo listaAlmuerzo[], int tamAlmuerzo, eComida listaComida[], int tamComida, eEmpleado listaEmpleado[], int tamEmpleado, eSector listaSector[], int tamSector, int* pNextId);

int mostrarAlmuerzos(eAlmuerzo listaAlmuerzo[], int tamAlmuerzo, eComida listaComida[], int tamComida, eEmpleado listaEmpleado[], int tamEmpleado);
int mostrarAlmuerzo(eAlmuerzo listaAlmuerzo[], int tamAlmuerzo, eComida listaComida[], int tamComida, eEmpleado listaEmpleado[], int tamEmpleado, int indice);

int buscarLibreAlmuerzo(eAlmuerzo listaAlmuerzo[], int len);
