/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_strings_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 01:42:11 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/24 18:57:06 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

/**
 * ENGLISH: Sorts an array of strings in lexicographical order using bubble
 * sort.
 *
 * SPANISH: Ordena un arreglo de cadenas en orden lexicográfico usando
 *          el método de burbuja.
 *
 * @param arr   The array of strings to sort. /
 *              El arreglo de cadenas a ordenar.
 *
 * @param size  The number of strings in the array. /
 *              El número de cadenas en el arreglo.
 */
void	ft_sort_strings(char **arr, int size)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(arr[i], arr[j]) > 0)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}
