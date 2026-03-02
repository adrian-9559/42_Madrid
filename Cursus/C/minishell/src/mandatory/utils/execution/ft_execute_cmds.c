/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_cmds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:35:40 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/25 00:12:46 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * ENGLISH: Forks a new process to execute a command, setting up I/O
 * 			redirections and handling built-in commands.
 *
 * SPANISH: Crea un nuevo proceso para ejecutar un comando,
 * 			configurando redirecciones de E/S y manejando comandos internos.
 *
 * @param curr     The current command to execute. /
 *                 El comando actual a ejecutar.
 * @param cmd_l    The list of all commands. /
 *                 La lista de todos los comandos.
 * @param data     Pointer to the shell data structure. /
 *                 Puntero a la estructura de datos del shell.
 * @param pids     Array to store the PIDs of forked processes. /
 *                 Arreglo para almacenar los PIDs de los procesos creados.
 *
 * @returns SUCCESS on successful fork, ERROR on failure. /
 *          SUCCESS en fork exitoso, ERROR en caso de fallo.
 */
static int	ft_fork_exec(t_cmd *curr, t_cmd *cmd_l, t_data **data, pid_t *pids)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (curr->has_error)
			exit(EXIT_FAILURE);
		ft_setup_child_io(curr, cmd_l);
		if (ft_is_builtin(curr))
			(*data)->last_exit_status = ft_exec_builtin(curr, data);
		else
			(*data)->last_exit_status = ft_exec_bin(curr);
		exit((*data)->last_exit_status);
	}
	else if (pid > 0)
	{
		pids[curr->index] = pid;
		if (curr->infd != STDIN_FILENO)
			close(curr->infd);
		if (curr->outfd != STDOUT_FILENO)
			close(curr->outfd);
		return (SUCCESS);
	}
	return (perror("fork"), ERROR);
}

/**
 * ENGLISH: Executes a pipeline of commands, handling built-ins and
 * 			forking as needed.
 *
 * SPANISH: Ejecuta una tubería de comandos, gestionando built-ins y
 * 			haciendo fork según sea necesario.
 *
 * @param cmd_list  The list of commands to execute. /
 *                  La lista de comandos a ejecutar.
 *
 * @param data      Pointer to the shell data structure. /
 *                  Puntero a la estructura de datos del shell.
 *
 * @returns The exit status of the last command executed. /
 *          El estado de salida del último comando ejecutado.
 */
int	ft_execute_cmds(t_cmd *cmd_list, t_data **data)
{
	t_cmd	*current;
	pid_t	*pids;

	if (!cmd_list || !data || !*data)
		return (ERROR);
	pids = ft_calloc((*data)->cmd_count, sizeof(pid_t));
	if (!pids)
		return (ERROR);
	current = cmd_list;
	while (current)
	{
		if (ft_is_builtin(current) && current->infd == STDIN_FILENO
			&& current->outfd == STDOUT_FILENO && !current->next
			&& current->has_error == 0)
		{
			(*data)->last_exit_status = ft_exec_builtin(current, data);
		}
		else if (ft_fork_exec(current, cmd_list, data, pids) == ERROR)
			break ;
		current = current->next;
	}
	ft_finish_execution(pids, cmd_list, *data);
	return ((*data)->last_exit_status);
}
