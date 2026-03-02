/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:14:50 by adriescr          #+#    #+#             */
/*   Updated: 2025/11/24 15:29:02 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ENGLISH: Duplicates a string.
 *
 * SPANISH: Duplica una cadena.
 *
 * @param str   The string to duplicate. /
 *            La cadena a duplicar.
 *
 * @returns A pointer to the duplicated string, or NULL on failure. /
 *          Un puntero a la cadena duplicada, o NULL en caso de error.
 */
char	*ft_strdup(const char *str)
{
	char	*dup;
	size_t	i;

	if (!str)
		return (NULL);
	dup = malloc(ft_strlen(str) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
