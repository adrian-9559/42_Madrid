# ft_strlcpy
`ft_strlcpy` es una función que copia una cadena a un buffer de tamaño limitado, asegurando la terminación nula.

## Prototipo
```c
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);
```

## Parámetros
- `dst`: Un puntero al buffer de destino donde se copiará la cadena.
- `src`: Un puntero a la cadena de origen que se desea copiar.
- `dstsize`: El tamaño del buffer de destino.

## Valor de retorno
- Devuelve la longitud de la cadena de origen (`src`).

## Descripción
La función copia hasta `dstsize - 1` caracteres de la cadena `src` al buffer `dst`, asegurándose de que el resultado esté terminado en nulo si `dstsize` es mayor que 0. Si la longitud de `src` es mayor o igual a `dstsize`, el resultado será truncado.

## Ejemplo de uso
```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char src[] = "Hola, mundo!";
    char dst[10];

    size_t result = ft_strlcpy(dst, src, sizeof(dst));
    printf("Cadena copiada: %s\n", dst);
    printf("Longitud de la cadena de origen: %zu\n", result);

    return 0;
}
```