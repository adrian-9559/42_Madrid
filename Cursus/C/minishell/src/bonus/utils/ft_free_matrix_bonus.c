/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 18:00:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/09/12 20:07:23 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"

/**
 * ENGLISH: Frees a NULL-terminated array of strings.
 *
 * SPANISH: Libera un array de cadenas terminado en NULL.
 *
 * @param array   The array of strings to free. /
 *                El array de cadenas a liberar.
 */
void	ft_free_matrix(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/**
 * ENGLISH: Frees an array of strings with a given size.
 *
 * SPANISH: Libera un array de cadenas con un tamaño dado.
 *
 * @param array   The array of strings to free. /
 *                El array de cadenas a liberar.
 *
 * @param size    The number of elements in the array. /
 *                El número de elementos en el array.
 */
void	ft_free_matrix_size(char **array, int size)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (i < size)
	{
		if (array[i])
			free(array[i]);
		i++;
	}
	free(array);
}
