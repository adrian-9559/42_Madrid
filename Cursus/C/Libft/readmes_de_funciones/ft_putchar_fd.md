# ft_putchar_fd
`ft_putchar_fd` es una función que escribe un carácter en un descriptor de archivo dado.

## Prototipo
```c
void ft_putchar_fd(char c, int fd);
```

## Parámetros
- `c`: El carácter que se escribirá.
- `fd`: El descriptor de archivo donde se escribirá el carácter.

## Valor de retorno
- No devuelve ningún valor.

## Descripción
La función utiliza la función autorizada `write` para escribir el carácter `c` en el descriptor de archivo especificado por `fd`.

## Ejemplo de uso
```c
#include <unistd.h>

int main(void)
{
    char c = 'A';

    ft_putchar_fd(c, 1); // Escribe 'A' en la salida estándar (stdout)

    return 0;
}
```