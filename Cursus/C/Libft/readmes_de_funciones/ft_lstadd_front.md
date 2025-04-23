# ft_lstadd_front
`ft_lstadd_front` es una función que añade un nuevo nodo al principio de una lista enlazada.

## Prototipo
```c
void ft_lstadd_front(t_list **lst, t_list *new);
```

## Parámetros
- `lst`: Un puntero al puntero del primer nodo de la lista.
- `new`: Un puntero al nodo que se añadirá al principio de la lista.

## Valor de retorno
- Esta función no devuelve ningún valor.

## Descripción
La función toma un nodo nuevo y lo coloca al principio de la lista enlazada, actualizando el puntero al primer nodo para que apunte al nuevo nodo.

## Ejemplo de uso
```c
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int main(void)
{
    t_list *head = NULL;
    t_list *new_node;

    new_node = ft_lstnew("Primer nodo");
    if (!new_node)
    {
        perror("Error al asignar memoria");
        return 1;
    }

    ft_lstadd_front(&head, new_node);

    printf("Contenido del primer nodo: '%s'\n", (char *)head->content);

    // Liberar memoria
    free(new_node);
    return 0;
}
```