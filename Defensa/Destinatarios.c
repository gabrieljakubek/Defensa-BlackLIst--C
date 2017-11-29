#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "fun.h"
#include "arrayList.h"
#include "Destinatarios.h"

int parserDestinatario(ArrayList* lista, FILE* archivo)
{
    int auxRetorno = 0, flag = 1,i, auxRespuesta = 0;
    char nombre[100], correo[1000];
    eDestinatario* destinatario;
    if(lista!=NULL)
    {
        while (!feof(archivo))
        {
            destinatario = newDestinatario();
            if(destinatario!=NULL)
            {
                fscanf(archivo,"%[^,],%[^\n]\n",nombre,correo);
                setNombre(destinatario,nombre);
                setDireccion(destinatario,correo);
                for(i=0; i<lista->len(lista); i++)
                {
                    if(compareCorreo(correo,lista->get(lista,i))==0)
                    {
                        auxRespuesta = 1;
                        break;
                    }
                }
                if(auxRespuesta!=1)
                {
                    lista->add(lista, destinatario);
                }
                auxRespuesta = 0;
            }
            else
            {
                flag = 0;
                break;
            }
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

eDestinatario* newDestinatario()
{
    eDestinatario* returnAux = (eDestinatario*) calloc(1,sizeof(eDestinatario));

    return returnAux;
}

void setNombre(eDestinatario* destinatario, char nombre[])
{
    destinatario->nombre = charDyn(nombre);
}

void setDireccion(eDestinatario* destinatario, char correo[])
{
    destinatario->direccion = charDyn(correo);
}

char* getCorreoDestinatario(eDestinatario* destinatario)
{
    return destinatario->direccion;
}

int compareCorreo(char correo[], eDestinatario* destinatario)
{
    int respuesta = 2;
    char buffer[1000];
    if(destinatario!=NULL)
    {
        strcpy(buffer,getCorreoDestinatario(destinatario));
        respuesta = strcmp(correo,buffer);
    }
    return respuesta;
}


void listarDestinatarios(ArrayList* lista)
{
    int i;
    eDestinatario* auxDest;
    for ( i=0; i < lista->len(lista); i++)
    {
        auxDest = lista->get(lista,i);
        destinatario_print(auxDest);
    }
}

void destinatario_print(eDestinatario* lista)
{
    printf("%s\t%s\n",lista->nombre,lista->direccion);
}
