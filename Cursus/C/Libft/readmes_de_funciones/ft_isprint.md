# ft_isprint
`ft_isprint` es una función que verifica si un carácter dado es imprimible, incluyendo el espacio.

## Prototipo
```c
int ft_isprint(unsigned int c);
```

## Parámetros
- `c`: El carácter a evaluar, representado como un valor entero sin signo.

## Valor de retorno
- Devuelve `1` si el carácter es imprimible.
- Devuelve `0` en caso contrario.

## Descripción
La función determina si el valor de `c` corresponde a un carácter imprimible según la tabla ASCII, es decir, si está en el rango de 32 a 126 inclusive.

## Ejemplo de uso
```c
#include <stdio.h>

int main(void)
{
    char c = 'A';
    if (ft_isprint(c))
        printf("%c es un carácter imprimible.\n", c);
    else
        printf("%c no es un carácter imprimible.\n", c);
    return 0;
}
```
