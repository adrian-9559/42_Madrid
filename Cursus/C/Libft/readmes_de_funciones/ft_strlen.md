# ft_strlen
`ft_strlen` es una función que calcula la longitud de una cadena de caracteres.

## Prototipo
```c
size_t ft_strlen(const char *s);
```

## Parámetros
- `s`: Un puntero a la cadena de caracteres cuya longitud se desea calcular.

## Valor de retorno
- Devuelve la longitud de la cadena, excluyendo el carácter nulo de terminación (`\0`).

## Descripción
La función recorre la cadena de caracteres hasta encontrar el carácter nulo (`\0`) y cuenta el número de caracteres en el proceso.

## Ejemplo de uso
```c
#include <stdio.h>

int main(void)
{
    const char *str = "Hola, mundo!";
    printf("La longitud de la cadena es: %zu\n", ft_strlen(str));
    return 0;
}
```