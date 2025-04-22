# ft_tolower
`ft_tolower` es una función que convierte un carácter en minúscula si es una letra mayúscula.

## Prototipo
```c
int ft_tolower(int c);
```

## Parámetros
- `c`: El carácter que se desea convertir.

## Valor de retorno
- Devuelve el carácter convertido en minúscula si es una letra mayúscula.
- Si el carácter no es una letra mayúscula, se devuelve sin cambios.

## Descripción
La función verifica si el carácter proporcionado es una letra mayúscula. Si lo es, lo convierte a su equivalente en minúscula utilizando la codificación ASCII. Si no, simplemente devuelve el carácter original.

## Ejemplo de uso
```c
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char c = 'A';
    char result = ft_tolower(c);

    printf("Carácter original: %c\n", c);
    printf("Carácter convertido: %c\n", result);

    return 0;
}
```