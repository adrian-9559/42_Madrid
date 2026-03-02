/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:56:05 by adriescr          #+#    #+#             */
/*   Updated: 2025/11/24 17:17:46 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ENGLISH: Helper function to copy a string into a destination buffer.
 * 		It advances the position index accordingly.
 *
 * SPANISH: Función auxiliar para copiar una cadena en un búfer de destino.
 * 		Avanza el índice de posición en consecuencia.
 *
 * @param dst   The destination buffer. /
 *              El búfer de destino.
 * @param src   The source string. /
 *              La cadena fuente.
 * @param pos   Pointer to the current position index in the destination buffer.
 *              / Puntero al índice de posición actual en el búfer de destino.
 */
static void	copy_and_advance(char *dst, const char *src, size_t *pos)
{
	size_t	i;

	if (!src)
		return ;
	i = 0;
	while (src[i])
		dst[(*pos)++] = src[i++];
}

/**
 * ENGLISH: Joins two strings into a new string.
 *
 * SPANISH: Une dos cadenas en una nueva cadena.
 *
 * @param str1  The first string. /
 *				La primera cadena.
 * @param str2  The second string. /
 *				La segunda cadena.
 *
 * @returns A pointer to the newly allocated joined string, or NULL on failure.
 *          / Un puntero a la nueva cadena unida asignada dinámicamente,
 *          o NULL en caso de error.
 */
char	*ft_strjoin(char *str1, char *str2)
{
	char	*new_str;
	size_t	i;
	size_t	len1;
	size_t	len2;

	if (!str2)
		return (str1);
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	new_str = malloc(len1 + len2 + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	copy_and_advance(new_str, str1, &i);
	copy_and_advance(new_str, str2, &i);
	new_str[i] = '\0';
	return (new_str);
}
