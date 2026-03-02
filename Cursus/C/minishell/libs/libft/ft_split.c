/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:25:36 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/24 19:01:24 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_result(char **result, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

static char	**split_input(char **result, char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			k = i;
			while (s[i] && s[i] != c)
				i++;
			result[j] = ft_substr(s, k, i - k);
			if (!result[j++])
			{
				free_result(result, j - 1);
				return (NULL);
			}
		}
		else
			i++;
	}
	result[j] = NULL;
	return (result);
}

/**
 * ENGLISH: Splits the input string into an array of substrings based on the
 *          specified delimiter character.
 *
 * SPANISH: Divide la cadena de entrada en un arreglo de subcadenas
 *          basado en el carácter delimitador especificado.
 *
 * @param s The input string to be split. /
 *          La cadena de entrada a dividir.
 * @param c The delimiter character used to split the string. /
 *          El carácter delimitador utilizado para dividir la cadena.
 *
 * @returns An array of substrings, or NULL on memory allocation failure. /
 *          Un arreglo de subcadenas, o NULL en caso de fallo de asignación de
 *          memoria.
 */
char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!result)
		return (NULL);
	return (split_input(result, (char *)s, c));
}
