# ex00: ft_putchar

## Objetivo
Escribe una función llamada `ft_putchar` que imprima un solo carácter en la salida estándar.

## Especificaciones
- La función debe tener la siguiente firma:
    ```c
    void ft_putchar(char c);
    ```
- No se permite el uso de funciones de la biblioteca estándar como `printf` o `putchar`.

## Funciones autorizadas
- `write`: Esta función permite escribir datos directamente en un descriptor de archivo, como la salida estándar. Es fundamental para este ejercicio, ya que no se permite el uso de funciones de la biblioteca estándar como `printf` o `putchar`.

## Requisitos
1. Crea un archivo llamado `ft_putchar.c`.
2. Implementa la función `ft_putchar` en este archivo.
3. Asegúrate de que tu código respete la Norma y pase la `norminette`.

## Ejemplo
Si llamas a la función de la siguiente manera:
```c
ft_putchar('A');
```
La salida esperada será:
```
A
```

## Notas
- Este ejercicio es fundamental para entender cómo interactuar con la salida estándar en C.
- Asegúrate de probar tu función con diferentes caracteres para verificar su correcto funcionamiento.
- Recuerda que la precisión y el cumplimiento de las reglas son esenciales para evitar errores en la Moulinette.
- ¡Buena suerte!
