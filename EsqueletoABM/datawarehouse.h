
#include "empleado.h"
#include "sectores.h"
#include "comida.h"

#ifndef DATAWAREHOUSE_H_INCLUDED
#define DATAWAREHOUSE_H_INCLUDED

void harcodearComidas(eComida lista[], int len, int cantidad);

int harcodearEmpleados(eEmpleado lista[], int tam, int cant, int* pLegajo);

int harcodearSectores(eSector lista[], int len, int cant);

#endif // DATAWAREHOUSE_H_INCLUDED
