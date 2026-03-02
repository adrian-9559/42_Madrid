/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:20:19 by adriescr          #+#    #+#             */
/*   Updated: 2025/11/16 14:38:29 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * ENGLISH: Counts a single word in the command string, considering quotes
 *          and escaped characters, and updates the index accordingly.
 *
 * SPANISH: Cuenta una sola palabra en la cadena de comando, considerando
 *          comillas y caracteres escapados, y actualiza el índice en
 *          consecuencia.
 *
 * @param cmd   The input command string. /
 *              La cadena de comando de entrada.
 *
 * @param i     Pointer to the current index in the command string. /
 *              Puntero al índice actual en la cadena de comando.
 *
 * @returns 1 if a word was counted, 0 otherwise. /
 *          1 si se contó una palabra, 0 en caso contrario.
 */
static int	count_word(const char *cmd, int *i)
{
	int		count;
	int		in_quote;
	char	quote_char;
	int		start;

	count = 0;
	in_quote = 0;
	quote_char = 0;
	start = *i;
	ft_skip_quotes_and_escapes(cmd, i, &in_quote, &quote_char);
	if (*i > start)
		count = 1;
	if (*i == start)
		(*i)++;
	return (count);
}

/**
 * ENGLISH: Counts the number of arguments in a command string,
 *          considering quotes, escaped characters, and operators.
 *
 * SPANISH: Cuenta el número de argumentos en una cadena de comando,
 *          considerando comillas, caracteres escapados y operadores.
 *
 * @param cmd   The input command string. /
 *              La cadena de comando de entrada.
 *
 * @returns The total count of arguments in the command string. /
 *          El conteo total de argumentos en la cadena de comando.
 */
int	ft_count_args(const char *cmd)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (cmd[i])
	{
		ft_skip_whitespace(cmd, &i);
		if (!cmd[i])
			break ;
		if (ft_handle_operator(cmd, &i))
			count++;
		else
			count += count_word(cmd, &i);
	}
	return (count);
}
