#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "fun.h"
#include "arrayList.h"
#include "Destinatarios.h"
#include "BlackList.h"
#include "Depurado.h"

int cargarDestinatarios(ArrayList* lista)
{
    int auxResp = 0;
    FILE* archivo;
    char buffer [10000];
    printf("\nIngrese la direccion de archivo destinatario:");
    fflush(stdin);
    gets(buffer);
    archivo=fopen(buffer,"r");
    if(archivo!=NULL)
    {
        auxResp= parserDestinatario(lista,archivo);
        fclose(archivo);
    }
    else
    {
        auxResp =-1;
    }
    return auxResp;
}

int cargarBlackList(ArrayList* listaNegra, ArrayList* listaDestinatario)
{
    int auxResp = 0;
    FILE* archivo;
    char buffer [10000];
    printf("\nIngrese la direccion de archivo BlackList:");
    fflush(stdin);
    gets(buffer);
    archivo=fopen(buffer,"r");
    if(archivo!=NULL && listaDestinatario!=NULL)
    {
        auxResp= parserBlackList(listaNegra,listaDestinatario,archivo);
        fclose(archivo);
    }
    else
    {
        auxResp =-1;
    }
    return auxResp;
}

int generarListaDepurada(ArrayList* listaDestinatario,ArrayList* listaNegra,ArrayList* listaDepurada)
{
    int retorno;
    retorno = depurar(listaDestinatario,listaNegra,listaDepurada);
    return retorno;
}
