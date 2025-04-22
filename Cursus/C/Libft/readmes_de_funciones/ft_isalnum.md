# ft_isalnum
`ft_isalnum` es una función que verifica si un carácter dado es alfanumérico, es decir, si es una letra (A-Z o a-z) o un dígito decimal (0-9).

## Prototipo
```c
int ft_isalnum(unsigned int c);
```

## Parámetros
- `c`: El carácter a evaluar, representado como un valor entero sin signo.

## Valor de retorno
- Devuelve `1` si el carácter es alfanumérico.
- Devuelve `0` en caso contrario.

## Descripción
La función combina las verificaciones de `ft_isalpha` y `ft_isdigit` para determinar si el valor de `c` es una letra o un dígito.

## Ejemplo de uso
```c
#include <stdio.h>

int main(void)
{
    char c = 'A';
    if (ft_isalnum(c))
        printf("%c es alfanumérico.\n", c);
    else
        printf("%c no es alfanumérico.\n", c);
    return 0;
}
```
