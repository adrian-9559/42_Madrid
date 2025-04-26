# ft_putnbr_unsigned
`ft_putnbr_unsigned` es una función que escribe un número entero sin signo en la salida estándar y devuelve el número de caracteres escritos.

## Prototipo
```c
int ft_putnbr_unsigned(unsigned int n);
```

## Parámetros
- `n`: El número entero sin signo que se escribirá.

## Valor de retorno
- Devuelve el número de caracteres escritos.

## Descripción
La función utiliza la función autorizada `write` para escribir el número entero sin signo `n` en la salida estándar (stdout). La escritura se realiza carácter por carácter. Al finalizar, devuelve la cantidad total de caracteres escritos.

## Ejemplo de uso
```c
#include <unistd.h>

int main(void)
{
    unsigned int num = 42;
    int count;

    count = ft_putnbr_unsigned(num); // Escribe "42" en stdout y devuelve 2
    return 0;
}
```