# ft_strmapi
`ft_strmapi` es una función que aplica una función dada a cada carácter de una cadena, generando una nueva cadena con los resultados.

## Prototipo
```c
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
```

## Parámetros
- `s`: La cadena sobre la que se iterará.
- `f`: La función a aplicar a cada carácter. Recibe como parámetros el índice del carácter y el carácter en sí.

## Valor de retorno
- Devuelve un puntero a la nueva cadena creada como resultado de aplicar la función `f` a cada carácter de `s`.
- Si la asignación falla, devuelve `NULL`.

## Descripción
La función asigna memoria y crea una nueva cadena, donde cada carácter es el resultado de aplicar la función `f` al carácter correspondiente de la cadena `s`.

## Funciones autorizadas
- `malloc`: Se utiliza para asignar memoria dinámica. En `ft_strmapi`, se emplea `malloc` para reservar espacio suficiente para la nueva cadena.

## Ejemplo de uso
```c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char to_uppercase(unsigned int i, char c)
{
    (void)i; // El índice no se utiliza en este caso
    return (char)toupper((unsigned char)c);
}

int main(void)
{
    char *str = "hola mundo";
    char *result;

    result = ft_strmapi(str, to_uppercase);
    if (!result)
    {
        perror("Error al asignar memoria");
        return 1;
    }

    printf("Resultado: '%s'\n", result);

    free(result);
    return 0;
}
```