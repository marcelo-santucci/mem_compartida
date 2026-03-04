#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include "memoria_compartida.h"

#define IPC_RESULT_ERROR (-1)

// Función que obtiene un bloque compartido de memoria
static int obtiene_bloque_memoria(char *filename, int size) {
    key_t key;

    // Solicitar una llave que este relacionada con el archivo
    // que se empleara para compartir la memoria
    key = ftok(filename, 0);
    if(key == IPC_RESULT_ERROR) {
        return IPC_RESULT_ERROR;
    }

    /* 
    Obtener un puntero hacia el bloque compartido, creandolo si no existe 
    y hace uso de la variable key para poder obtener acceso al bloque
        
        4 = lectura (r)
        2 = escritura (w)
        1 = ejecución (x)

        se debe anteponer un 0 para que el compilador de C lo
        entienda como un valor Octal
    */
    return shmget(key, size, 0644 | IPC_CREAT);
}

// Función que permite obtener un puntero con el cual se pueda acceder 
// al bloque de memoria compartida
char * adjunta_bloque_memoria(char *filename, int size) {
    int shared_block_id = obtiene_bloque_memoria(filename, size);
    char *result;

    if(shared_block_id == IPC_RESULT_ERROR){
        return NULL;
    }

    // Mapear el bloque compartido a la memoria del proceso
    // y devolver un puntero hacia él
    result = shmat(shared_block_id, NULL, 0);
    if(result == (char *)IPC_RESULT_ERROR) {
        return NULL;
    }

    return result;
}

// Función que desvincula un puntero de un bloque de memoria
bool desvincula_bloque_memoria(char *block) {
    return (shmdt(block) != IPC_RESULT_ERROR);
}

// Función que destruye un bloque de memoria
bool destruye_bloque_memoria (char *filename) {
    int shared_block_id = obtiene_bloque_memoria(filename, 0);

    if (shared_block_id == IPC_RESULT_ERROR) {
        return NULL;
    }

    // IPC_RMID significa Remove Messageblock ID
    return (shmctl(shared_block_id, IPC_RMID, NULL) != IPC_RESULT_ERROR);
}