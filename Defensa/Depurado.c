#include <stdio.h>
#include <stdlib.h>
#include "fun.h"
#include "arrayList.h"
#include "General.h"
#include "Destinatarios.h"
#include "BlackList.h"
#include "Depurado.h"

int depurar(ArrayList* listaDestinatarios, ArrayList* listaNegra, ArrayList* listaDepurada)
{
    int retorno = -1, auxResp, i, auxRemove = 0;
    //eDepurado* depurado;
    if(listaDepurada!=NULL && (listaDestinatarios!=NULL) && listaNegra!=NULL)
    {
        /*if(listaDepurada->isEmpty(listaDepurada)==0)
        {
            for(i=0; i<listaDepurada->len(listaDepurada); i++)
            {
                auxResp = al_contains(listaNegra,listaDepurada->get(listaDepurada,i));
                if(auxResp==1)
                {
                    listaDepurada->remove(listaDepurada,i);
                    auxRemove = 1;
                }
            }
        }*/
        if(listaDepurada->isEmpty(listaDepurada)==0)
        {
            listaDepurada->clear(listaDepurada);
        }
        for(i=0; i<listaDestinatarios->len(listaDestinatarios); i++)
        {
            auxResp = al_contains(listaNegra,listaDestinatarios->get(listaDestinatarios,i));
            if(auxResp==0)
            {
                auxResp = al_contains(listaDepurada,listaDestinatarios->get(listaDestinatarios,i));
                if(auxResp==0)
                {
                    listaDepurada->add(listaDepurada,listaDestinatarios->get(listaDestinatarios,i));
                    retorno = 0;
                }
                else
                {
                    retorno = 1;
                }
                //depurado = newDepurado();
            }
        }
        if(retorno==1 && auxRemove==1)
        {
            retorno = 0;
        }
    }
    return retorno;
}

eDepurado* newDepurado()
{
    eDepurado* depurado = (eDepurado*)calloc(1,sizeof(eDepurado));

    return depurado;
}

void listarDepurados(ArrayList* lista)
{
    int i;
    //eDepurado* auxDepur;
    printf("\n%s\t%s\n","Nombre","Direccion");
    for ( i=0; i < lista->len(lista); i++)
    {
        //auxDepur = lista->get(lista,i);
        listaDepurado(lista->get(lista,i));
    }
}

void listaDepurado(eDepurado* depurado)
{
    printf("%s\t%s\n",depurado->nombre,depurado->direccion);
}
