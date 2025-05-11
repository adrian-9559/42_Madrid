# Introducción
La función `printf()` es una de las herramientas más poderosas y versátiles del lenguaje C. 🌟 Este proyecto te brinda la oportunidad de profundizar en su funcionamiento interno, desafiándote a implementar tu propia versión: `ft_printf`. 🛠️ A través de este ejercicio, no solo mejorarás tus habilidades de programación, sino que también aprenderás a trabajar con funciones variádicas, un concepto clave en C que permite manejar un número variable de argumentos. 📚

El desarrollo de `ft_printf` requiere un enfoque estructurado y modular, ya que deberás gestionar múltiples conversiones de formato y garantizar un comportamiento robusto y eficiente. 🚀 Este proyecto es una excelente manera de consolidar tus conocimientos sobre la gestión de memoria, el manejo de cadenas y la manipulación de datos en bajo nivel. 🧠

Además, `ft_printf` es un ejercicio de dificultad moderada que te preparará para enfrentar desafíos más complejos en el futuro. 🔑 La clave para el éxito radica en diseñar un código limpio, extensible y conforme a la Norma de 42. 🧹 ¡Prepárate para explorar el fascinante mundo de las funciones variádicas y llevar tus habilidades de programación al siguiente nivel! 💻✨

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
- Entrega tu trabajo en tu repositorio Git asignado. Solo el trabajo de tu repositorio Git será evaluado. Si Deepthought evalúa tu trabajo, lo hará después de tus compañeros. Si se encuentra un error durante la evaluación de Deepthought, esta habrá terminado.

# Enunciado original
[Enunciado en Español](es.subject.pdf)

# Instrucciones de uso de la librería
## Instrucciones de ejecución

1. Ejecutar el comando "make"
```bash
make
```

2. Compilar el programa con la librería creada
```bash
cc main.c libftprintf.a
```

3. Ejecutar el programa
```bash
./a.out
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

# Funcionalidades implementadas

La librería `ft_printf` soporta las siguientes conversiones de formato:

| Conversión | Descripción                          			|
|------------|--------------------------------------------------|
| `%c`       | Imprime un carácter.                				|
| `%s`       | Imprime una cadena de caracteres.   				|
| `%p`       | Imprime un puntero en formato hexadecimal. 		|
| `%d`       | Imprime un número entero decimal (base 10). 		|
| `%i`       | Imprime un número entero (base 10). 				|
| `%u`       | Imprime un número entero sin signo (base 10). 	|
| `%x`       | Imprime un número hexadecimal en minúsculas. 	|
| `%X`       | Imprime un número hexadecimal en mayúsculas. 	|
| `%%`       | Imprime un símbolo de porcentaje.   				|

# Funciones utilizadas
| Función         		| Descripción                                                          	 | Enlace al README de la función		                    	|
|-----------------------|------------------------------------------------------------------------|--------------------------------------------------------------|
| `ft_printf`     		| Función principal que gestiona las conversiones y formatea la salida.  | [README](./readmes_de_funciones/ft_printf.md)      				|
| `ft_putchar`    		| Imprime un carácter en la salida estándar.                             | [README](./readmes_de_funciones/ft_putchar.md)    				|
| `ft_putstr`     		| Imprime una cadena de caracteres en la salida estándar.                | [README](./readmes_de_funciones/ft_putstr.md)      				|
| `ft_putnbr`     		| Imprime un número entero en la salida estándar.                        | [README](./readmes_de_funciones/ft_putnbr.md)      				|
| `ft_putnbr_unsigned`  | Imprime un número entero sin signo en la salida estándar.              | [README](./readmes_de_funciones/ft_putnbr_unsigned.md) |
| `ft_putnbr_base`      | Imprime un número en formato hexadecimal (minúsculas o mayúsculas).    | [README](./readmes_de_funciones/ft_putnbr_base.md) 		|
| `ft_putptr`     		| Imprime un puntero en formato hexadecimal.                             | [README](./readmes_de_funciones/ft_putptr.md)      				|
| `ft_handle_format`    | Gestiona el formato de las conversiones y delega a las funciones correspondientes. | [README](./readmes_de_funciones/ft_handle_format.md) |

# Herramientas recomendadas
En esta sección encontrarás una lista de herramientas que te serán útiles durante el desarrollo de este proyecto. Estas herramientas están diseñadas para facilitar la depuración, la escritura de código y la gestión de tu proyecto.

## Lista de herramientas recomendadas

- **Valgrind**: Para detectar fugas de memoria y errores relacionados con la gestión de memoria.
- **Norminette**: Una herramienta para verificar que tu código cumple con la Norma de 42.
- **Printf Tester**: Herramientas externas para probar la funcionalidad de tu `ft_printf`.

