# ft_strdup
`ft_strdup` es una función que duplica una cadena de caracteres.

## Prototipo
```c
char *ft_strdup(const char *s);
```

## Parámetros
- `s`: Un puntero a la cadena de caracteres que se desea duplicar.

## Valor de retorno
- Devuelve un puntero a una nueva cadena que es una copia de `s`.
- Devuelve `NULL` si no se pudo asignar memoria.

## Descripción
La función asigna memoria suficiente para una copia de la cadena `s`, la copia en la memoria recién asignada y devuelve un puntero a ella. Es responsabilidad del usuario liberar la memoria asignada cuando ya no sea necesaria.

## Funciones autorizadas
- `malloc`: Se utiliza para asignar memoria dinámica. En `ft_strdup`, se emplea `malloc` para reservar suficiente espacio en memoria para almacenar una copia de la cadena `s`.

## Ejemplo de uso
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char str1[] = "Hola, mundo!";
    char *duplicado;

    duplicado = ft_strdup(str1);
    if (duplicado == NULL)
    {
        perror("Error duplicando la cadena");
        return 1;
    }

    printf("Original: %s\n", str1);
    printf("Duplicado: %s\n", duplicado);

    free(duplicado);
    return 0;
}
```