# handle_format
`handle_format` es una función estática que analiza y maneja un formato específico dentro de una cadena de formato, utilizando una lista de argumentos variable.

## Prototipo
```c
static int handle_format(const char **format, va_list *va);
```

## Parámetros
- `format`: Un puntero doble a la cadena de formato que se está procesando.
- `va`: Un puntero a la lista de argumentos variable.

## Valor de retorno
- Devuelve el número total de caracteres escritos como resultado del manejo del formato.

## Descripción
La función `handle_format` realiza las siguientes tareas:
1. Inicializa una estructura de banderas (`t_flags`) para almacenar las opciones de formato.
2. Analiza las banderas, el ancho y la precisión del formato.
3. Identifica el especificador de formato y llama a la función correspondiente para manejarlo:
    - `'c'`: Maneja caracteres.
    - `'s'`: Maneja cadenas.
    - `'p'`: Maneja punteros.
    - `'d'` o `'i'`: Maneja enteros con signo.
    - `'u'`: Maneja enteros sin signo.
    - `'x'` o `'X'`: Maneja números hexadecimales.
    - `'%'`: Maneja el carácter de porcentaje literal.

## Ejemplo de uso
```c
#include <stdarg.h>
#include <stdio.h>

int main(void)
{
     const char *format = "%d";
     va_list args;
     int count;

     va_start(args, format);
     count = handle_format(&format, &args); // Maneja el formato "%d"
     va_end(args);

     printf("Caracteres escritos: %d\n", count);
     return 0;
}
```
