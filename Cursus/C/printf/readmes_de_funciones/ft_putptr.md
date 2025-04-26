# ft_putptr
`ft_putptr` es una función que escribe la dirección de un puntero en formato hexadecimal en la salida estándar y devuelve el número de caracteres escritos.

## Prototipo
```c
int ft_putptr(const void *ptr);
```

## Parámetros
- `ptr`: El puntero cuya dirección se escribirá.

## Valor de retorno
- Devuelve el número de caracteres escritos (la longitud de la representación hexadecimal de la dirección en caso de éxito).

## Descripción
La función convierte la dirección del puntero `ptr` en una representación hexadecimal y la escribe en la salida estándar (stdout). Utiliza la función autorizada `write` para realizar la operación.

## Ejemplo de uso
```c
#include <unistd.h>

int main(void)
{
    int number = 42;
    int count;

    count = ft_putptr(&number); // Escribe la dirección de `number` en formato hexadecimal y devuelve el número de caracteres escritos
    return 0;
}
```