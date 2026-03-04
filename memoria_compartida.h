#ifndef MEMORIA_COMPARTIDA_H
#define MEMORIA_COMPARTIDA_H

#include <stdbool.h>

//Adjunta un bloque de memoria
//asociada con un nombre de archivo
//lo crea si no existe
char * adjunta_bloque_memoria(char *filename, int size);
bool desvincula_bloque_memoria(char * block);
bool destruye_bloque_memoria(char *filename);

//Todos los programas comparten estos 2 valores
#define BLOCK_SIZE 4096                 //Tamaño de bloque de memoria
#define FILENAME "memcompartida.sh"     //Archivo donde se comparte la memoria

#endif

