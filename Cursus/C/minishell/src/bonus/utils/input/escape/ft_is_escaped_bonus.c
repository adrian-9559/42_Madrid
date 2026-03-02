/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_escaped_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 20:29:49 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/24 18:42:24 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell_bonus.h"

/**
 * ENGLISH: Checks if the character at the given index in the string is escaped
 *          by a backslash.
 *
 * SPANISH: Verifica si el carácter en el índice dado en la cadena está
 *          escapado por una barra invertida.
 *
 * @param s     The input string. /
 *              La cadena de entrada.
 *
 * @param idx   The index of the character to check. /
 *              El índice del carácter a verificar.
 *
 * @returns 1 if the character is escaped, 0 otherwise. /
 *          1 si el carácter está escapado, 0 en caso contrario.
 */
int	ft_is_escaped(const char *s, int idx)
{
	int	count;

	count = 0;
	idx--;
	while (idx >= 0 && s[idx] == '\\')
	{
		count++;
		idx--;
	}
	return (count % 2 == 1);
}
