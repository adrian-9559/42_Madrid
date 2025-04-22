# ft_atoi
`ft_atoi` es una función que convierte una cadena de caracteres en un número entero.

## Prototipo
```c
int ft_atoi(const char *str);
```

## Parámetros
- `str`: Un puntero a la cadena de caracteres que se desea convertir.

## Valor de retorno
- Devuelve el número entero representado por la cadena.
- Si la conversión no es posible, el comportamiento es indefinido.

## Descripción
La función analiza la cadena de caracteres apuntada por `str`, omitiendo los espacios en blanco iniciales, y convierte la secuencia de caracteres en un número entero. La conversión se detiene al encontrar un carácter no numérico.

## Ejemplo de uso
```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char str1[] = "42";
    char str2[] = "   -123";
    char str3[] = "0";
    char str4[] = "abc123";

    int num1 = ft_atoi(str1);
    int num2 = ft_atoi(str2);
    int num3 = ft_atoi(str3);
    int num4 = ft_atoi(str4);

    printf("Conversión de '%s': %d\n", str1, num1);
    printf("Conversión de '%s': %d\n", str2, num2);
    printf("Conversión de '%s': %d\n", str3, num3);
    printf("Conversión de '%s': %d\n", str4, num4);

    return 0;
}
```