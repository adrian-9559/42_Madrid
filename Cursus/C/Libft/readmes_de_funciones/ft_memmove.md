# ft_memmove
`ft_memmove` es una función que copia un bloque de memoria de una ubicación a otra, permitiendo que los bloques de memoria se solapen.

## Prototipo
```c
void *ft_memmove(void *dst, const void *src, size_t len);
```

## Parámetros
- `dst`: Un puntero al bloque de memoria de destino donde se copiarán los datos.
- `src`: Un puntero al bloque de memoria de origen desde donde se copiarán los datos.
- `len`: La cantidad de bytes a copiar.

## Valor de retorno
- Devuelve un puntero al bloque de memoria `dst`.

## Descripción
La función copia `len` bytes del bloque de memoria apuntado por `src` al bloque de memoria apuntado por `dst`. A diferencia de `ft_memcpy`, `ft_memmove` maneja correctamente el solapamiento entre los bloques de memoria.

## Ejemplo de uso
```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[50] = "Hola, mundo!";
    printf("Antes de memmove: str = %s\n", str);
    ft_memmove(str + 5, str, strlen(str) + 1);
    printf("Después de memmove: str = %s\n", str);
    return 0;
}
```