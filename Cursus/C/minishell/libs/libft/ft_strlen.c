/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:39:52 by adriescr          #+#    #+#             */
/*   Updated: 2025/11/24 15:36:36 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ENGLISH: Calculates the length of a string.
 *
 * SPANISH: Calcula la longitud de una cadena.
 *
 * @param str   The string to measure. /
 *            La cadena a medir.
 *
 * @returns The length of the string. /
 *          La longitud de la cadena.
 */
size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
