# ft_lstsize
`ft_lstsize` es una función que cuenta el número de nodos en una lista enlazada.

## Prototipo
```c
int ft_lstsize(t_list *lst);
```

## Parámetros
- `lst`: Un puntero al primer nodo de la lista enlazada.

## Valor de retorno
- Devuelve el número de nodos en la lista.

## Descripción
La función recorre la lista enlazada comenzando desde el nodo apuntado por `lst` y cuenta cuántos nodos existen hasta llegar al final de la lista (`NULL`).

## Ejemplo de uso
```c
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int main(void)
{
    t_list *node1 = ft_lstnew("Nodo 1");
    t_list *node2 = ft_lstnew("Nodo 2");
    t_list *node3 = ft_lstnew("Nodo 3");

    if (!node1 || !node2 || !node3)
    {
        perror("Error al asignar memoria");
        return 1;
    }

    node1->next = node2;
    node2->next = node3;

    printf("Tamaño de la lista: %d\n", ft_lstsize(node1));

    free(node3);
    free(node2);
    free(node1);
    return 0;
}
```