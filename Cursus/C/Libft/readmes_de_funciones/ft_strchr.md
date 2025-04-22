# ft_strchr
`ft_strchr` es una función que busca la primera aparición de un carácter específico en una cadena.

## Prototipo
```c
char *ft_strchr(const char *s, int c);
```

## Parámetros
- `s`: Un puntero a la cadena donde se realizará la búsqueda.
- `c`: El carácter que se desea buscar, interpretado como un `unsigned char`.

## Valor de retorno
- Devuelve un puntero a la primera aparición del carácter `c` en la cadena `s`.
- Si el carácter no se encuentra, devuelve `NULL`.

## Descripción
La función recorre la cadena `s` buscando la primera aparición del carácter `c`. Si el carácter se encuentra, devuelve un puntero a su posición en la cadena. Si no se encuentra, devuelve `NULL`. Si `c` es el carácter nulo (`'\0'`), la función devuelve un puntero al final de la cadena.

## Ejemplo de uso
```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    const char *str = "Hola, mundo!";
    char c = 'm';
    char *result = ft_strchr(str, c);

    if (result != NULL)
        printf("El carácter '%c' se encontró en: %s\n", c, result);
    else
        printf("El carácter '%c' no se encontró en la cadena.\n", c);

    return 0;
}
```