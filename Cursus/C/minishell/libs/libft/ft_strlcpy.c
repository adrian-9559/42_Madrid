/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 22:00:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/09/22 12:54:31 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ENGLISH: Copies up to size - 1 characters from the null-terminated string
 *          src to dst, null-terminating the result.
 *
 * SPANISH: Copia hasta size - 1 caracteres de la cadena terminada en nulo
 *          src a dst, terminando el resultado en nulo.
 *
 * @param dst   The destination buffer where the content is to be copied. /
 *              El búfer de destino donde se copiará el contenido.
 *
 * @param src   The source string to copy from. /
 *              La cadena fuente desde la que se copiará.
 *
 * @param size  The size of the destination buffer. /
 *              El tamaño del búfer de destino.
 *
 * @returns The total length of the string it tried to create,
 *          that is, the length of src. /
 *          La longitud total de la cadena que intentó crear,
 *          es decir, la longitud de src.
 * @returns If the return value is >= size, the output string has been
 *          truncated. /
 *          Si el valor de retorno es >= size, la cadena de salida ha sido
 *          truncada.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	if (!src)
		return (0);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
