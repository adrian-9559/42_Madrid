# ft_putchar
`ft_putchar` es una función que escribe un carácter en la salida estándar y devuelve el número de caracteres escritos.

## Prototipo
```c
int ft_putchar(char c);
```

## Parámetros
- `c`: El carácter que se escribirá.

## Valor de retorno
- Devuelve el número de caracteres escritos (siempre 1 en caso de éxito).

## Descripción
La función utiliza la función autorizada `write` para escribir el carácter `c` en la salida estándar (stdout). Es útil para imprimir caracteres individuales.

## Ejemplo de uso
```c
#include <unistd.h>

int main(void)
{
    char ch = 'A';
    int count;

    count = ft_putchar(ch); // Escribe "A" en stdout y devuelve 1
    return 0;
}
```