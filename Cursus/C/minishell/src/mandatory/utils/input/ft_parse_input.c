/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 18:57:27 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/24 18:02:14 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * ENGLISH: Frees the linked list of command structures.
 *
 * SPANISH: Libera la lista enlazada de estructuras de comando.
 *
 * @param cmd_list Pointer to the head of the command list. /
 *                 Puntero a la cabeza de la lista de comandos.
 */
static void	free_cmd_list(t_cmd *cmd_list)
{
	t_cmd	*tmp;

	while (cmd_list)
	{
		tmp = cmd_list->next;
		ft_free_matrix(cmd_list->argv);
		free(cmd_list);
		cmd_list = tmp;
	}
}

/**
 * ENGLISH: Checks if the given token is a redirection operator.
 *
 * SPANISH: Verifica si el token dado es un operador de redirección.
 *
 * @param token The token to check. /
 *              El token a verificar.
 *
 * @returns 1 if the token is a redirection operator, 0 otherwise. /
 *          1 si el token es un operador de redirección, 0 en caso contrario.
 */
static int	ft_is_redir(char *token)
{
	return (!ft_strcmp(token, "<") || !ft_strcmp(token, ">")
		|| !ft_strcmp(token, ">>") || !ft_strcmp(token, "<<"));
}

/**
 * ENGLISH: Processes a single segment of the input arguments.
 * 		It handles pipes, redirections, and adds arguments to the command.
 *
 * SPANISH: Procesa un solo segmento de los argumentos de entrada.
 * 		Maneja tuberías, redirecciones y agrega argumentos al comando.
 *
 * @param current_cmd Pointer to the current command structure. /
 * 					Puntero a la estructura del comando actual.
 * @param data        Pointer to the shell data structure. /
 * 					Puntero a la estructura de datos del shell.
 * @param i           Pointer to the current index in the argument array. /
 * 					Puntero al índice actual en el arreglo de argumentos.
 * @param cmd_index   Pointer to the current command index. /
 * 					Puntero al índice actual del comando.
 *
 * @returns SUCCESS on successful processing, or ERROR on failure. /
 *          SUCCESS en caso de procesamiento exitoso, o ERROR en caso de fallo.
 */
static int	ft_process_segment(t_cmd **current_cmd, t_data *data, int *i,
		int *cmd_index)
{
	int	ret;

	if (data->argv[*i] != NULL)
	{
		if (*i >= data->argc)
			return (ERROR);
		if (ft_strcmp(data->argv[*i], "|") == 0)
		{
			if (ft_process_pipe(current_cmd, cmd_index,
					(*current_cmd)->data) == ERROR)
				return (ERROR);
		}
		else if (ft_is_redir(data->argv[*i]))
		{
			ret = ft_redir(*current_cmd, data->argv, *i);
			if (ret == -1)
				return (ERROR);
			*i = ret;
		}
		else if (data->argv[*i] && data->argv[*i][0] != '\0')
			ft_add_arg_to_cmd(*current_cmd, ft_remove_quotes(data->argv[*i]));
	}
	(*i)++;
	return (SUCCESS);
}

/**
 * ENGLISH: Parses the input arguments into a linked list of command
 * 		structures.
 * 		It processes pipes, redirections, and arguments.
 *
 * SPANISH: Analiza los argumentos de entrada en una lista enlazada
 * 		de estructuras de comando.
 * 		Procesa tuberías, redirecciones y argumentos.
 *
 * @param data Pointer to the shell data structure containing input
 *             arguments. /
 *             Puntero a la estructura de datos del shell que contiene
 *             los argumentos de entrada.
 *
 * @returns Pointer to the head of the command list on success,
 *          NULL on failure. /
 *          Puntero a la cabeza de la lista de comandos en caso de éxito,
 *          NULL en caso de fallo.
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
		free_cmd_list(cmd_list);
		return (NULL);
	}
	return (cmd_list);
}
