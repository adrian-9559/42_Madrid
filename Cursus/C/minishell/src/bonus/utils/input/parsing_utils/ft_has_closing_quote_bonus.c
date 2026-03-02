/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_closing_quote_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:25:00 by adriescr          #+#    #+#             */
/*   Updated: 2025/11/24 18:42:44 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell_bonus.h"

/**
 * ENGLISH: Checks if there is a closing quote of the specified type in the
 *          string.
 *
 * SPANISH: Verifica si hay una comilla de cierre del tipo especificado en la
 *          cadena.
 *
 * @param s      The input string. /
 *               La cadena de entrada.
 *
 * @param quote  The quote character to check for (either ' or "). /
 *               El carácter de comilla a verificar (ya sea ' o ").
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
