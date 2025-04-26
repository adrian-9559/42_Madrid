# ft_putnbr_base
`ft_putnbr_base` es una función que escribe un número entero en una base específica en la salida estándar y devuelve el número de caracteres escritos.

## Prototipo
```c
int ft_putnbr_base(unsigned long n, int base);
```

## Parámetros
- `n`: El número entero que se escribirá.
- `base`: Una cadena de caracteres que representa la base en la que se escribirá el número. Debe contener al menos dos caracteres únicos y no puede incluir signos `+` o `-`.

## Valor de retorno
- Devuelve el número de caracteres escritos, o `-1` si la base es inválida.

## Descripción
La función convierte el número entero `n` a la base especificada por `base` y lo escribe en la salida estándar (stdout) utilizando la función autorizada `write`. Si el número es negativo, se escribe el signo `-` antes del valor absoluto del número. La función valida que la base sea válida (al menos dos caracteres únicos y sin signos `+` o `-`). Si la base no es válida, no realiza ninguna escritura y devuelve `-1`.

## Ejemplo de uso
```c
#include <unistd.h>

int main(void)
{
    int num = 42;
    int count;

    count = ft_putnbr_base(num, 'x'); // Escribe "2A" en stdout y devuelve 2
    return 0;
}
```