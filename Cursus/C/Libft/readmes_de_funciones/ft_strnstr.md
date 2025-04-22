# ft_strnstr
`ft_strnstr` es una función que localiza una subcadena dentro de una cadena, pero solo busca en los primeros `n` caracteres.

## Prototipo
```c
char *ft_strnstr(const char *haystack, const char *needle, size_t len);
```

## Parámetros
- `haystack`: La cadena en la que se buscará.
- `needle`: La subcadena que se desea encontrar.
- `len`: El número máximo de caracteres a buscar.

## Valor de retorno
- Devuelve un puntero al primer carácter de la primera aparición de `needle` en `haystack`.
- Devuelve `NULL` si `needle` no se encuentra en los primeros `len` caracteres de `haystack`.
- Si `needle` es una cadena vacía, devuelve `haystack`.

## Descripción
La función busca la primera aparición de la subcadena `needle` dentro de la cadena `haystack`, pero solo examina como máximo los primeros `len` caracteres de `haystack`.

## Ejemplo de uso
```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    const char *haystack = "Hola, mundo!";
    const char *needle1 = "mundo";
    const char *needle2 = "Madrid";
    
    char *result1 = ft_strnstr(haystack, needle1, strlen(haystack));
    char *result2 = ft_strnstr(haystack, needle2, strlen(haystack));
    
    if (result1)
        printf("Subcadena encontrada: %s\n", result1);
    else
        printf("Subcadena no encontrada: %s\n", needle1);
    
    if (result2)
        printf("Subcadena encontrada: %s\n", result2);
    else
        printf("Subcadena no encontrada: %s\n", needle2);
    
    return 0;
}
```