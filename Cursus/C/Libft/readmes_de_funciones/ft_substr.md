# ft_substr
`ft_substr` es una función que extrae una subcadena de una cadena dada.

## Prototipo
```c
char *ft_substr(char const *s, unsigned int start, size_t len);
```

## Parámetros
- `s`: La cadena de la cual se extraerá la subcadena.
- `start`: Índice inicial desde donde comienza la subcadena.
- `len`: Longitud máxima de la subcadena.

## Valor de retorno
- Devuelve un puntero a la subcadena extraída.
- Si la asignación falla o `s` es `NULL`, devuelve `NULL`.

## Descripción
La función asigna memoria y devuelve una subcadena de la cadena `s`. La subcadena comienza en el índice `start` y tiene una longitud máxima de `len`. Si `start` está fuera del rango de la cadena, se devuelve una cadena vacía.

## Funciones autorizadas
- `malloc`: Se utiliza para asignar memoria dinámica. En `ft_substr`, se emplea `malloc` para reservar espacio suficiente para la subcadena.

## Ejemplo de uso
```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = "Hola, mundo!";
    char *substr;

    substr = ft_substr(s, 7, 5);
    if (!substr)
    {
        perror("Error al asignar memoria");
        return 1;
    }

    printf("Subcadena: %s\n", substr);

    free(substr);
    return 0;
}
```