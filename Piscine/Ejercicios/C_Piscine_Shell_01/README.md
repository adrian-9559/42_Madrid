# C_Piscine_Shell_01

## Introducción
En este módulo avanzarás en el shell scripting de Unix. Aprenderás a escribir scripts para imprimir grupos de usuario, buscar archivos, contar entradas en el directorio, obtener direcciones MAC, manejar nombres de archivo con caracteres especiales y procesar saltos de línea. Estos ejercicios automatizan tareas comunes del sistema.

## Instrucciones
- Esta página será la única referencia: no te fíes de los rumores.
- ¡Ten cuidado! Los enunciados pueden cambiar en cualquier momento.
- Los ejercicios han sido ordenados con mucha precisión, del más sencillo al más complejo. En ningún caso se tendrá en cuenta un ejercicio complejo si no se ha conseguido realizar perfectamente un ejercicio más sencillo.
- Asegúrate de que tus directorios y archivos tienen los permisos adecuados.
- Debes respetar el procedimiento de entrega para todos tus ejercicios.
- Tus compañeros de piscina se encargarán de corregir tus ejercicios.
- Además de por tus compañeros, también serán corregidos por un programa que se llama la Moulinette.
- La Moulinette es muy estricta a la hora de evaluar. Está completamente automatizada. Es imposible discutir con ella sobre tu nota. Por lo tanto, sé extremadamente riguroso para evitar cualquier sorpresa.
- Los ejercicios shell se deben ejecutar con /bin/sh.
- No puedes dejar en tu directorio ningún archivo que no se haya indicado de forma explícita en los enunciados de los ejercicios.
- ¿Tienes alguna pregunta? Pregunta a tu compañero de la derecha. Si no, prueba con tu compañero de la izquierda.
- Tu manual de referencia se llama Google / man / Internet / ...
- Lee detenidamente los ejemplos. Podrían exigir cosas que no se especifican necesariamente en los enunciados...

## Ejercicios

### [ex01: print_groups.sh](./ex01/print_groups.sh)
Escribe un script que muestre los grupos de un usuario.

### [ex02: find_sh.sh](./ex02/find_sh.sh)
Escribe un script que busque archivos .sh y muestre solo su nombre sin extensión.

### [ex03: count_files.sh](./ex03/count_files.sh)
Escribe un script que cuente el número de archivos y directorios.

### [ex04: MAC.sh](./ex04/MAC.sh)
Escribe un script que muestre las direcciones MAC de la máquina.

### [ex05: `"\?$*'MaRViN'*$?\"`](./ex05/)
Escribe un script que cree un archivo con un nombre literal que contiene caracteres especiales.

### [ex06: skip.sh](./ex06/skip.sh)
Escribe un script que muestre el output de ls -l saltando líneas pares.
