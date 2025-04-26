# ft_putnbr
`ft_putnbr` es una función que escribe un número entero en la salida estándar y devuelve el número de caracteres escritos.

## Prototipo
```c
int ft_putnbr(int n);
```

## Parámetros
- `n`: El número entero que se escribirá.

## Valor de retorno
- Devuelve el número de caracteres escritos.

## Descripción
La función utiliza la función autorizada `write` para escribir el número entero `n` en la salida estándar (stdout). Si el número es negativo, se escribe el signo `-` antes del valor absoluto del número. La escritura se realiza carácter por carácter. Al finalizar, devuelve la cantidad total de caracteres escritos.

## Ejemplo de uso
```c
#include <unistd.h>

int main(void)
{
    int num = -42;
    int count;

    count = ft_putnbr(num); // Escribe "-42" en stdout y devuelve 3
    return 0;
}
```