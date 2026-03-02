/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_closing_quote.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:25:00 by adriescr          #+#    #+#             */
/*   Updated: 2025/11/24 17:55:17 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

/**
 * ENGLISH: Checks if the given quote character has a closing quote in the
 * 			string.
 *
 * SPANISH: Verifica si el carácter de comillas dado tiene una comilla de
 * 			cierre en la cadena.
 *
 * @param s    The input string. /
 *             La cadena de entrada.
 * @param quote The quote character to check. /
 *              El carácter de comillas a verificar.
 *
 * @returns 1 if a closing quote is found, 0 otherwise. /
 *          1 si se encuentra una comilla de cierre, 0 en caso contrario.
 */
int	ft_has_closing_quote(const char *s, char quote)
{
	while (*s)
	{
		if (*s == quote)
			return (1);
		s++;
	}
	return (0);
}
