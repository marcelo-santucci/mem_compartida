# Programas de Memoria Compartida

Ejemplo de procesos independientes que comparten memoria para comunicarse entre ellos.

Esta compuesto de los siguientes archivos: 

📚Librerías compartidas:
  📘 memoria_compartida.h

📁Archivos de código:
  📗 destruyeMemCompartida.c
  📗 escribeMemCompartida.c
  📗 leeMemCompartida.c
  📗 memoria_compartida.c

📭Area de memoria compartida
  📝 memcompartida.sh
  
⛏️Makefile
    👉🏼 Los archivos elf deben ser borrados a mano previo a compilar con el comando make
    
🟢Forma de uso:
  
  > Ejecute primero el programa ./escribeMemCompartida.elf proporcionando como parametro de entrada una cadena de texto "Mensaje que desea compartir"
  > Ejecute luego el programa ./leeMemCompartida.elf
