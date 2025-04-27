# ex07: ft_putnbr

## Objetivo
Escribe una función llamada `ft_putnbr` que imprima un número entero en la salida estándar.

## Especificaciones
- La función debe tener la siguiente firma:
    ```c
    void ft_putnbr(int nb);
    ```
- La función debe manejar números negativos.
- No se permite el uso de funciones de la biblioteca estándar como `printf` o `itoa`.

## Funciones autorizadas
- `write`: Esta función permite escribir datos directamente en un descriptor de archivo, como la salida estándar. Es fundamental para este ejercicio.

## Requisitos
1. Crea un archivo llamado `ft_putnbr.c`.
2. Implementa la función `ft_putnbr` en este archivo.
3. Asegúrate de que tu código respete la Norma y pase la `norminette`.

## Ejemplo
Si llamas a la función de la siguiente manera:
```c
ft_putnbr(42);
ft_putnbr(-123);
ft_putnbr(0);
```
La salida esperada será:
```
42-1230
```

## Notas
- Este ejercicio es importante para practicar el manejo de números y la conversión de enteros a caracteres en C.
- Asegúrate de que la salida sea exactamente como se especifica, sin espacios adicionales ni saltos de línea.
- Recuerda que la precisión y el cumplimiento de las reglas son esenciales para evitar errores en la Moulinette.
- ¡Buena suerte!