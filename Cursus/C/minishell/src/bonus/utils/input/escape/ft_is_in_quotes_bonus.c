/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auto <auto@local>                           +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 22:00:00 by auto              #+#    #+#             */
/*   Updated: 2025/11/16 22:00:00 by auto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell_bonus.h"

/**
 * ENGLISH: Checks if the character at the given position in the input string
 *          is inside quotes (single or double).
 *
 * SPANISH: Verifica si el carácter en la posición dada en la cadena de
 *          entrada está dentro de comillas (simples o dobles).
 *
 * @param input The input string. /
 *              La cadena de entrada.
 *
 * @param pos   The position of the character to check. /
 *              La posición del carácter a verificar.
 *
 * @returns 1 if the character is inside quotes, 0 otherwise. /
 *          1 si el carácter está dentro de comillas, 0 en caso contrario.
 */
int	ft_is_in_quotes(const char *input, int pos)
{
	int		i;
	int		in_q;
	char	q;

	i = 0;
	in_q = 0;
	q = 0;
	while (i <= pos && input[i])
	{
		if (!in_q && (input[i] == '\'' || input[i] == '"'))
		{
			in_q = 1;
			q = input[i];
		}
		else if (in_q && input[i] == q)
		{
			in_q = 0;
			q = 0;
		}
		i++;
	}
	return (in_q);
}
