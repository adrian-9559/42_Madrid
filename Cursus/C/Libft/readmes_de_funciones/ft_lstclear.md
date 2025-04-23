# ft_lstclear
`ft_lstclear` es una función que elimina y libera todos los nodos de una lista enlazada, utilizando una función proporcionada por el usuario para liberar el contenido de cada nodo.

## Prototipo
```c
void ft_lstclear(t_list **lst, void (*del)(void *));
```

## Parámetros
- `lst`: Un puntero al puntero del primer nodo de la lista.
- `del`: Un puntero a una función que se usará para liberar el contenido de cada nodo.

## Valor de retorno
- Esta función no devuelve ningún valor.

## Descripción
La función elimina y libera todos los nodos de la lista enlazada, comenzando desde el primer nodo. Utiliza la función `del` para liberar el contenido de cada nodo y `free` para liberar la memoria del nodo en sí. Al finalizar, el puntero al primer nodo de la lista se establece en `NULL`.

## Funciones autorizadas
- `free`: Se utiliza para liberar memoria dinámica previamente asignada. En `ft_lstclear`, se emplea `free` para liberar cada nodo de la lista.

## Ejemplo de uso
```c
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void del_content(void *content)
{
    free(content);
}

int main(void)
{
    t_list *list;
    t_list *node1;
    t_list *node2;

    node1 = ft_lstnew(malloc(20));
    node2 = ft_lstnew(malloc(30));
    if (!node1 || !node2)
    {
        perror("Error al asignar memoria");
        return 1;
    }

    node1->next = node2;
    list = node1;

    ft_lstclear(&list, del_content);

    if (!list)
        printf("Lista eliminada correctamente.\n");

    return 0;
}
```