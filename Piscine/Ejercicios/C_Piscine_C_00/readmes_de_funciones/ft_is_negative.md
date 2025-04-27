# ex04: ft_is_negative

## Objetivo
Escribe una función llamada `ft_is_negative` que determine si un número entero es negativo o no, e imprima un carácter correspondiente.

## Especificaciones
- La función debe tener la siguiente firma:
    ```c
    void ft_is_negative(int n);
    ```
- Si el número es negativo, la función debe imprimir `N`. Si es positivo o cero, debe imprimir `P`.

## Funciones autorizadas
- `write`: Esta función permite escribir datos directamente en un descriptor de archivo, como la salida estándar. Es fundamental para este ejercicio, ya que no se permite el uso de funciones de la biblioteca estándar como `printf` o `putchar`.

## Requisitos
1. Crea un archivo llamado `ft_is_negative.c`.
2. Implementa la función `ft_is_negative` en este archivo.
3. Asegúrate de que tu código respete la Norma y pase la `norminette`.

## Ejemplo
Si llamas a la función de la siguiente manera:
```c
ft_is_negative(-5);
ft_is_negative(0);
ft_is_negative(42);
```
La salida esperada será:
```
NPP
```

## Notas
- Este ejercicio es importante para practicar el uso de condicionales y la manipulación de caracteres en C.
- Asegúrate de probar tu función para verificar que imprime correctamente el carácter esperado.
- Recuerda que la precisión y el cumplimiento de las reglas son esenciales para evitar errores en la Moulinette.
- ¡Buena suerte!