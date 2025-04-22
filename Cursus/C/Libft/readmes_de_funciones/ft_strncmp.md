# ft_strncmp
`ft_strncmp` es una función que compara los primeros `n` caracteres de dos cadenas.

## Prototipo
```c
int ft_strncmp(const char *s1, const char *s2, size_t n);
```

## Parámetros
- `s1`: Un puntero a la primera cadena a comparar.
- `s2`: Un puntero a la segunda cadena a comparar.
- `n`: El número máximo de caracteres a comparar.

## Valor de retorno
- Devuelve un número entero menor, igual o mayor que cero si los primeros `n` caracteres de `s1` son, respectivamente, menores, iguales o mayores que los de `s2`.

## Descripción
La función compara carácter por carácter las cadenas `s1` y `s2` hasta un máximo de `n` caracteres o hasta que se encuentre un carácter nulo en cualquiera de las cadenas. La comparación se realiza utilizando el valor ASCII de los caracteres.

## Ejemplo de uso
```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    const char str1[] = "Hola, mundo!";
    const char str2[] = "Hola, Madrid!";
    size_t n = 5;

    int result = ft_strncmp(str1, str2, n);
    if (result == 0)
        printf("Las cadenas son iguales en los primeros %zu caracteres.\n", n);
    else if (result < 0)
        printf("La primera cadena es menor que la segunda en los primeros %zu caracteres.\n", n);
    else
        printf("La primera cadena es mayor que la segunda en los primeros %zu caracteres.\n", n);

    return 0;
}
```