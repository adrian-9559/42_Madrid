# ft_strjoin
`ft_strjoin` es una función que concatena dos cadenas en una nueva cadena.

## Prototipo
```c
char *ft_strjoin(char const *s1, char const *s2);
```

## Parámetros
- `s1`: La primera cadena.
- `s2`: La segunda cadena.

## Valor de retorno
- Devuelve un puntero a la nueva cadena concatenada.
- Si la asignación falla o alguno de los parámetros es `NULL`, devuelve `NULL`.

## Descripción
La función asigna memoria y devuelve una nueva cadena que es el resultado de concatenar `s1` y `s2`. La nueva cadena incluye todos los caracteres de `s1` seguidos por todos los caracteres de `s2`.

## Funciones autorizadas
- `malloc`: Se utiliza para asignar memoria dinámica. En `ft_strjoin`, se emplea `malloc` para reservar espacio suficiente para la cadena concatenada.

## Ejemplo de uso
```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s1 = "Hola, ";
    char *s2 = "mundo!";
    char *joined;

    joined = ft_strjoin(s1, s2);
    if (!joined)
    {
        perror("Error al asignar memoria");
        return 1;
    }

    printf("Cadena concatenada: %s\n", joined);

    free(joined);
    return 0;
}
```