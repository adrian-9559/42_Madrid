# ft_putendl_fd
`ft_putendl_fd` es una función que escribe una cadena de caracteres seguida de un salto de línea en un descriptor de archivo dado.

## Prototipo
```c
void ft_putendl_fd(char *s, int fd);
```

## Parámetros
- `s`: La cadena de caracteres que se escribirá.
- `fd`: El descriptor de archivo donde se escribirá la cadena.

## Valor de retorno
- No devuelve ningún valor.

## Descripción
La función utiliza la función autorizada `write` para escribir la cadena de caracteres `s` seguida de un salto de línea (`\n`) en el descriptor de archivo especificado por `fd`. La escritura se realiza carácter por carácter hasta encontrar el carácter nulo (`\0`), seguido de la escritura del salto de línea.

## Ejemplo de uso
```c
#include <unistd.h>

int main(void)
{
    char *str = "Hola, mundo!";

    ft_putendl_fd(str, 1); // Escribe "Hola, mundo!\n" en la salida estándar (stdout)

    return 0;
}
```