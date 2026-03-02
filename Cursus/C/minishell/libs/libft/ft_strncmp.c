/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 18:35:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/24 15:37:23 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ENGLISH: Compares up to n characters of the null-terminated strings str1
 *          and str2.
 *
 * SPANISH: Compara hasta n caracteres de las cadenas terminadas en nulo str1
 *          y str2.
 *
 * @param str1   The first string to compare. /
 *              La primera cadena a comparar.
 *
 * @param str2   The second string to compare. /
 *              La segunda cadena a comparar.
 *
 * @param n    The maximum number of characters to compare. /
 *              El número máximo de caracteres a comparar.
 *
 * @returns An integer less than, equal to, or greater than zero if str1 (or the
 *          first n bytes thereof) is found, respectively, to be less than,
 *          to match, or be greater than str2. /
 *          Un entero menor que, igual a,
	o mayor que cero si str1 (o los primeros
 *          n bytes de la misma) es encontrado, respectivamente, como menor que,
 *          igual a, o mayor que str2.
 * @returns The comparison is done using unsigned characters. /
 *          La comparación se hace usando caracteres sin signo.
 */
int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n && str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
