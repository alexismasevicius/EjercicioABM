#ifndef COMIDA_H_INCLUDED
#define COMIDA_H_INCLUDED

typedef struct{
    int id;
    char descripcion[50];
    float precio;
    int isEmpty;

}eComida;

#endif // COMIDA_H_INCLUDED



int mostrarComidas(eComida lista[], int lenC);
int mostrarComida(eComida lista[], int indice);
int cargarDescripcionComida(eComida listacomidas[], int tamCom, int idCom, char descripcionCargar[]);
