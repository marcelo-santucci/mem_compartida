# Programas de Memoria Compartida

Ejemplo de procesos independientes que comparten memoria para comunicarse entre ellos.

Esta compuesto de los siguientes archivos: 

📚Librerías compartidas: <br>
  📘 memoria_compartida.h <br>

📁Archivos de código: <br>
  📗 destruyeMemCompartida.c <br>
  📗 escribeMemCompartida.c <br>
  📗 leeMemCompartida.c <br>
  📗 memoria_compartida.c <br>

📭Area de memoria compartida <br>
  📝 memcompartida.sh <br>
  
⛏️Makefile <br>
    👉🏼 Los archivos elf deben ser borrados a mano previo a compilar con el comando make <br>
    
🟢Forma de uso (1ra ejecución):<br>
  
  > Ejecute primero el programa ./escribeMemCompartida.elf proporcionando como parametro de entrada una cadena de texto "Mensaje que desea compartir" <br>
  > Ejecute luego el programa ./leeMemCompartida.elf <br>

🚨2da. ejecución <br>

  👉🏼 Luego pruebe editar el código en las secciones que estan comentadas para verificar los problemas de concurrencia de los cuales adolece este código de ejemplo. <br>
    

  🟥Borre los ejecutables con el comando rm *.elf <br>
  ♻️Recompile los programas con el comando make <br>
  
  > Ejecute primero el programa ./destruyeMemCompartida.elf para liberar el bloque de memoria compartida <br>
  > Abra una nueva ventana de comando y ejecute en ella el programa ./leeMemCompartida.elf <br>
  > Abra otra ventana adicional de comando y ejecute en ella el programa ./escribeMemCompartida.elf "Algun mensaje" <br>

  ❓¿Que cosa observa que pasa con los mensajes?, ¿cuantos son escritos? y ¿cuantos son desplegados?

  3ra. ejecución <br>
    👉🏼 Detenga únicamente el programa que escribe mensajes con "Ctrl+C"
    
  > Ahora en la ventana del programa que escribe ejecutelo nuevamente pero multiples veces con el siguiente comando: <br>

 ./escribeMemCompartida.elf "Uno" & ./escribeMemCompartida.elf "Dos" & ./escribeMemCompartida.elf "Tres" & ./escribeMemCompartida.elf "Cuatro" & ./escribeMemCompartida.elf "Cinco" <br>

👁️Si esta en Mac Os agregue un ";" luego del "&" <br>

 ❓¿Vario ahora el comportamiento de los mensajes?, ¿cuantos son escritos? y ¿cuantos son desplegados? <br>


 
  
