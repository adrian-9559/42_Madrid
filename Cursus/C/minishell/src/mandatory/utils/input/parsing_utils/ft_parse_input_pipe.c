/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_input_pipe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 19:52:24 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/16 19:38:17 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

/**
 * ENGLISH: Processes a pipe operator, creating a new command node
 *          and setting up the appropriate file descriptors for
 *          inter-process communication.
 *
 * SPANISH: Procesa un operador de tubería, creando un nuevo nodo
 *          de comando y configurando los descriptores de archivo
 *          apropiados para la comunicación entre procesos.
 *
 * @param current_cmd  Pointer to the current command pointer. /
 *                     Puntero al puntero del comando actual.
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
int	ft_process_pipe(t_cmd **current_cmd, int *cmd_index, t_data *data)
{
	int		pipefd[2];
	t_cmd	*new_cmd;

	if (pipe(pipefd) == -1)
		return (ERROR);
	new_cmd = ft_create_cmd_node(*cmd_index + 1);
	if (!new_cmd)
		return (ERROR);
	(*cmd_index)++;
	(*current_cmd)->next = new_cmd;
	new_cmd->data = data;
	if ((*current_cmd)->outfd == STDOUT_FILENO)
		(*current_cmd)->outfd = pipefd[1];
	else
		close(pipefd[1]);
	new_cmd->infd = pipefd[0];
	*current_cmd = new_cmd;
	return (SUCCESS);
}
