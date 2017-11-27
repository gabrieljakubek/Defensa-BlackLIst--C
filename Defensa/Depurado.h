#include "arrayList.h"

typedef struct
{
    char* nombre;
    char* direccion;
}eDepurado;


int depurar(ArrayList* listaDestinatarios, ArrayList* listaNegra, ArrayList* listaDepurada);

eDepurado* newDepurado();

void listarDepurados(ArrayList* lista);

void listaDepurado(eDepurado* depurado);
