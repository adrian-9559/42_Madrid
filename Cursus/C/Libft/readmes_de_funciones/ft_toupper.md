# ft_toupper
`ft_toupper` es una función que convierte un carácter en su equivalente en mayúscula si es una letra minúscula.

## Prototipo
```c
int ft_toupper(int c);
```

## Parámetros
- `c`: El carácter que se desea convertir.

## Valor de retorno
- Devuelve el carácter convertido a mayúscula si es una letra minúscula.
- Si el carácter no es una letra minúscula, devuelve el carácter sin cambios.

## Descripción
La función verifica si el carácter proporcionado es una letra minúscula. Si lo es, lo convierte a su equivalente en mayúscula utilizando la tabla ASCII. Si no, simplemente devuelve el carácter original.

## Ejemplo de uso
```c
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char c = 'a';
    char result = ft_toupper(c);

    printf("Carácter original: %c\n", c);
    printf("Carácter convertido: %c\n", result);

    return 0;
}
```