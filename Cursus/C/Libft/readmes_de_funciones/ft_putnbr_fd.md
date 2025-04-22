# ft_putnbr_fd
`ft_putnbr_fd` es una función que escribe un número entero en un descriptor de archivo dado.

## Prototipo
```c
void ft_putnbr_fd(int n, int fd);
```

## Parámetros
- `n`: El número entero que se escribirá.
- `fd`: El descriptor de archivo donde se escribirá el número.

## Valor de retorno
- No devuelve ningún valor.

## Descripción
La función utiliza la función autorizada `write` para escribir el número entero `n` en el descriptor de archivo especificado por `fd`. Si el número es negativo, se escribe el signo `-` antes del valor absoluto del número. La escritura se realiza carácter por carácter.

## Ejemplo de uso
```c
#include <unistd.h>

int main(void)
{
    int num = 42;

    ft_putnbr_fd(num, 1); // Escribe "42" en la salida estándar (stdout)

    return 0;
}
```