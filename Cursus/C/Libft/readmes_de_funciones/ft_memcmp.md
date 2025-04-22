# ft_memcmp
`ft_memcmp` es una función que compara dos bloques de memoria byte a byte.

## Prototipo
```c
int ft_memcmp(const void *s1, const void *s2, size_t n);
```

## Parámetros
- `s1`: Un puntero al primer bloque de memoria a comparar.
- `s2`: Un puntero al segundo bloque de memoria a comparar.
- `n`: La cantidad de bytes a comparar.

## Valor de retorno
- Devuelve un valor entero:
    - `0` si los bloques de memoria son iguales.
    - Un valor negativo si el primer byte que no coincide en `s1` es menor que el correspondiente en `s2`.
    - Un valor positivo si el primer byte que no coincide en `s1` es mayor que el correspondiente en `s2`.

## Descripción
La función compara los primeros `n` bytes de los bloques de memoria apuntados por `s1` y `s2`. La comparación se realiza byte a byte.

## Ejemplo de uso
```c
#include <stdio.h>
#include <string.h>

int main(void)
{
        char str1[50] = "Hola, mundo!";
        char str2[50] = "Hola, mundo!";
        char str3[50] = "Hola, Madrid!";
        
        int result1 = ft_memcmp(str1, str2, strlen(str1));
        int result2 = ft_memcmp(str1, str3, strlen(str1));
        
        printf("Comparación str1 y str2: %d\n", result1);
        printf("Comparación str1 y str3: %d\n", result2);
        
        return 0;
}
```