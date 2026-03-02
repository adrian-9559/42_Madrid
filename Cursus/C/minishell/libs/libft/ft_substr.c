/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:15:59 by adriescr          #+#    #+#             */
/*   Updated: 2025/11/24 15:38:38 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ENGLISH: Extracts a substring from a string.
 *
 * SPANISH: Extrae una subcadena de una cadena.
 *
 * @param str       The original string. /
 *                La cadena original.
 * @param start   The starting index of the substring. /
 *                El índice de inicio de la subcadena.
 * @param len     The length of the substring. /
 *                La longitud de la subcadena.
 *
 * @returns A pointer to the new substring, or NULL on failure. /
 *          Un puntero a la nueva subcadena, o NULL en caso de error.
 */
char	*ft_substr(char *str, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!str || start >= ft_strlen(str))
		return (ft_strdup(""));
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && str[start + i])
	{
		sub[i] = str[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
