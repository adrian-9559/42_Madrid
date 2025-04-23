# ft_lstmap
`ft_lstmap` es una función que itera sobre una lista enlazada y aplica una función proporcionada por el usuario a cada contenido de los nodos, creando una nueva lista con los resultados.

## Prototipo
```c
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
```

## Parámetros
- `lst`: Un puntero al primer nodo de la lista.
- `f`: Un puntero a una función que se aplicará al contenido de cada nodo.
- `del`: Un puntero a una función que se usará para liberar el contenido de un nodo en caso de error.

## Valor de retorno
- Un puntero al primer nodo de la nueva lista, o `NULL` si ocurre un error.

## Descripción
La función crea una nueva lista enlazada aplicando la función `f` al contenido de cada nodo de la lista original. Si ocurre un error al asignar memoria para un nuevo nodo, se utiliza la función `del` para liberar la memoria de los nodos ya creados y se devuelve `NULL`.

## Funciones autorizadas
- `malloc`: Se utiliza para asignar memoria dinámica para los nuevos nodos de la lista.
- `free`: Se utiliza para liberar memoria dinámica en caso de error.

## Ejemplo de uso
```c
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void *duplicate_content(void *content)
{
    void *new_content = malloc(20); // Ejemplo de tamaño
    if (!new_content)
        return NULL;
    // Copiar contenido (esto depende del tipo de datos)
    return new_content;
}

void del_content(void *content)
{
    free(content);
}

int main(void)
{
    t_list *list;
    t_list *node1;
    t_list *node2;
    t_list *new_list;

    node1 = ft_lstnew(malloc(20));
    node2 = ft_lstnew(malloc(30));
    if (!node1 || !node2)
    {
        perror("Error al asignar memoria");
        return 1;
    }

    node1->next = node2;
    list = node1;

    new_list = ft_lstmap(list, duplicate_content, del_content);

    if (new_list)
        printf("Nueva lista creada correctamente.\n");

    // Liberar ambas listas
    ft_lstclear(&list, del_content);
    ft_lstclear(&new_list, del_content);

    return 0;
}
```