/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:30:08 by adriescr          #+#    #+#             */
/*   Updated: 2025/11/24 15:28:23 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ENGLISH: Compares two strings.
 *
 * SPANISH: Compara dos cadenas.
 *
 * @param str1   The first string. /
 *              La primera cadena.
 * @param str2   The second string. /
 *              La segunda cadena.
 *
 * @returns 0 if equal, negative if str1 < str2, positive if str1 > str2. /
 *          0 si son iguales, negativo si str1 < str2, positivo si str1 > str2.
 */
int	ft_strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return ((unsigned char)*str1 - (unsigned char)*str2);
}
