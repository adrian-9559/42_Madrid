/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:23:07 by adriescr          #+#    #+#             */
/*   Updated: 2025/11/24 15:21:46 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ENGLISH: Counts the number of words in a string,
 * 			separated by a given delimiter.
 *
 * SPANISH: Cuenta el número de palabras en una cadena,
 * 			separadas por un delimitador dado.
 *
 * @param str   The string to count words in. /
 *            La cadena en la que contar las palabras.
 *
 * @param c   The delimiter character. /
 *            El carácter delimitador.
 *
 * @returns The number of words in the string. /
 *          El número de palabras en la cadena.
 */
size_t	ft_count_words(const char *str, char c)
{
	size_t	count;
	int		i;

	if (!str)
		return (0);
	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}
