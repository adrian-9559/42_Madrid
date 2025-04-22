# ft_memset
`ft_memset` es una función que llena un bloque de memoria con un valor específico.

## Prototipo
```c
void *ft_memset(void *b, int c, size_t len);
```

## Parámetros
- `b`: Un puntero al bloque de memoria que se desea llenar.
- `c`: El valor con el que se llenará el bloque de memoria (convertido a un `unsigned char`).
- `len`: La cantidad de bytes a llenar.

## Valor de retorno
- Devuelve un puntero al bloque de memoria `b`.

## Descripción
La función escribe el valor especificado (`c`) en los primeros `len` bytes del bloque de memoria apuntado por `b`.

## Ejemplo de uso
```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[50] = "Hola, mundo!";
    printf("Antes de memset: %s\n", str);
    ft_memset(str, '*', 5);
    printf("Después de memset: %s\n", str);
    return 0;
}
```