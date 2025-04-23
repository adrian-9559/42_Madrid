# ft_lstiter
`ft_lstiter` es una función que aplica una función dada a cada elemento de una lista enlazada.

## Prototipo
```c
void ft_lstiter(t_list *lst, void (*f)(void *));
```

## Parámetros
- `lst`: Un puntero al primer nodo de la lista.
- `f`: Un puntero a la función que se aplicará a cada contenido de los nodos.

## Valor de retorno
- Ninguno.

## Descripción
La función recorre la lista enlazada y aplica la función `f` al contenido de cada nodo.

## Ejemplo de uso
```c
#include <stdio.h>
#include "libft.h"

void print_content(void *content)
{
    printf("%s\n", (char *)content);
}

int main(void)
{
    t_list *node1 = ft_lstnew("Nodo 1");
    t_list *node2 = ft_lstnew("Nodo 2");
    t_list *node3 = ft_lstnew("Nodo 3");

    node1->next = node2;
    node2->next = node3;

    ft_lstiter(node1, print_content);

    ft_lstclear(&node1, free);
    return 0;
}
```