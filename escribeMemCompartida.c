#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "memoria_compartida.h"

// Contador para mostrar error concurrencia
 #define ITERACIONES 10

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Forma de uso - %s \"lo que desea escribir\"", argv[0]);
        return -1;
    }

    //grab the shared memory block
    char *block = adjunta_bloque_memoria(FILENAME, BLOCK_SIZE);
    if(block == NULL) {
        printf("Error: No se pudo obtener un bloque\n");
        return -1;
    }
   
    //Comentar siguientes dos líneas para mostrar error concurrencia
    printf("Escribiendo: \"%s\"\n", argv[1]);
    strncpy(block, argv[1], BLOCK_SIZE);

    //Descomentar error concurrencia
    /*
    for (int i=0; i<ITERACIONES; i++) {
        printf("Escribiendo: \"%s\"\n", argv[1]);
        strncpy(block, argv[1], BLOCK_SIZE);
    }
    */
    //Fin descomentar error concurrencia

    desvincula_bloque_memoria(block);

    return 0;
}
