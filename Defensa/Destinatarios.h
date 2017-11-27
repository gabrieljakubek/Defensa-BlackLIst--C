#include "arrayList.h"
typedef struct
{
    char* nombre;
    char* direccion;
}eDestinatario;

int parserDestinatario(ArrayList* lista, FILE* archivo);

eDestinatario* newDestinatario();

void setNombre(eDestinatario* destinatario, char nombre[]);

void setDireccion(eDestinatario* destinatario, char correo[]);

char* getCorreoDestinatario(eDestinatario* destinatario);

int compareCorreo(char correo[], eDestinatario* destinatario);

void listarDestinatarios(ArrayList* lista);

void destinatario_print(eDestinatario* lista);
