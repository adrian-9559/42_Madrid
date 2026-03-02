/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expansion_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 10:00:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/24 17:41:10 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * ENGLISH: Copies a literal substring from the argument string to the
 *          destination string.
 *
 * SPANISH: Copia una subcadena literal de la cadena de argumentos a la
 *          cadena de destino.
 *
 * @param dst   Pointer to the destination string to append to. /
 *              Puntero a la cadena de destino donde se añadirá.
 *
 * @param arg   The argument string containing the literal substring. /
 *              La cadena de argumentos que contiene la subcadena literal.
 *
 * @param start The starting index of the substring in the argument string. /
 *              El índice inicial de la subcadena en la cadena de argumentos.
 *
 * @param end   The ending index (exclusive) of the substring in the
 *              argument string. /
 *              El índice final (exclusivo) de la subcadena en la cadena
 *              de argumentos.
 *
 * @returns SUCCESS (0) on success, ERROR (1) on memory allocation failure. /
 *          SUCCESS (0) en caso de éxito,
 *          ERROR (1) en caso de fallo de asignación de memoria.
 */
int	ft_copy_literal(char **dst, char *arg, int start, int end)
{
	char	*literal;
	char	*temp;

	if (end <= start)
		return (SUCCESS);
	literal = ft_substr(arg, start, end - start);
	if (!literal)
		return (ERROR);
	temp = *dst;
	*dst = ft_strjoin(temp, literal);
	free(temp);
	free(literal);
	if (!*dst)
		return (ERROR);
	return (SUCCESS);
}
