#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "empleado.h"
#include "menu.h"
#include "sectores.h"
#include "comida.h"
#include "almuerzo.h"
#include "datawarehouse.h"
#define TAM 10
#define TAMC 5
#define TAMA 10


int main()
{
    int opcion;
    int opcionSecundaria;
    eEmpleado nomina[TAM];
    eSector listaSectores[5];
    eComida listaComida[TAMC];
    eAlmuerzo listaAlmuerzo[TAMA];

    int legajo = 2000;
    int idAlmuerzoPuntero = 100;
    inicializar(nomina,TAM);
    inicializarAlmuerzo(listaAlmuerzo,TAMA);
    harcodearEmpleados(nomina,TAM,10,&legajo);
    harcodearSectores(listaSectores, 5, 5);
    harcodearComidas(listaComida,TAMC,5);

    do{

        printf("\n");

        menuPrincipal();
        utn_getNumero(&opcion,"Ingrese una opcion: \n", "Error. Ingrese una opcion valida.\n",1,8,100);

        switch(opcion)
        {
            case 1:
                menuAlta();
                utn_getNumero(&opcionSecundaria,"Ingrese una opcion: \n", "Error. Ingrese una opcion valida.\n",1,4,100);
                switch(opcionSecundaria)
                {
                    case 1:
                        if(altaEmpleado(nomina,TAM,&legajo,listaSectores,5)==1)
                        {

                            printf("\nAlta completa.\n");
                        }
                        else
                        {
                            printf("\nNo se pudo realizar la carga del empleado.\n");
                        }
                        break;

                    case 2:
                        if(altaAlmuerzo(listaAlmuerzo,TAMA, listaComida,TAMC,nomina,TAM,listaSectores,5,&idAlmuerzoPuntero))
                        {
                              printf("\nAlta completa.\n");
                        }
                        else
                        {
                            printf("\nNo se pudo realizar la carga del almuerzo.\n");
                        }
                }

                break;
            case 2:
                    if(bajaEmpleado(nomina,TAM,listaSectores,5))
                    {
                        printf("\nBaja exitosa.\n");
                    }
                    else
                    {
                        printf("\nNo se pudo completar la baja.\n");
                    }

                break;
            case 3:
                    if(modificarEmpleados(nomina,TAM,listaSectores,5)==1)
                    {
                        printf("\nModificacion exitosa.\n");
                    }
                    else
                    {
                        printf("\nNo se pudo completar la modificacion.\n");
                    }
                    break;
            case 4:
                menuListar();
                utn_getNumero(&opcionSecundaria,"Ingrese una opcion: \n", "Error. Ingrese una opcion valida.\n",1,10,100);
                switch(opcionSecundaria)
                {
                    case 1:
                        if(mostarEmpleados(nomina,TAM,listaSectores,5)==0)
                        {
                            printf("\nNo hay empleados cargados.\n");
                        }
                        break;
                    case 2:
                        if(mostarSectores(listaSectores,5)==0)
                        {
                            printf("\nNo hay sectores cargados.\n");
                        }
                        break;
                    case 3:
                        if(mostarEmpleadosDeUnSector(nomina,TAM,listaSectores,5)==0)
                        {
                            printf("\nError. No hay empleados en el sector pedido\n");
                        }
                        break;
                    case 4:
                        mostrarEmpleadosTodosSectores(nomina,TAM,listaSectores,5);
                        break;
                    case 5:
                        if(mostrarComidas(listaComida,TAMC)==0)
                        {
                            printf("\nNo hay comidas cargadas.\n");
                        }
                        break;
                    case 6:
                        if(mostrarAlmuerzos(listaAlmuerzo,TAMA,listaComida,TAMC,nomina,TAM)==0)
                        {
                            printf("\nNo hay comidas cargadas.\n");
                        }
                        break;
                }

                break;
            case 5:

                menuInformar();
                utn_getNumero(&opcionSecundaria,"Ingrese una opcion: \n", "Error. Ingrese una opcion valida.\n",1,4,100);
                switch(opcionSecundaria)
                {
                    case 1:
                        totalSueldosSector(nomina,TAM,listaSectores,5);
                        break;
                    case 2:
                        totalADepositar(nomina,TAM,listaSectores,5);
                        break;
                    case 3:
                        sectorMayorSueldo(nomina,TAM,listaSectores,5);
                        break;
                    case 4:

                        break;
                }

                break;
            case 6:

                break;
            case 7:
                break;
            case 8:
                break;
        }


    }while(opcion!=8);

    return 0;
}
