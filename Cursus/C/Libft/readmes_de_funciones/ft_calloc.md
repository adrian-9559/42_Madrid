# ft_calloc
`ft_calloc` es una función que asigna memoria para un array y la inicializa a cero.

## Prototipo
```c
void *ft_calloc(size_t count, size_t size);
```

## Parámetros
- `count`: Número de elementos a asignar.
- `size`: Tamaño en bytes de cada elemento.

## Valor de retorno
- Devuelve un puntero al bloque de memoria asignado e inicializado a cero.
- Si la asignación falla, devuelve `NULL`.

## Descripción
La función asigna memoria suficiente para un array de `count` elementos, cada uno de `size` bytes, y establece todos los bytes a cero. Es útil para inicializar estructuras de datos dinámicas.

## Funciones autorizadas
- `malloc`: Se utiliza para asignar memoria dinámica. En `ft_calloc`, se emplea `malloc` para reservar suficiente espacio en memoria para el array solicitado.

## Ejemplo de uso
```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *arr;
    size_t n = 5;

    arr = (int *)ft_calloc(n, sizeof(int));
    if (!arr)
    {
        perror("Error al asignar memoria");
        return 1;
    }

    for (size_t i = 0; i < n; i++)
        printf("arr[%zu] = %d\n", i, arr[i]);

    free(arr);
    return 0;
}
```