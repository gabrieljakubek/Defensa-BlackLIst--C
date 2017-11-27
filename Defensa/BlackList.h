#include "arrayList.h"

typedef struct
{
    char* nombre;
    char* direccion;
}eBlackList;

int parserBlackList(ArrayList* listaNegra, ArrayList* listaDestinatario, FILE* archivo);

eBlackList* newBloqueado();

void listarBloqueados(ArrayList* lista);

void listanegra_print(eBlackList* lista);
