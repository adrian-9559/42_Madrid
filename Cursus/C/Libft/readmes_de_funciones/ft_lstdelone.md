# ft_lstdelone
`ft_lstdelone` es una función que elimina un nodo de una lista enlazada y libera su contenido utilizando una función proporcionada por el usuario.

## Prototipo
```c
void ft_lstdelone(t_list *lst, void (*del)(void *));
```

## Parámetros
- `lst`: Un puntero al nodo que se eliminará.
- `del`: Un puntero a una función que se usará para liberar el contenido del nodo.

## Valor de retorno
- Esta función no devuelve ningún valor.

## Descripción
La función elimina el nodo especificado de la lista enlazada y utiliza la función `del` para liberar el contenido del nodo. No libera el nodo siguiente ni modifica la lista enlazada más allá del nodo especificado.

## Funciones autorizadas
- `free`: Se utiliza para liberar memoria dinámica previamente asignada. En `ft_lstdelone`, se emplea `free` para liberar el contenido del nodo eliminado.

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
    t_list *node;

    node = ft_lstnew(malloc(20));
    if (!node)
    {
        perror("Error al asignar memoria");
        return 1;
    }

    ft_lstdelone(node, del_content);

    printf("Nodo eliminado correctamente.\n");

    return 0;
}
```