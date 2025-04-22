# ft_memchr
`ft_memchr` es una función que busca la primera aparición de un carácter específico en un bloque de memoria.

## Prototipo
```c
void *ft_memchr(const void *s, int c, size_t n);
```

## Parámetros
- `s`: Un puntero al bloque de memoria donde se realizará la búsqueda.
- `c`: El carácter que se desea buscar (convertido a un `unsigned char`).
- `n`: El número de bytes a examinar en el bloque de memoria.

## Valor de retorno
- Devuelve un puntero al primer byte en el bloque de memoria que coincide con el carácter `c`.
- Devuelve `NULL` si el carácter no se encuentra en los primeros `n` bytes.

## Descripción
La función examina los primeros `n` bytes del bloque de memoria apuntado por `s` en busca del carácter `c`. La búsqueda se detiene tan pronto como se encuentra el carácter o se han examinado todos los bytes especificados.

## Ejemplo de uso
```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    const char str[] = "Hola, mundo!";
    char c = 'm';
    size_t n = 10;

    char *result = ft_memchr(str, c, n);
    if (result != NULL)
        printf("El carácter '%c' se encontró en la posición: %ld\n", c, result - str);
    else
        printf("El carácter '%c' no se encontró en los primeros %zu bytes.\n", c, n);

    return 0;
}
```