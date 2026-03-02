/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 00:51:17 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/17 23:14:50 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

/**
 * ENGLISH: Appends the source string to the destination string,
 *          reallocating memory as necessary.
 *
 * SPANISH: Añade la cadena de origen a la cadena de destino,
 *          realojando memoria según sea necesario.
 *
 * @param dst   Pointer to the destination string to append to. /
 *              Puntero a la cadena de destino donde se añadirá.
 *
 * @param src   The source string to append. /
 *              La cadena de origen que se añadirá.
 *
 * @returns 1 on success, 0 on memory allocation failure. /
 *          1 en caso de éxito, 0 en caso de fallo de asignación de memoria.
 */
int	ft_append(char **dst, const char *src)
{
	char	*temp;

	if (!dst || !src)
		return (ERROR);
	temp = *dst;
	*dst = ft_strjoin(temp, (char *)src);
	free(temp);
	if (!*dst)
		return (ERROR);
	return (SUCCESS);
}
