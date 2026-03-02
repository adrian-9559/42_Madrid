/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize_path_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:44:59 by adriescr          #+#    #+#             */
/*   Updated: 2025/11/24 18:32:46 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

/**
 * ENGLISH: Builds a stack of valid path components from the given parts,
 *          handling "." and ".." appropriately.
 *
 * SPANISH: Construye una pila de componentes de ruta válidos a partir de
 *          las partes dadas, manejando "." y ".." adecuadamente.
 *
 * @param parts  The array of path components split by '/'. /
 *               El arreglo de componentes de ruta dividido por '/'.
 * @param stack  The stack to store valid path components. /
 *               La pila para almacenar componentes de ruta válidos.
 *
 * @return The number of valid components in the stack. /
 * 		El número de componentes válidos en la pila.
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
 * ENGLISH: Builds a normalized path string from the stack of valid components.
 *
 * SPANISH: Construye una cadena de ruta normalizada a partir de la pila
 *          de componentes válidos.
 *
 * @param stack  The stack of valid path components. /
 *               La pila de componentes de ruta válidos.
 * @param top    The number of valid components in the stack. /
 *               El número de componentes válidos en la pila.
 *
 * @return A dynamically allocated normalized path string. /
 * 		Una cadena de ruta normalizada asignada dinámicamente.
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
 * 			Consecutive slashes are treated as a single slash.
 * 			The resulting path is absolute, starting with a '/'.
 *
 * SPANISH: Normaliza una ruta de archivo dada resolviendo los componentes
 * 			"." y "..". Las barras diagonales consecutivas se tratan como una
 * 			sola barra diagonal. La ruta resultante es absoluta, comenzando
 * 			con una '/'.
 *
 * @param path  The input file path to normalize. /
 *              La ruta de archivo de entrada a normalizar.
 *
 * @return A dynamically allocated normalized path string, or NULL on error. /
 * 		Una cadena de ruta normalizada asignada dinámicamente, o NULL en caso
 * 		de error.
 */
char	*ft_normalize_path(const char *path)
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
