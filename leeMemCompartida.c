#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/sem.h>

#include "memoria_compartida.h"

int main(int argc, char *argv[])
{
    if (argc != 1) {
        printf("Forma de uso - %s //sin argumentos", argv[0]);
        return -1;
    }

    //grab the shared memory block
    char *block = adjunta_bloque_memoria(FILENAME, BLOCK_SIZE);
    if(block == NULL) {
        printf("Error: No se pudo obtener un bloque\n");
        return -1;
    }

    //Comentar siguiente línea para mostrar error concurrencia 
    printf("Leyendo: \"%s\"\n", block);

    //Des comentar siguientes bloque comentado para mostrar error concurrencia
    /*
    while (true) {

        if (strlen(block) > 0) {
            printf("Leyendo: \"%s\"\n", block);
            bool done = (strcmp(block, "quit")==0);
            block[0]=0;
            if(done) { break; }
        }

    }
    */
    //Fin comentar siguientes bloque comentado para mostrar error concurrencia

    desvincula_bloque_memoria(block);

    return 0;
}

