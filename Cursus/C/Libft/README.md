# Introducción

Programar en C puede ser aburrido cuando uno no tiene acceso a las funciones comunes más utilizadas. Este proyecto te permitirá entender la forma en la que estas funciones funcionan, cómo implementarlas y aprender a utilizarlas. Crearás una librería propia, que será muy útil ya que la utilizarás en los siguientes proyectos de C.
Asegúrate de ir enriqueciendo tu libft a lo largo de tu cursus. Sin embargo, cuando utilices tu librería asegúrate de que todas las funciones utilizadas por tu librería respetan las permitidas por cada proyecto.

## Instrucciones generales

- Tu proyecto deberá estar escrito en C.
- Tu proyecto debe estar escrito siguiendo la Norma. Si tienes archivos o funciones adicionales, estas están incluidas en la verificación de la Norma y tendrás un 0 si hay algún error de norma en cualquiera de ellos.
- Tus funciones no deben terminar de forma inesperada (segfault, bus error, double free, etc) excepto en el caso de comportamientos indefinidos. Si esto sucede, tu proyecto será considerado no funcional y recibirás un 0 durante la evaluación.
- Toda la memoria asignada en el heap deberá liberarse adecuadamente cuando sea necesario. No se permitirán leaks de memoria.
- Si el enunciado lo requiere, deberás entregar un Makefile que compilará tus archivos fuente al output requerido con las flags -Wall, -Werror y -Wextra, utilizar cc y por supuesto tu Makefile no debe hacer relink.
- Tu Makefile debe contener al menos las normas $(NAME), all, clean, fclean y re.
- Para entregar los bonus de tu proyecto deberás incluir una regla bonus en tu Makefile, en la que añadirás todos los headers, librerías o funciones que estén prohibidas en la parte principal del proyecto. Los bonus deben estar en archivos distintos _bonus.{c/h}. La parte obligatoria y los bonus se evalúan por separado.
- Si tu proyecto permite el uso de la libft, deberás copiar su fuente y sus Makefile asociados en un directorio libft con su correspondiente Makefile. El Makefile de tu proyecto debe compilar primero la librería utilizando su Makefile, y después compilar el proyecto.
- Te recomendamos crear programas de prueba para tu proyecto, aunque este trabajo no será entregado ni evaluado. Te dará la oportunidad de verificar que tu programa funciona correctamente durante tu evaluación y la de otros compañeros. Y sí, tienes permitido utilizar estas pruebas durante tu evaluación o la de otros compañeros.
- Entrega tu trabajo en tu repositorio Git asignado. Solo el trabajo de tu repositorio Git será evaluado. Si Deepthought evalúa tu trabajo, lo hará después de tus compañeros. Si se encuentra un error durante la evaluación de Deepthought, esta habrá
terminado.

# Instrucciones de uso de la librería
## Instrucciones de ejecución

1. Ejecutar el comando "make"
```bash
make
```

2. Compilar el programa con la libreria creada
```bash
cc main.c libft.a
```

## Instrucciones de limpieza del directorio

- Eliminación de los archivos "*.o"
```bash
make clean
```

- Eliminación de los archivos creados con el "make"
```bash
make fclean
```

# READMES de cada función
|                   Funciones de Libc                              |
|------------------------------------------------------------------|
| Función         | Enlace al README                               |
|-----------------|------------------------------------------------|
| ft_isalpha      | [README](readmes_de_funciones/ft_isalpha.md)   |
| ft_isdigit      | [README](readmes_de_funciones/ft_isdigit.md)   |
| ft_isalnum      | [README](readmes_de_funciones/ft_isalnum.md)   |
| ft_isascii      | [README](readmes_de_funciones/ft_isascii.md)   |
| ft_isprint      | [README](readmes_de_funciones/ft_isprint.md)   |
| ft_strlen       | [README](readmes_de_funciones/ft_istrlen.md)   |
| ft_memset       | [README](readmes_de_funciones/ft_memset.md)    |
| ft_bzero        | [README](readmes_de_funciones/ft_bzero.md)     |
| ft_memcpy       | [README](readmes_de_funciones/ft_memcpy.md)    |
| ft_memmove      | [README](readmes_de_funciones/ft_memmove.md)   |
| ft_strlcpy      | [README](readmes_de_funciones/ft_strlcpy.md)   |
| ft_strlcat      | [README](readmes_de_funciones/ft_strlcat.md)   |
| ft_tolower      | [README](readmes_de_funciones/ft_tolower.md)   |
| ft_strchr       | [README](readmes_de_funciones/ft_strchr.md)    |
| ft_strrchr      | [README](readmes_de_funciones/ft_strrchr.md)   |
| ft_strncmp      | [README](readmes_de_funciones/ft_strncmp.md)   |
| ft_memchr       | [README](readmes_de_funciones/ft_memchr.md)    |
| ft_memcmp       | [README](readmes_de_funciones/ft_memcmp.md)    |
| ft_strnstr      | [README](readmes_de_funciones/ft_strnstr.md)   |
| ft_atoi         | [README](readmes_de_funciones/ft_atoi.md)      |
| ft_calloc       | [README](readmes_de_funciones/ft_calloc.md)    |
| ft_strdup       | [README](readmes_de_funciones/ft_strdup.md)    |

# Herramientas recomendadas
En esta sección encontrarás una lista de herramientas que te serán útiles durante el desarrollo de este proyecto. Estas herramientas están diseñadas para facilitar la depuración, la escritura de código y la gestión de tu proyecto.

## Lista de herramientas recomendadas

- **Valgrind**: Para detectar fugas de memoria y errores relacionados con la gestión de memoria.
- **Norminette**: Una herramienta para verificar que tu código cumple con la Norma de 42.
