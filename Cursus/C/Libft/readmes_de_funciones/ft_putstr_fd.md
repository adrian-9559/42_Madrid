# ft_putstr_fd
`ft_putstr_fd` es una función que escribe una cadena de caracteres en un descriptor de archivo dado.

## Prototipo
```c
void ft_putstr_fd(char *s, int fd);
```

## Parámetros
- `s`: La cadena de caracteres que se escribirá.
- `fd`: El descriptor de archivo donde se escribirá la cadena.

## Valor de retorno
- No devuelve ningún valor.

## Descripción
La función utiliza la función autorizada `write` para escribir la cadena de caracteres `s` en el descriptor de archivo especificado por `fd`. La escritura se realiza carácter por carácter hasta encontrar el carácter nulo (`\0`).

## Ejemplo de uso
```c
#include <unistd.h>

int main(void)
{
    char *str = "Hola, mundo!";

    ft_putstr_fd(str, 1); // Escribe "Hola, mundo!" en la salida estándar (stdout)

    return 0;
}
```