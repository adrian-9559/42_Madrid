# ft_lstnew
`ft_lstnew` es una función que crea un nuevo nodo para una lista enlazada.

## Prototipo
```c
t_list *ft_lstnew(void *content);
```

## Parámetros
- `content`: El contenido que se almacenará en el nuevo nodo.

## Valor de retorno
- Devuelve un puntero al nuevo nodo.
- Si la asignación falla, devuelve `NULL`.

## Descripción
La función asigna memoria para un nuevo nodo de una lista enlazada. El miembro `content` del nodo se inicializa con el valor del parámetro `content`, y el miembro `next` se inicializa a `NULL`.

## Funciones autorizadas
- `malloc`: Se utiliza para asignar memoria dinámica. En `ft_lstnew`, se emplea `malloc` para reservar espacio para el nuevo nodo.

## Ejemplo de uso
```c
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int main(void)
{
    char *content = "Hola, mundo";
    t_list *node;

    node = ft_lstnew(content);
    if (!node)
    {
        perror("Error al asignar memoria");
        return 1;
    }

    printf("Contenido del nodo: '%s'\n", (char *)node->content);

    free(node);
    return 0;
}
```