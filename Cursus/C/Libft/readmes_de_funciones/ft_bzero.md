# ft_bzero
`ft_bzero` es una función que establece a cero los bytes de un área de memoria.

## Prototipo
```c
void ft_bzero(void *s, size_t n);
```

## Parámetros
- `s`: Un puntero al área de memoria que se desea establecer a cero.
- `n`: El número de bytes que se deben establecer a cero.

## Valor de retorno
- Esta función no devuelve ningún valor.

## Descripción
La función establece los primeros `n` bytes del área de memoria apuntada por `s` a cero (`\0`).

## Ejemplo de uso
```c
#include <stdio.h>
#include <strings.h>

int main(void)
{
    char buffer[10] = "Hola";
    printf("Antes de ft_bzero: %s\n", buffer);
    ft_bzero(buffer, 10);
    printf("Después de ft_bzero: %s\n", buffer);
    return 0;
}
```