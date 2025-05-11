# Introducción

El proyecto `get_next_line` es un ejercicio fundamental en el currículo de 42 que te desafía a implementar una función capaz de leer una línea completa desde un descriptor de archivo, incluso si esta línea está dividida en múltiples lecturas. 📜 Este proyecto te permitirá profundizar en el manejo de archivos, la gestión de memoria dinámica y la manipulación de buffers en C. 🛠️

A través de este ejercicio, aprenderás a trabajar con conceptos clave como el almacenamiento en búfer, la reutilización de datos no procesados y la optimización de recursos. 🚀 Además, `get_next_line` es una excelente oportunidad para mejorar tus habilidades en la gestión de memoria y en la escritura de código modular y eficiente. 🧠

Este proyecto es de dificultad moderada y te preparará para enfrentar desafíos más complejos en el futuro. 🔑 La clave del éxito radica en diseñar un código limpio, extensible y conforme a la Norma de 42. 🧹 ¡Prepárate para explorar el fascinante mundo de la lectura de archivos y llevar tus habilidades de programación al siguiente nivel! 💻✨

## Instrucciones generales

- Tu proyecto deberá estar escrito en C.
- Tu proyecto debe estar escrito siguiendo la Norma. Si tienes archivos o funciones adicionales, estas están incluidas en la verificación de la Norma y tendrás un 0 si hay algún error de norma en cualquiera de ellos.
- Tus funciones no deben terminar de forma inesperada (segfault, bus error, double free, etc.) excepto en el caso de comportamientos indefinidos. Si esto sucede, tu proyecto será considerado no funcional y recibirá un 0 durante la evaluación.
- Toda la memoria asignada en el heap deberá liberarse adecuadamente cuando sea necesario. No se permitirán fugas de memoria.
- Si el enunciado lo requiere, deberás entregar un Makefile que compilará tus archivos fuente al output requerido con las flags `-Wall`, `-Werror` y `-Wextra`, utilizar `cc` y, por supuesto, tu Makefile no debe hacer relink.
- Tu Makefile debe contener al menos las normas `$(NAME)`, `all`, `clean`, `fclean` y `re`.
- Para entregar los bonus de tu proyecto deberás incluir una regla `bonus` en tu Makefile, en la que añadirás todos los headers, librerías o funciones que estén prohibidas en la parte principal del proyecto. Los bonus deben estar en archivos distintos `_bonus.{c/h}`. La parte obligatoria y los bonus se evalúan por separado.
- Te recomendamos crear programas de prueba para tu proyecto, aunque este trabajo no será entregado ni evaluado. Te dará la oportunidad de verificar que tu programa funciona correctamente durante tu evaluación y la de otros compañeros. Y sí, tienes permitido utilizar estas pruebas durante tu evaluación o la de otros compañeros.
- Entrega tu trabajo en tu repositorio Git asignado. Solo el trabajo de tu repositorio Git será evaluado. Si Deepthought evalúa tu trabajo, lo hará después de tus compañeros. Si se encuentra un error durante la evaluación de Deepthought, esta habrá terminado.

# Enunciado original

[Enunciado en Español](es.subject.pdf)

# Instrucciones de uso de la librería

## Instrucciones de ejecución

1. Compilar el programa con la librería creada:
    ```bash
    cc main.c get_next_line.a
    ```

2. Ejecutar el programa:
    ```bash
    ./a.out
    ```

# Funcionalidades implementadas

La función `get_next_line` permite leer una línea completa desde un descriptor de archivo, soportando las siguientes características:

| Característica                    | Descripción                                                                 |
|-----------------------------------|-----------------------------------------------------------------------------|
| Lectura por bloques               | Utiliza un búfer para leer datos en bloques definidos por `BUFFER_SIZE`.    |
| Manejo de múltiples descriptores  | Soporta la lectura simultánea desde múltiples descriptores de archivo.      |
| Gestión de memoria eficiente      | Garantiza que no haya fugas de memoria durante la ejecución.                |

# Funciones utilizadas

| Función           | Descripción                                                                 | Enlace al README de la función                     |
|-------------------|-----------------------------------------------------------------------------|---------------------------------------------------|
| `get_next_line`   | Función principal que gestiona la lectura de líneas desde un descriptor.    | [README](./readmes_de_funciones/ft_get_next_line.md) |
| `ft_read_to_reminder`      |  Función auxiliar utilizada para leer datos desde un descriptor de archivo y almacenarlos en un recordatorio                 | [README](./readmes_de_funciones/ft_read_to_reminder.md)    |
| `ft_extract_line`       | Función auxiliar diseñada para extraer una línea completa desde un recordatorio.                       | [README](./readmes_de_funciones/ft_extract_line.md)     |

# Herramientas recomendadas

En esta sección encontrarás una lista de herramientas que te serán útiles durante el desarrollo de este proyecto. Estas herramientas están diseñadas para facilitar la depuración, la escritura de código y la gestión de tu proyecto.

## Lista de herramientas recomendadas

- **Valgrind**: Para detectar fugas de memoria y errores relacionados con la gestión de memoria.
- **Norminette**: Una herramienta para verificar que tu código cumple con la Norma de 42.
- **GNL Tester**: Herramientas externas para probar la funcionalidad de tu `get_next_line`.  