# ft_isalpha
`ft_isalpha` es una función que verifica si un carácter dado es una letra del alfabeto (ya sea mayúscula o minúscula). 

## Prototipo
```c
int ft_isalpha(unsigned int c);
```

## Parámetros
- `c`: El carácter a evaluar, representado como un valor entero sin signo.

## Valor de retorno
- Devuelve `1` si el carácter es una letra (A-Z o a-z).
- Devuelve `0` en caso contrario.

## Descripción
La función utiliza comparaciones para determinar si el valor de `c` se encuentra dentro de los rangos ASCII correspondientes a las letras mayúsculas (`'A'` a `'Z'`) o minúsculas (`'a'` a `'z'`).

## Ejemplo de uso
```c
#include <stdio.h>

int main(void)
{
    char c = 'A';
    if (ft_isalpha(c))
        printf("%c es una letra.\n", c);
    else
        printf("%c no es una letra.\n", c);
    return 0;
}
```