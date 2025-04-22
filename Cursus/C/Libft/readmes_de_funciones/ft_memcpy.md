# ft_memcpy
`ft_memcpy` es una función que copia un bloque de memoria de una ubicación a otra.

## Prototipo
```c
void *ft_memcpy(void *dst, const void *src, size_t n);
```

## Parámetros
- `dst`: Un puntero al bloque de memoria de destino donde se copiarán los datos.
- `src`: Un puntero al bloque de memoria de origen desde donde se copiarán los datos.
- `n`: La cantidad de bytes a copiar.

## Valor de retorno
- Devuelve un puntero al bloque de memoria `dst`.

## Descripción
La función copia `n` bytes del bloque de memoria apuntado por `src` al bloque de memoria apuntado por `dst`. Los bloques de memoria no deben solaparse.

## Ejemplo de uso
```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char src[50] = "Hola, mundo!";
    char dst[50];
    printf("Antes de memcpy: src = %s, dst = %s\n", src, dst);
    ft_memcpy(dst, src, strlen(src) + 1);
    printf("Después de memcpy: src = %s, dst = %s\n", src, dst);
    return 0;
}
```