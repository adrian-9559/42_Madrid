/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auto <auto@local>                           +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 22:20:00 by auto              #+#    #+#             */
/*   Updated: 2025/11/16 22:20:00 by auto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

/**
 * ENGLISH: Skips over quoted segments and escaped characters in the command
 * string.
 * Updates the index to the position after the quoted/escaped segment.
 *
 * SPANISH: Salta sobre segmentos entre comillas y caracteres escapados en la
 * cadena de comando.
 * 	Actualiza el índice a la posición después del segmento entre
 * 	comillas/escapado.
 *
 * @param cmd The command string. /
 *            La cadena de comando.
 * @param i   Pointer to the current index in the command string. /
 *            Puntero al índice actual en la cadena de comando.
 * @param in_quote Pointer to a flag indicating if currently inside quotes. /
 *                 Puntero a una bandera que indica si se está dentro de
 * 					comillas.
 * @param quote_char Pointer to the current quote character (' or "). /
 *                   Puntero al carácter de comilla actual (' o ").
 */
void	ft_skip_quotes_and_escapes(const char *cmd, int *i, int *in_quote,
		char *quote_char)
{
	while (cmd[*i] && ((*in_quote) || (!ft_isspace(cmd[*i]) && cmd[*i] != '|'
				&& cmd[*i] != '<' && cmd[*i] != '>' && cmd[*i] != '&'
				&& cmd[*i] != '(' && cmd[*i] != ')')))
	{
		if (!(*in_quote) && (cmd[*i] == '\'' || cmd[*i] == '"'))
		{
			*in_quote = 1;
			*quote_char = cmd[*i];
			(*i)++;
		}
		else if (*in_quote && cmd[*i] == *quote_char)
		{
			*in_quote = 0;
			*quote_char = 0;
			(*i)++;
		}
		else if (cmd[*i] == '\\' && cmd[*i + 1])
			(*i) += 2;
		else
			(*i)++;
	}
}

static int	ft_handle_redir_op(const char *cmd, int *i, int escaped)
{
	if ((cmd[*i] == '<' || cmd[*i] == '>') && cmd[*i + 1] == cmd[*i]
		&& !escaped)
	{
		(*i) += 2;
		ft_skip_whitespace(cmd, i);
		return (1);
	}
	else if ((cmd[*i] == '<' || cmd[*i] == '>') && !escaped)
	{
		(*i)++;
		ft_skip_whitespace(cmd, i);
		return (1);
	}
	return (0);
}

/**
 * ENGLISH: Handles operators in the command string.
 * Updates the index to the position after the operator.
 *
 * SPANISH: Maneja los operadores en la cadena de comando.
 * 	Actualiza el índice a la posición después del operador.
 *
 * @param cmd The command string. /
 *            La cadena de comando.
 * @param i   Pointer to the current index in the command string. /
 *            Puntero al índice actual en la cadena de comando.
 * @returns   1 if an operator was handled, 0 otherwise. /
 *            1 si se manejó un operador, 0 en caso contrario.
 */
int	ft_handle_operator(const char *cmd, int *i)
{
	int	escaped;

	escaped = ft_is_escaped(cmd, *i);
	if (ft_handle_redir_op(cmd, i, escaped))
		return (1);
	if ((cmd[*i] == '|' || cmd[*i] == '&') && !escaped)
	{
		if (cmd[*i + 1] == cmd[*i] && !ft_is_escaped(cmd, *i + 1))
			(*i) += 2;
		else
			(*i)++;
		return (1);
	}
	if ((cmd[*i] == '(' || cmd[*i] == ')') && !escaped)
		return ((*i)++, 1);
	return (0);
}
