# ft_lstadd_back
`ft_lstadd_back` es una función que añade un nuevo nodo al final de una lista enlazada.

## Prototipo
```c
void ft_lstadd_back(t_list **lst, t_list *new);
```

## Parámetros
- `lst`: Un puntero al puntero del primer nodo de la lista.
- `new`: Un puntero al nodo que se añadirá al final de la lista.

## Valor de retorno
- Esta función no devuelve ningún valor.

## Descripción
La función toma un nodo nuevo y lo coloca al final de la lista enlazada. Si la lista está vacía, el nuevo nodo se convierte en el primer nodo de la lista.

## Ejemplo de uso
```c
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int main(void)
{
    t_list *head = NULL;
    t_list *new_node;

    new_node = ft_lstnew("Último nodo");
    if (!new_node)
    {
        perror("Error al asignar memoria");
        return 1;
    }

    ft_lstadd_back(&head, new_node);

    printf("Contenido del último nodo: '%s'\n", (char *)new_node->content);

    // Liberar memoria
    free(new_node);
    return 0;
}
```