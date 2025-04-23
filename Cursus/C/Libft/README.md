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

# Enunciado original
[Enunciado en Español](es.subject.pdf)

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

<table>
	<thead>
		<tr>
			<th colspan="2">Funciones de la libreria Libc</th>
			<th colspan="2">Funciones Adicionales</th>
			<th colspan="2">Funciones Bonus</th>
		</tr>
		<tr>
			<th>Función</th>
			<th>Enlace al README</th>
			<th>Función</th>
			<th>Enlace al README</th>
			<th>Función</th>
			<th>Enlace al README</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>ft_isalpha</td>
			<td><a href="readmes_de_funciones/ft_isalpha.md">README</a></td>
			<td>ft_substr</td>
			<td><a href="readmes_de_funciones/ft_substr.md">README</a></td>
			<td>ft_lstnew</td>
			<td><a href="readmes_de_funciones/ft_lstnew.md">README</a></td>
		</tr>
		<tr>
			<td>ft_isdigit</td>
			<td><a href="readmes_de_funciones/ft_isdigit.md">README</a></td>
			<td>ft_strjoin</td>
			<td><a href="readmes_de_funciones/ft_strjoin.md">README</a></td>
			<td>ft_lstadd_front</td>
			<td><a href="readmes_de_funciones/ft_lstadd_front.md">README</a></td>
		</tr>
		<tr>
			<td>ft_isalnum</td>
			<td><a href="readmes_de_funciones/ft_isalnum.md">README</a></td>
			<td>ft_strtrim</td>
			<td><a href="readmes_de_funciones/ft_strtrim.md">README</a></td>
			<td>ft_lstsize</td>
			<td><a href="readmes_de_funciones/ft_lstsize.md">README</a></td>
		</tr>
		<tr>
			<td>ft_isascii</td>
			<td><a href="readmes_de_funciones/ft_isascii.md">README</a></td>
			<td>ft_split</td>
			<td><a href="readmes_de_funciones/ft_split.md">README</a></td>
			<td>ft_lstlast</td>
			<td><a href="readmes_de_funciones/ft_lstlast.md">README</a></td>
		</tr>
		<tr>
			<td>ft_isprint</td>
			<td><a href="readmes_de_funciones/ft_isprint.md">README</a></td>
			<td>ft_itoa</td>
			<td><a href="readmes_de_funciones/ft_itoa.md">README</a></td>
			<td>ft_lstadd_back</td>
			<td><a href="readmes_de_funciones/ft_lstadd_back.md">README</a></td>
		</tr>
		<tr>
			<td>ft_strlen</td>
			<td><a href="readmes_de_funciones/ft_istrlen.md">README</a></td>
			<td>ft_strmapi</td>
			<td><a href="readmes_de_funciones/ft_strmapi.md">README</a></td>
			<td>ft_lstdelone</td>
			<td><a href="readmes_de_funciones/ft_lstdelone.md">README</a></td>
		</tr>
		<tr>
			<td>ft_memset</td>
			<td><a href="readmes_de_funciones/ft_memset.md">README</a></td>
			<td>ft_striteri</td>
			<td><a href="readmes_de_funciones/ft_striteri.md">README</a></td>
			<td>ft_lstclear</td>
			<td><a href="readmes_de_funciones/ft_lstclear.md">README</a></td>
		</tr>
		<tr>
			<td>ft_bzero</td>
			<td><a href="readmes_de_funciones/ft_bzero.md">README</a></td>
			<td>ft_putchar_fd</td>
			<td><a href="readmes_de_funciones/ft_putchar_fd.md">README</a></td>
			<td>ft_lstiter</td>
			<td><a href="readmes_de_funciones/ft_lstiter.md">README</a></td>
		</tr>
		<tr>
			<td>ft_memcpy</td>
			<td><a href="readmes_de_funciones/ft_memcpy.md">README</a></td>
			<td>ft_putstr_fd</td>
			<td><a href="readmes_de_funciones/ft_putstr_fd.md">README</a></td>
			<td>ft_lstmap</td>
			<td><a href="readmes_de_funciones/ft_lstmap.md">README</a></td>
		</tr>
		<tr>
			<td>ft_memmove</td>
			<td><a href="readmes_de_funciones/ft_memmove.md">README</a></td>
			<td>ft_putendl_fd</td>
			<td><a href="readmes_de_funciones/ft_putendl_fd.md">README</a></td>
			<td></td>
			<td></td>
		</tr>
		<tr>
			<td>ft_strlcpy</td>
			<td><a href="readmes_de_funciones/ft_strlcpy.md">README</a></td>
			<td>ft_putnbr_fd</td>
			<td><a href="readmes_de_funciones/ft_putnbr_fd.md">README</a></td>
			<td></td>
			<td></td>
		</tr>
		<tr>
			<td>ft_strlcat</td>
			<td><a href="readmes_de_funciones/ft_strlcat.md">README</a></td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
		</tr>
		<tr>
			<td>ft_tolower</td>
			<td><a href="readmes_de_funciones/ft_tolower.md">README</a></td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
		</tr>
		<tr>
			<td>ft_strchr</td>
			<td><a href="readmes_de_funciones/ft_strchr.md">README</a></td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
		</tr>
		<tr>
			<td>ft_strrchr</td>
			<td><a href="readmes_de_funciones/ft_strrchr.md">README</a></td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
		</tr>
		<tr>
			<td>ft_strncmp</td>
			<td><a href="readmes_de_funciones/ft_strncmp.md">README</a></td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
		</tr>
		<tr>
			<td>ft_memchr</td>
			<td><a href="readmes_de_funciones/ft_memchr.md">README</a></td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
		</tr>
		<tr>
			<td>ft_memcmp</td>
			<td><a href="readmes_de_funciones/ft_memcmp.md">README</a></td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
		</tr>
		<tr>
			<td>ft_strnstr</td>
			<td><a href="readmes_de_funciones/ft_strnstr.md">README</a></td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
		</tr>
		<tr>
			<td>ft_atoi</td>
			<td><a href="readmes_de_funciones/ft_atoi.md">README</a></td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
		</tr>
		<tr>
			<td>ft_calloc</td>
			<td><a href="readmes_de_funciones/ft_calloc.md">README</a></td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
		</tr>
		<tr>
			<td>ft_strdup</td>
			<td><a href="readmes_de_funciones/ft_strdup.md">README</a></td>
			<td></td>
			<td></td>
			<td></td>
			<td></td>
		</tr>
	</tbody>
</table>

# Herramientas recomendadas
En esta sección encontrarás una lista de herramientas que te serán útiles durante el desarrollo de este proyecto. Estas herramientas están diseñadas para facilitar la depuración, la escritura de código y la gestión de tu proyecto.

## Lista de herramientas recomendadas

- **Valgrind**: Para detectar fugas de memoria y errores relacionados con la gestión de memoria.
- **Norminette**: Una herramienta para verificar que tu código cumple con la Norma de 42.
