# ft_split
`ft_split` es una función que divide una cadena en un array de cadenas utilizando un delimitador específico.

## Prototipo
```c
char **ft_split(char const *s, char c);
```

## Parámetros
- `s`: La cadena a dividir.
- `c`: El carácter delimitador.

## Valor de retorno
- Devuelve un array de cadenas terminadas en `NULL`, resultado de dividir la cadena `s` por el carácter `c`.
- Si la asignación falla o el parámetro `s` es `NULL`, devuelve `NULL`.

## Descripción
La función asigna memoria y devuelve un array de cadenas, donde cada elemento es una subcadena de `s` separada por el carácter `c`. El array final está terminado con un puntero `NULL`.

## Funciones autorizadas
- `malloc`: Se utiliza para asignar memoria dinámica para las subcadenas y el array de cadenas.
- `free`: Se utiliza para liberar la memoria asignada en caso de error o cuando ya no se necesita.

## Ejemplo de uso
```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = "Hola,esto,es,una,prueba";
    char c = ',';
    char **result;
    int i = 0;

    result = ft_split(s, c);
    if (!result)
    {
        perror("Error al asignar memoria");
        return 1;
    }

    while (result[i])
    {
        printf("Subcadena %d: '%s'\n", i, result[i]);
        free(result[i]);
        i++;
    }
    free(result);

    return 0;
}
```