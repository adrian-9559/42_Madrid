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

#include "../../minishell.h"

/**
 * ENGLISH: Skips over quoted sections and escaped characters
 *          in the command string.
 *          It updates the index to point to the next relevant character.
 *
 * SPANISH: Omite las secciones entre comillas y los caracteres
 *          escapados en la cadena de comando.
 *          Actualiza el índice para apuntar al siguiente carácter relevante.
 *
 * @param cmd       The command string to parse. /
 *                  La cadena de comando a analizar.
 * @param i         Pointer to the current index in the command string. /
 *                  Puntero al índice actual en la cadena de comando.
 * @param in_quote  Pointer to a flag indicating if currently inside quotes. /
 *                  Puntero a una bandera que indica si se está dentro de
 *                  comillas.
 * @param quote_char Pointer to store the current quote character. /
 *                  Puntero para almacenar el carácter de comillas actual.
 */
void	ft_skip_quotes_and_escapes(const char *cmd, int *i, int *in_quote,
		char *quote_char)
{
	while (cmd[*i] && ((*in_quote) || (!ft_isspace(cmd[*i]) && cmd[*i] != '|'
				&& cmd[*i] != '<' && cmd[*i] != '>' && cmd[*i] != '&')))
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

/**
 * ENGLISH: Handles operators in the command string.
 *          It checks for redirection and pipe operators,
 *          updating the index accordingly.
 *
 * SPANISH: Maneja los operadores en la cadena de comando.
 *          Verifica los operadores de redirección y tubería,
 *          actualizando el índice en consecuencia.
 *
 * @param cmd The command string to parse. /
 *            La cadena de comando a analizar.
 * @param i   Pointer to the current index in the command string. /
 *            Puntero al índice actual en la cadena de comando.
 *
 * @returns 1 if an operator was handled, 0 otherwise. /
 *          1 si se manejó un operador, 0 en caso contrario.
 */
int	ft_handle_operator(const char *cmd, int *i)
{
	int	escaped;

	escaped = ft_is_escaped(cmd, *i);
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
	else if ((cmd[*i] == '|' || cmd[*i] == '&') && !escaped)
	{
		if (cmd[*i + 1] == cmd[*i] && !ft_is_escaped(cmd, *i + 1))
			(*i) += 2;
		else
			(*i)++;
		return (1);
	}
	return (0);
}
