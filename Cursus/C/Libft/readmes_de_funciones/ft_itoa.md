# ft_itoa
`ft_itoa` es una función que convierte un número entero en una cadena de caracteres terminada en nulo.

## Prototipo
```c
char *ft_itoa(int n);
```

## Parámetros
- `n`: El número entero a convertir.

## Valor de retorno
- Devuelve un puntero a la cadena que representa el número.
- Si la asignación falla, devuelve `NULL`.

## Descripción
La función asigna memoria y devuelve una cadena que representa el número entero `n`. La cadena está terminada en nulo (`\0`).

## Funciones autorizadas
- `malloc`: Se utiliza para asignar memoria dinámica. En `ft_itoa`, se emplea `malloc` para reservar espacio suficiente para la cadena que representa el número.

## Ejemplo de uso
```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int number = 42;
    char *str;

    str = ft_itoa(number);
    if (!str)
    {
        perror("Error al asignar memoria");
        return 1;
    }

    printf("Número como cadena: '%s'\n", str);

    free(str);
    return 0;
}
```