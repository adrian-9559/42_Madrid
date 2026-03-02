/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:44:59 by adriescr          #+#    #+#             */
/*   Updated: 2025/11/24 18:15:00 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * ENGLISH: Builds a stack of valid path components from the split parts,
 * 			handling "." and "..".
 *
 * SPANISH: Construye una pila de componentes de ruta válidos a partir
 * 			de las partes divididas, manejando "." y "..".
 *
 * @param parts  The split path components. /
 * 				Los componentes de ruta divididos.
 * @param stack  The stack to build the valid components into. /
 * 			La pila para construir los componentes válidos.
 *
 * @returns The number of valid components in the stack. /
 * 			El número de componentes válidos en la pila.
 */
static int	ft_build_stack(char **parts, char **stack)
{
	int	i[2];

	i[0] = 0;
	i[1] = 0;
	while (parts[i[0]])
	{
		if (ft_strcmp(parts[i[0]], ".") == 0)
		{
			i[0]++;
			continue ;
		}
		else if (ft_strcmp(parts[i[0]], "..") == 0)
		{
			if (i[1] > 0)
			{
				free(stack[i[1] - 1]);
				i[1]--;
			}
		}
		else
			stack[i[1]++] = ft_strdup(parts[i[0]]);
		i[0]++;
	}
	return (i[1]);
}

/**
 * ENGLISH: Builds the normalized path string from the stack of valid
 * 			components.
 *
 * SPANISH: Construye la cadena de ruta normalizada a partir de la pila
 * 			de componentes válidos.
 *
 * @param stack  The stack of valid path components. /
 * 				La pila de componentes de ruta válidos.
 * @param top    The number of valid components in the stack. /
 * 				El número de componentes válidos en la pila.
 *
 * @returns The normalized path as a string. /
 * 			La ruta normalizada como cadena.
 */
static char	*build_path_from_stack(char **stack, int top)
{
	char	*res;
	char	*tmp;
	int		i;

	if (top == 0)
		return (ft_strdup("/"));
	res = ft_strdup("");
	i = 0;
	while (i < top)
	{
		tmp = ft_strjoin(res, "/");
		free(res);
		res = ft_strjoin(tmp, stack[i]);
		free(tmp);
		i++;
	}
	return (res);
}

/**
 * ENGLISH: Normalizes a given file path by resolving "." and ".." components.
 *
 * SPANISH: Normaliza una ruta de archivo dada resolviendo los componentes
 * 			"." y "..".
 *
 * @param path  The input file path to normalize. /
 * 				La ruta de archivo de entrada a normalizar.
 *
 * @returns The normalized file path as a string. /
 * 			La ruta de archivo normalizada como cadena.
 */
char	*ft_normalize_path(char *path)
{
	char	**parts;
	char	**stack;
	char	*res;
	int		top;

	if (!path)
		return (NULL);
	parts = ft_split(path, '/');
	if (!parts)
		return (ft_strdup("/"));
	stack = malloc(sizeof(char *) * (ft_matrix_size(parts) + 1));
	if (!stack)
		return (ft_free_matrix(parts), ft_strdup("/"));
	top = ft_build_stack(parts, stack);
	res = build_path_from_stack(stack, top);
	while (top > 0)
	{
		free(stack[top - 1]);
		top--;
	}
	free(stack);
	ft_free_matrix(parts);
	return (res);
}
