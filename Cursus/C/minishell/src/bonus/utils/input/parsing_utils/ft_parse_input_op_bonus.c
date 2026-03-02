/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input_op_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 19:52:24 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/09 00:10:55 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell_bonus.h"

/**
 * ENGLISH: Handles the creation of a pipe between two commands.
 *          Sets up the appropriate file descriptors for input
 *          and output.
 *
 * SPANISH: Maneja la creación de una tubería entre dos comandos.
 *          Configura los descriptores de archivo apropiados para
 *          entrada y salida.
 *
 * @param current_cmd  Pointer to the current command pointer. /
 *                     Puntero al puntero del comando actual.
 *
 * @param pipefd  Array to hold the read and write file descriptors
 *                of the pipe. /
 *                Arreglo para contener los descriptores de archivo
 *                de lectura y escritura de la tubería.
 *
 * @returns 0 on success, -1 on failure. /
 *          0 en caso de éxito, -1 en caso de error.
 */
int	ft_handle_pipe(t_cmd **current_cmd, int *pipefd)
{
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (1);
	}
	if ((*current_cmd)->outfd == STDOUT_FILENO)
		(*current_cmd)->outfd = pipefd[1];
	else
		close(pipefd[1]);
	return (0);
}

/**
 * ENGLISH: Processes a command operator (pipe, AND, OR) and sets up the
 *          next command node in the command list.
 *
 * SPANISH: Procesa un operador de comando (tubería, AND, OR) y configura
 *          el siguiente nodo de comando en la lista de comandos.
 *
 * @param current_cmd  Pointer to the current command pointer. /
 *                     Puntero al puntero del comando actual.
 *
 * @param arg          The operator argument string ("|", "||", "&&"). /
 *                     La cadena de argumentos del operador ("|", "||", "&&").
 *
 * @param cmd_index    Pointer to the current command index. /
 *                     Puntero al índice del comando actual.
 *
 * @param data         Pointer to the shell data structure. /
 *                     Puntero a la estructura de datos del shell.
 *
 * @returns 0 on success, -1 on failure. /
 *          0 en caso de éxito, -1 en caso de error.
 */
int	ft_process_op(t_cmd **current_cmd, char *arg, int *cmd_index, t_data *data)
{
	int		pipefd[2];
	t_cmd	*new_cmd;

	new_cmd = ft_create_cmd_node(*cmd_index + 1);
	if (!new_cmd)
		return (-1);
	(*cmd_index)++;
	(*current_cmd)->next = new_cmd;
	new_cmd->data = data;
	new_cmd->op = OP_NONE;
	if (ft_strcmp(arg, "|") == 0)
		new_cmd->op = OP_PIPE;
	else if (ft_strcmp(arg, "||") == 0)
		new_cmd->op = OP_OR;
	else if (ft_strcmp(arg, "&&") == 0)
		new_cmd->op = OP_AND;
	if (new_cmd->op == OP_PIPE)
	{
		if (ft_handle_pipe(current_cmd, pipefd) == -1)
			return (-1);
		new_cmd->infd = pipefd[0];
	}
	*current_cmd = new_cmd;
	return (0);
}
