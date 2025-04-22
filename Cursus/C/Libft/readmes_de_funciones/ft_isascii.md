# ft_isascii
`ft_isascii` es una función que verifica si un carácter dado pertenece al conjunto ASCII, es decir, si su valor está en el rango de 0 a 127.

## Prototipo
```c
int ft_isascii(unsigned int c);
```

## Parámetros
- `c`: El carácter a evaluar, representado como un valor entero sin signo.

## Valor de retorno
- Devuelve `1` si el carácter pertenece al conjunto ASCII.
- Devuelve `0` en caso contrario.

## Descripción
La función determina si el valor de `c` está dentro del rango de valores válidos para los caracteres ASCII.

## Ejemplo de uso
```c
#include <stdio.h>

int main(void)
{
    char c = 127;
    if (ft_isascii(c))
        printf("%c pertenece al conjunto ASCII.\n", c);
    else
        printf("%c no pertenece al conjunto ASCII.\n", c);
    return 0;
}
```