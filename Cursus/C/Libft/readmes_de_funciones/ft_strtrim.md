# ft_strtrim
`ft_strtrim` es una función que elimina los caracteres especificados al principio y al final de una cadena.

## Prototipo
```c
char *ft_strtrim(char const *s1, char const *set);
```

## Parámetros
- `s1`: La cadena a recortar.
- `set`: Los caracteres a eliminar de los extremos de `s1`.

## Valor de retorno
- Devuelve un puntero a la nueva cadena recortada.
- Si la asignación falla o alguno de los parámetros es `NULL`, devuelve `NULL`.

## Descripción
La función asigna memoria y devuelve una nueva cadena que es una copia de `s1` sin los caracteres especificados en `set` al principio y al final. Si `set` está vacío, la cadena original no se modifica.

## Funciones autorizadas
- `malloc`: Se utiliza para asignar memoria dinámica. En `ft_strtrim`, se emplea `malloc` para reservar espacio suficiente para la cadena recortada.

## Ejemplo de uso
```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s1 = "   Hola, mundo!   ";
    char *set = " ";
    char *trimmed;

    trimmed = ft_strtrim(s1, set);
    if (!trimmed)
    {
        perror("Error al asignar memoria");
        return 1;
    }

    printf("Cadena recortada: '%s'\n", trimmed);

    free(trimmed);
    return 0;
}
```