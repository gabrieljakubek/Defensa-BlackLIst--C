#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "fun.h"
#include "arrayList.h"
#include "BlackList.h"
#include "Destinatarios.h"

int parserBlackList(ArrayList* listaNegra, ArrayList* listaDestinatario, FILE* archivo)
{
    int auxRetorno = 0, flag = 1, i, j, auxResp, auxInt = 0, auxCompare = 0;
    char nombre[100], correo[1000];
    //eBlackList* bloqueado;
    if(listaNegra!=NULL && listaDestinatario!=NULL)
    {
        //auxLen = listaDestinatario->len(listaDestinatario);
        while (!feof(archivo))
        {
            /*bloqueado = newBloqueado();
            if(bloqueado!=NULL)
            {*/
            auxInt = 0;
            fscanf(archivo,"%[^,],%[^\n]\n",nombre,correo);
            for(i=0; i<listaDestinatario->len(listaDestinatario); i++)
            {
                auxResp = compareCorreo(correo,listaDestinatario->get(listaDestinatario,i));
                if(auxResp == 0)
                {
                    auxInt = 1;
                    break;
                }
            }
            for(j=0; j<listaNegra->len(listaNegra); j++)
            {
                if(compareCorreo(correo,listaNegra->get(listaNegra,j))==0)
                {
                    auxCompare = 1;
                    break;
                }
            }
            if(auxInt!=0 && auxCompare!=1)
            {
                listaNegra->add(listaNegra, listaDestinatario->get(listaDestinatario,i));
            }
            auxCompare = 0;
            /*}
            else
            {
                flag = 0;
                break;
            }*/
        }
    }
    else
    {
        flag = 0;
    }

    if(flag!=1)
    {
        auxRetorno = -1;
    }

    return auxRetorno;
}

eBlackList* newBloqueado()
{
    eBlackList* bloqueado = (eBlackList*)calloc(1,sizeof(eBlackList));

    return bloqueado;
}


void listarBloqueados(ArrayList* lista)
{
    int i;
    eBlackList* auxBlack;
    for ( i=0; i < lista->len(lista); i++)
    {
        auxBlack = lista->get(lista,i);
        listanegra_print(auxBlack);
    }
}

void listanegra_print(eBlackList* lista)
{
    printf("%s\t%s\n",lista->nombre,lista->direccion);
}
