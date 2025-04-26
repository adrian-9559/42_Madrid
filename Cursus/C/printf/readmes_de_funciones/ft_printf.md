# printf

`printf` es una función que imprime una salida formateada en la consola.

## Prototipo
```c
int printf(const char *format, ...);
```

## Parámetros
- `format`: Una cadena de formato que especifica cómo se deben formatear e imprimir los argumentos adicionales.
- `...`: Una lista variable de argumentos que se formatearán e imprimirán según la cadena de formato.

## Valor de retorno
- Devuelve el número total de caracteres impresos (excluyendo el carácter nulo final).
- Si ocurre un error, devuelve un valor negativo.

## Descripción
La función `printf` permite imprimir texto y valores formateados en la salida estándar. La cadena de formato puede contener texto literal y especificadores de formato que indican cómo se deben imprimir los argumentos.

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
#include <stdio.h>

int main(void)
{
    int entero = 42;
    float flotante = 3.14;
    char caracter = 'A';
    char cadena[] = "Hola, mundo";

    printf("Entero: %d\n", entero);
    printf("Carácter: %c\n", caracter);
    printf("Cadena: %s\n", cadena);

    return 0;
}
```

## Ejemplo de uso con `size_t`
```c
#include <stdio.h>

int main(void)
{
    size_t tamano = 1024;

    printf("Tamaño en bytes: %zu\n", tamano);

    return 0;
}
```