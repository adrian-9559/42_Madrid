/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:06:49 by adriescr          #+#    #+#             */
/*   Updated: 2025/11/24 15:25:55 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ENGLISH: Counts the number of strings in a NULL-terminated array of
 * 			strings (matrix).
 *
 * SPANISH: Cuenta el número de cadenas en un array de cadenas terminado en
 * 			NULL (matriz).
 *
 * @param matrix The NULL-terminated array of strings. /
 *               El array de cadenas terminado en NULL.
 *
 * @returns The number of strings in the array. /
 *          El número de cadenas en el array.
 */
int	ft_matrix_size(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return (0);
	while (matrix[i])
		i++;
	return (i);
}
