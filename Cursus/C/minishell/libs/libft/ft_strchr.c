/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:17:18 by adriescr          #+#    #+#             */
/*   Updated: 2025/11/24 15:26:44 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ENGLISH: Locates the first occurrence of a character in a string.
 *
 * SPANISH: Localiza la primera ocurrencia de un carácter en una cadena.
 *
 * @param str   The string to search. /
 *            La cadena a buscar.
 * @param c   The character to find. /
 *            El carácter a encontrar.
 *
 * @returns A pointer to the first occurrence of the character, or NULL
 * 			if not found. / Un puntero a la primera ocurrencia del carácter,
 * 			o NULL si no se encuentra.
 */
char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
