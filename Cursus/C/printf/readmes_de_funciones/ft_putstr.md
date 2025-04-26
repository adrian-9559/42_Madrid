# ft_putstr
`ft_putstr` es una función que escribe una cadena de caracteres en la salida estándar y devuelve el número de caracteres escritos.

## Prototipo
```c
int ft_putstr(const char *str);
```

## Parámetros
- `str`: La cadena de caracteres que se escribirá.

## Valor de retorno
- Devuelve el número de caracteres escritos (la longitud de la cadena en caso de éxito).

## Descripción
La función utiliza la función autorizada `write` para escribir la cadena `str` en la salida estándar (stdout). Es útil para imprimir cadenas completas.

## Ejemplo de uso
```c
#include <unistd.h>

int main(void)
{
    const char *message = "Hola, mundo!";
    int count;

    count = ft_putstr(message); // Escribe "Hola, mundo!" en stdout y devuelve 12
    return 0;
}
```