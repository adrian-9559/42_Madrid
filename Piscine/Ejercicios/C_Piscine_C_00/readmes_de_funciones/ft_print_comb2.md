# ex06: ft_print_comb2

## Objetivo
Escribe una función llamada `ft_print_comb2` que imprima todas las combinaciones posibles de dos números de dos dígitos en orden ascendente, separados por comas y espacios.

## Especificaciones
- La función debe tener la siguiente firma:
    ```c
    void ft_print_comb2(void);
    ```
- Cada combinación debe estar formada por dos números diferentes.
- Los números deben imprimirse en orden ascendente, es decir, el primer número siempre debe ser menor que el segundo.
- Las combinaciones deben estar separadas por `, `, excepto la última.

## Funciones autorizadas
- `write`: Esta función permite escribir datos directamente en un descriptor de archivo, como la salida estándar. Es fundamental para este ejercicio, ya que no se permite el uso de funciones de la biblioteca estándar como `printf` o `putchar`.

## Requisitos
1. Crea un archivo llamado `ft_print_comb2.c`.
2. Implementa la función `ft_print_comb2` en este archivo.
3. Asegúrate de que tu código respete la Norma y pase la `norminette`.

## Ejemplo
Si llamas a la función de la siguiente manera:
```c
ft_print_comb2();
```
La salida esperada será:
```
00 01, 00 02, ..., 98 99
```

## Notas
- Este ejercicio es importante para practicar el uso de bucles anidados y la generación de combinaciones en C.
- Asegúrate de que la salida sea exactamente como se especifica, incluyendo los espacios y las comas.
- Recuerda que la precisión y el cumplimiento de las reglas son esenciales para evitar errores en la Moulinette.
- ¡Buena suerte!