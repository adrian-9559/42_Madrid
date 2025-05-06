# ft_printf

`ft_printf` es una función personalizada que imprime una salida formateada en la consola, similar a la función estándar `printf`.

## Prototipo
```c
int ft_printf(const char *format, ...);
```

## Parámetros
- `format`: Una cadena de formato que especifica cómo se deben formatear e imprimir los argumentos adicionales.
- `...`: Una lista variable de argumentos que se formatearán e imprimirán según la cadena de formato.

## Valor de retorno
- Devuelve el número total de caracteres impresos.
- Si ocurre un error, devuelve un valor negativo.

## Descripción
La función `ft_printf` permite imprimir texto y valores formateados en la salida estándar. Implementa un comportamiento similar a `printf`, pero está diseñada desde cero. La cadena de formato puede contener texto literal y especificadores de formato que indican cómo se deben imprimir los argumentos.

### Especificadores de formato comunes:
- `%d` o `%i`: Entero con signo.
- `%u`: Entero sin signo.
- `%c`: Carácter.
- `%s`: Cadena de caracteres.
- `%p`: Dirección de puntero.
- `%x` o `%X`: Entero en formato hexadecimal.
- `%%`: Imprime un carácter `%`.

## Ejemplo de uso
```c
#include "ft_printf.h"

int main(void)
{
    int entero = 42;
    char caracter = 'A';
    char cadena[] = "Hola, mundo";

    ft_printf("Entero: %d\n", entero);
    ft_printf("Carácter: %c\n", caracter);
    ft_printf("Cadena: %s\n", cadena);

    return 0;
}
```

## Implementación básica
La función `ft_printf` utiliza una lista de argumentos variables (`va_list`) para procesar los valores proporcionados. Recorre la cadena de formato y, cuando encuentra un especificador (`%`), delega el manejo del formato a una función auxiliar como `handle_format`. Si no es un especificador, imprime el carácter directamente utilizando una función como `ft_putchar`.

```c
int ft_printf(const char *format, ...)
{
    va_list va;
    int count;

    count = 0;
    va_start(va, format);
    while (*format)
    {
        if (*format == '%' && *(format + 1))
        {
            format++;
            count += handle_format(&format, &va);
        }
        else
            count += ft_putchar(*format);
        format++;
    }
    va_end(va);
    return (count);
}
```
