/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:55:54 by adriescr          #+#    #+#             */
/*   Updated: 2025/09/04 18:54:29 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ENGLISH: Copies the string pointed to by src (including 
 * 			the terminating null byte) to the buffer pointed to by dest.
 *
 * SPANISH: Copia la cadena apuntada por src (incluyendo
 * 			el byte nulo de terminación) al búfer apuntado por dest.
 *
 * @param dest   Pointer to the destination buffer.
 *               Puntero al búfer de destino.
 * @param src    Pointer to the source string.
 *               Puntero a la cadena fuente.
 *
 * @returns A pointer to the destination string dest.
 *          Un puntero a la cadena de destino dest.
 */
char	*ft_strcpy(char *dest, const char *src)
{
	char	*ptr;

	ptr = dest;
	while (*src)
		*ptr++ = *src++;
	*ptr = '\0';
	return (dest);
}
