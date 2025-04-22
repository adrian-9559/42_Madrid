# ft_striteri
`ft_striteri` es una función que aplica una función dada a cada carácter de una cadena, pasando su índice como primer argumento.

## Prototipo
```c
void ft_striteri(char *s, void (*f)(unsigned int, char*));
```

## Parámetros
- `s`: La cadena sobre la que se iterará.
- `f`: La función que se aplicará a cada carácter de la cadena.

## Valor de retorno
- No devuelve ningún valor.

## Descripción
La función itera sobre cada carácter de la cadena `s` y aplica la función `f` a cada carácter, pasando el índice del carácter como primer argumento y un puntero al carácter como segundo argumento.

## Ejemplo de uso
```c
#include <stdio.h>

void to_uppercase(unsigned int i, char *c)
{
    if (c && *c >= 'a' && *c <= 'z')
        *c -= 32;
}

int main(void)
{
    char str[] = "hola mundo";

    ft_striteri(str, to_uppercase);
    printf("Cadena modificada: '%s'\n", str);

    return 0;
}
```