#include <stdio.h>
#include <stdlib.h>
#include "fun.h"
#include "arrayList.h"
#include "General.h"
//#include "Destinatarios.h"
//#include "BlackList.h"
#include "Depurado.h"

int main()
{
    system("mode con: cols=120 lines=30");
    system("color 2");
    int opcion;
    int auxInt;
    char seguir = 's';

    ArrayList* listaDestinatario;
    ArrayList* listaBlack;
    ArrayList* listaDepurada;

    listaDestinatario = al_newArrayList();
    listaBlack = al_newArrayList();
    listaDepurada = al_newArrayList();

    if(listaDestinatario!=NULL && (listaBlack!=NULL) && listaDepurada!=NULL)
    {
        do
        {
            opcion=mostrarMenu("1- Carga Destinatarios\
                              \n2- Carga Lista Negra\
                              \n3- Depurar\
                              \n4- Listar\
                              \n5- Salir");
            switch(opcion)
            {
            case 1:
                auxInt = cargarDestinatarios(listaDestinatario);
                if(auxInt != -1)
                {
                    printf("Se logro cargar la lista de destinatarios!!\n");
                    //listarDestinatarios(listaDestinatario);
                    printf("----%d----",listaDestinatario->len(listaDestinatario));
                }
                else
                {
                    printf("\nError no se pudo cargar los destinatarios o direccion erronea!!\n");
                }
                borrarPantalla();
                break;

            case 2:
                auxInt = cargarBlackList(listaBlack,listaDestinatario);
                if(auxInt != -1)
                {
                    printf("Se logro cargar la lista negra!!\n");
                    //listarBloqueados(listaBlack);
                    printf("----%d----",listaBlack->len(listaBlack));
                }
                else
                {
                    printf("\nError no se pudo dar de alta Producto o ID ya existente!!\n");
                }
                borrarPantalla();
                break;

            case 3:
               if(listaDestinatario->isEmpty(listaDestinatario) == 1 && (listaBlack->isEmpty(listaBlack) == 1))
                {
                    printf("\nNo hay datos cargados como para realizar la accion!!!");
                }
                else
                {
                    auxInt = generarListaDepurada(listaDestinatario, listaBlack, listaDepurada);
                    if(auxInt==0)
                    {
                        printf("\nSe logro depurar!!\n");
                        printf("----%d----",listaDepurada->len(listaDepurada));
                    }
                    else if(auxInt==1)
                    {
                        printf("\nNo existen nuevos correos a depurar!!\n");
                    }
                    else
                    {
                        printf("\nError no se logro depurar!!\n");
                    }
                }
                borrarPantalla();
                break;

            case 4:
                if(listaDepurada->isEmpty(listaDepurada) == 1)
                {
                    printf("\nNo hay datos cargados como para realizar la accion!!!");
                }
                else
                {
                    listarDepurados(listaDepurada);
                }
                borrarPantalla();
                break;

            case 5:
                seguir = 'n';
                printf("\nChau Chau!!!!!");
                break;

            default:
                printf("\nOpcion inexistente!!!\n");
                borrarPantalla();
                break;
            }
        }
        while(seguir != 'n');
    }
    return 0;
}
