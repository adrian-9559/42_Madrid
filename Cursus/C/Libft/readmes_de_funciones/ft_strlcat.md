# ft_strlcat
`ft_strlcat` es una función que concatena una cadena a un buffer de tamaño limitado, asegurando la terminación nula.

## Prototipo
```c
size_t ft_strlcat(char *dst, const char *src, size_t dstsize);
```

## Parámetros
- `dst`: Un puntero al buffer de destino donde se concatenará la cadena.
- `src`: Un puntero a la cadena de origen que se desea concatenar.
- `dstsize`: El tamaño total del buffer de destino.

## Valor de retorno
- Devuelve la longitud total que tendría la cadena concatenada si no hubiera truncamiento.

## Descripción
La función concatena la cadena `src` al final de la cadena `dst`, asegurándose de que el resultado esté terminado en nulo si `dstsize` es mayor que 0. Copia como máximo `dstsize - strlen(dst) - 1` caracteres de `src` al buffer `dst`. Si el tamaño del buffer no es suficiente, el resultado será truncado.

## Ejemplo de uso
```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char src[] = " mundo!";
    char dst[15] = "Hola,";

    size_t result = ft_strlcat(dst, src, sizeof(dst));
    printf("Cadena concatenada: %s\n", dst);
    printf("Longitud total esperada: %zu\n", result);

    return 0;
}
```