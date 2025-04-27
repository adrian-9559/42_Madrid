# ex03: ft_print_numbers

## Objetivo
Escribe una función llamada `ft_print_numbers` que imprima todos los dígitos del 0 al 9 en orden ascendente, seguido de un salto de línea.

## Especificaciones
- La función debe tener la siguiente firma:
    ```c
    void ft_print_numbers(void);
    ```
- No se permite el uso de funciones de la biblioteca estándar como `printf` o `putchar`.

## Funciones autorizadas
- `write`: Esta función permite escribir datos directamente en un descriptor de archivo, como la salida estándar. Es fundamental para este ejercicio, ya que no se permite el uso de funciones de la biblioteca estándar como `printf` o `putchar`.

## Requisitos
1. Crea un archivo llamado `ft_print_numbers.c`.
2. Implementa la función `ft_print_numbers` en este archivo.
3. Asegúrate de que tu código respete la Norma y pase la `norminette`.

## Ejemplo
Si llamas a la función de la siguiente manera:
```c
ft_print_numbers();
```
La salida esperada será:
```
0123456789
```

## Notas
- Este ejercicio es importante para practicar el uso de bucles y la manipulación de caracteres en C.
- Asegúrate de probar tu función para verificar que imprime correctamente todos los dígitos.
- Recuerda que la precisión y el cumplimiento de las reglas son esenciales para evitar errores en la Moulinette.
- ¡Buena suerte!