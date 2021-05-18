#ifndef SECTORES_H_INCLUDED
#define SECTORES_H_INCLUDED

typedef struct{
    int id;
    char descripcion[50];
    int isEmpty;

}eSector;

#endif // SECTORES_H_INCLUDED



int mostarSectores(eSector listaSector[], int lenSector);
int mostarSector(eSector listaSector[], int indice);
