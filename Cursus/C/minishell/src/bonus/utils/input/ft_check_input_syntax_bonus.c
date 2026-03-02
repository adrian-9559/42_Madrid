/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input_syntax_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 17:25:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/12/03 01:06:21 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

/**
 * ENGLISH: Checks if the given string is a redirection operator.
 *
 * SPANISH: Verifica si la cadena dada es un operador de redirección.
 *
 * @param s   The string to check. /
 *            La cadena a verificar.
 *
 * @returns 1 if the string is a redirection operator, 0 otherwise. /
 *          1 si la cadena es un operador de redirección, 0 en caso contrario.
 */
static int	ft_is_redir(const char *s)
{
	if (!s)
		return (0);
	return (ft_strcmp(s, "<") == 0 || ft_strcmp(s, ">") == 0 || ft_strcmp(s,
			">>") == 0 || ft_strcmp(s, "<<") == 0);
}

/**
 * ENGLISH: Checks if the given string is a logical operator (|| or &&).
 *
 * SPANISH: Verifica si la cadena dada es un operador lógico (|| o &&).
 *
 * @param s   The string to check. /
 *            La cadena a verificar.
 *
 * @returns 1 if the string is a logical operator, 0 otherwise. /
 *          1 si la cadena es un operador lógico, 0 en caso contrario.
 */
static int	ft_is_logical_op(const char *s)
{
	if (!s)
		return (0);
	return (ft_strcmp(s, "||") == 0 || ft_strcmp(s, "&&") == 0);
}

/**
 * ENGLISH: Checks if the given string is a pipe or
 * logical operator (|, ||, &&, &).
 *
 * SPANISH: Verifica si la cadena dada es un
 * operador de tubería o lógico (|, ||, &&, &).
 *
 * @param s   The string to check. /
 *            La cadena a verificar.
 *
 * @returns 1 if the string is a pipe or logical
 * operator, 0 otherwise. / 1 si la cadena
 * es un operador de tubería o lógico,
 * 0 en caso contrario.
 */
static int	ft_is_pipe_like(const char *s)
{
	if (!s)
		return (0);
	return (ft_strcmp(s, "|") == 0 || ft_is_logical_op(s) || ft_strcmp(s,
			"&") == 0);
}

/**
 * ENGLISH: Checks for syntax errors in the command arguments.
 *          It checks for invalid placements of pipes, redirections,
 *          and logical operators.
 *
 * SPANISH: Verifica errores de sintaxis en los argumentos del comando.
 *          Verifica colocaciones inválidas de tuberías,
 *          redirecciones y operadores lógicos.
 *
 * @param argv  The array of command arguments. /
 *              El arreglo de argumentos del comando.
 *
 * @param argc  The number of command arguments. /
 *              El número de argumentos del comando.
 *
 * @returns 0 if no syntax errors are found,
 *          or an error code if a syntax error is detected. /
 *          0 si no se encuentran errores de sintaxis,
 *          o un código de error si se detecta un error de sintaxis.
 */
static int	ft_check_parentheses(char **argv, int argc)
{
	int	i;
	int	balance;

	i = 0;
	balance = 0;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "("))
			balance++;
		else if (!ft_strcmp(argv[i], ")"))
		{
			balance--;
			if (balance < 0)
				return (ft_handle_error(6, 2, ")", NULL));
		}
		i++;
	}
	if (balance != 0)
		return (ft_handle_error(6, 2, "(", NULL));
	return (0);
}

int	ft_check_input_syntax(char **argv, int argc)
{
	int	i;

	if (!argv || argc == 0)
		return (0);
	if (!ft_strcmp(argv[0], "|") || !ft_strcmp(argv[0], "&")
		|| ft_is_logical_op(argv[0]) || !ft_strcmp(argv[0], ")"))
	{
		return (ft_handle_error(6, 2, argv[0], NULL));
	}
	i = -1;
	while (++i < argc)
	{
		if ((ft_is_pipe_like(argv[i]) || ft_is_redir(argv[i])) && i == argc - 1)
			return (ft_handle_error(5, 2, NULL, NULL));
		if (i + 1 < argc)
		{
			if (ft_is_pipe_like(argv[i]) && ft_is_pipe_like(argv[i + 1]))
				return (ft_handle_error(6, 2, argv[i + 1], NULL));
			if (ft_is_redir(argv[i]) && (ft_is_pipe_like(argv[i + 1])
					|| ft_is_redir(argv[i + 1])))
				return (ft_handle_error(6, 2, argv[i + 1], NULL));
		}
	}
	return (ft_check_parentheses(argv, argc));
}
