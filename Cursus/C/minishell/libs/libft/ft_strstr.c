/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:48:08 by adriescr          #+#    #+#             */
/*   Updated: 2025/09/04 18:55:31 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ENGLISH: Locates the first occurrence of a substring in a string.
 *
 * SPANISH: Localiza la primera aparición de una subcadena en una cadena.
 *
 * @param haystack   The string to be searched.
 *                   La cadena donde se busca.
 * @param needle     The substring to find.
 *                   La subcadena a encontrar.
 *
 * @returns A pointer to the first occurrence of needle in haystack, 
 * 			or NULL if not found.
 *          Un puntero a la primera aparición de needle en haystack, 
 * 			o NULL si no se encuentra.
 */
char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (!needle[j + 1])
				return ((char *)&haystack[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
