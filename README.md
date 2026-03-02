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
    
🟢Forma de uso (1ra ejecución):
  
  > Ejecute primero el programa ./escribeMemCompartida.elf proporcionando como parametro de entrada una cadena de texto "Mensaje que desea compartir"
  > Ejecute luego el programa ./leeMemCompartida.elf

🚨2da. ejecución

  👉🏼 Luego pruebe editar el código en las secciones que estan comentadas para verificar los problemas de concurrencia de los cuales adolece este código de ejemplo.

  🟥Borre los ejecutables con el comando rm *.elf
  ♻️Recompile los programas con el comando make
  
  > Ejecute primero el programa ./destruyeMemCompartida.elf para liberar el bloque de memoria compartida
  > Ejecute ahora el programa ./leeMemCompartida.elf
  > Ejecute el programa ./escribeMemCompartida.elf "Algun mensaje" 
