/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:57:27 by agarcia           #+#    #+#             */
/*   Updated: 2025/12/03 01:15:57 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

/**
 * ENGLISH: Checks if the token is a redirection operator.
 *
 * SPANISH: Comprueba si el token es un operador de redirección.
 *
 * @param token The token to check. /
 *              El token a comprobar.
 * @returns     1 if it is a redirection operator, 0 otherwise. /
 *              1 si es un operador de redirección, 0 en caso contrario.
 */
static int	ft_is_redir(char *token)
{
	return (!ft_strcmp(token, "<") || !ft_strcmp(token, ">")
		|| !ft_strcmp(token, ">>") || !ft_strcmp(token, "<<"));
}

/**
 * ENGLISH: Checks if the token is a command operator (|, ||, &&).
 *
 * SPANISH: Comprueba si el token es un operador de comando (|, ||, &&).
 *
 * @param token The token to check. /
 *              El token a comprobar.
 * @returns     1 if it is a command operator, 0 otherwise. /
 *              1 si es un operador de comando, 0 en caso contrario.
 */
static int	ft_is_operator(char *token)
{
	return (!ft_strcmp(token, "|") || !ft_strcmp(token, "||")
		|| !ft_strcmp(token, "&&"));
}

/**
 * ENGLISH: Processes a segment of the input arguments.
 *          Handles operators, redirections, and arguments.
 *
 * SPANISH: Procesa un segmento de los argumentos de entrada.
 *          Maneja operadores, redirecciones y argumentos.
 *
 * @param current_cmd Pointer to the current command node. /
 * 					Puntero al nodo de comando actual.
 * @param data        Shell data structure with argv array and argc count. /
 * 				Estructura de datos del shell con el array argv y el conteo
 * 				argc.
 * @param i           Pointer to the current index in argv. /
 * 				Puntero al índice actual en argv.
 * @param cmd_index   Pointer to the current command index. /
 * 				Puntero al índice actual del comando.
 *
 * @returns           SUCCESS on success, ERROR on failure. /
 * 					SUCCESS en caso de éxito, ERROR en caso de fallo.
 */
static int	ft_handle_segment_token(t_cmd **current_cmd, t_data *data, int *i,
		int *cmd_index)
{
	int	ret;

	if (!ft_strcmp(data->argv[*i], "("))
		return (ft_process_subshell(current_cmd, data, i, cmd_index));
	if (ft_is_operator(data->argv[*i]))
	{
		if (ft_process_op(current_cmd, data->argv[*i], cmd_index,
				(*current_cmd)->data) == ERROR)
			return (ERROR);
		return (SUCCESS);
	}
	if (ft_is_redir(data->argv[*i]))
	{
		ret = ft_redir(*current_cmd, data->argv, *i);
		if (ret == -1)
			return (ERROR);
		*i = ret;
		return (SUCCESS);
	}
	if (ft_strcmp(data->argv[*i], ")"))
		ft_add_arg_to_cmd(*current_cmd, ft_remove_quotes(data->argv[*i]));
	return (SUCCESS);
}

static int	ft_process_segment(t_cmd **current_cmd, t_data *data, int *i,
		int *cmd_index)
{
	int	ret;

	if (data->argv[*i] != NULL)
	{
		if (*i >= data->argc)
			return (ERROR);
		ret = ft_handle_segment_token(current_cmd, data, i, cmd_index);
		if (ret == ERROR)
			return (ERROR);
	}
	(*i)++;
	return (SUCCESS);
}

/**
 * ENGLISH: Parses the input arguments into a linked list of command structures.
 * 		Handles operators, redirections, and arguments.
 *
 * SPANISH: Analiza los argumentos de entrada en una lista enlazada de
 * 		estructuras de comando.
 * 		Maneja operadores, redirecciones y argumentos.
 *
 * @param data  Shell data structure with argv array and argc count.
 *
 * @returns     Pointer to command list head, or NULL on error.
 */
t_cmd	*ft_parse_input(t_data *data)
{
	t_cmd	*cmd_list;
	t_cmd	*current_cmd;
	int		i;
	int		cmd_index;
	int		ret;

	i = 0;
	cmd_index = 0;
	ret = 0;
	if (!data->argv || !data || data->argc == 0)
		return (NULL);
	cmd_list = ft_create_cmd_node(0);
	if (!cmd_list)
		return (NULL);
	current_cmd = cmd_list;
	cmd_list->data = data;
	while (i < data->argc && ret == SUCCESS)
		ret = ft_process_segment(&current_cmd, data, &i, &cmd_index);
	if (ret == ERROR)
	{
		ft_free_cmd_list(cmd_list);
		return (NULL);
	}
	return (cmd_list);
}
