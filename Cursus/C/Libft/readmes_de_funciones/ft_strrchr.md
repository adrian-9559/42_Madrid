# ft_strrchr
`ft_strrchr` es una función que localiza la última aparición de un carácter en una cadena.

## Prototipo
```c
char *ft_strrchr(const char *s, int c);
```

## Parámetros
- `s`: Un puntero a la cadena en la que se buscará el carácter.
- `c`: El carácter que se desea localizar (convertido a un `unsigned char`).

## Valor de retorno
- Devuelve un puntero a la última aparición del carácter `c` en la cadena `s`, o `NULL` si el carácter no se encuentra.

## Descripción
La función busca la última aparición del carácter `c` en la cadena `s`. El carácter nulo de terminación también se considera parte de la cadena, por lo que se puede buscar `'\0'`.

## Ejemplo de uso
```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    const char str[] = "Hola, mundo!";
    char c = 'o';

    char *result = ft_strrchr(str, c);
    if (result)
        printf("Última aparición de '%c': %s\n", c, result);
    else
        printf("El carácter '%c' no se encontró.\n", c);

    return 0;
}
```