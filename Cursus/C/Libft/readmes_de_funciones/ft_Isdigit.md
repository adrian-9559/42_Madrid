# ft_isdigit
`ft_isdigit` es una función que verifica si un carácter dado es un dígito decimal (0-9).

## Prototipo
```c
int ft_isdigit(unsigned int c);
```

## Parámetros
- `c`: El carácter a evaluar, representado como un valor entero sin signo.

## Valor de retorno
- Devuelve `1` si el carácter es un dígito (0-9).
- Devuelve `0` en caso contrario.

## Descripción
La función utiliza comparaciones para determinar si el valor de `c` se encuentra dentro del rango ASCII correspondiente a los dígitos decimales (`'0'` a `'9'`).

## Ejemplo de uso
```c
#include <stdio.h>

int main(void)
{
    char c = '5';
    if (ft_isdigit(c))
        printf("%c es un dígito.\n", c);
    else
        printf("%c no es un dígito.\n", c);
    return 0;
}
```