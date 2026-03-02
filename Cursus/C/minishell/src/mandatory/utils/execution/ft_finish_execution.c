/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish_execution.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 20:10:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/24 17:35:03 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * ENGLISH: Frees the linked list of command structures.
 *
 * SPANISH: Libera la lista enlazada de estructuras de comando.
 *
 * @param cmd_list   The head of the command list. /
 *                   La cabeza de la lista de comandos.
 */
static void	ft_free_cmd_list(t_cmd *cmd_list)
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
 * ENGLISH: Closes all file descriptors in the command list
 *          that are not standard input/output.
 *
 * SPANISH: Cierra todos los descriptores de archivo en la lista
 * 			de comandos que no sean entrada/salida estándar.
 *
 * @param cmd_list   The head of the command list. /
 *                   La cabeza de la lista de comandos.
 */
static void	ft_close_fds(t_cmd *cmd_list)
{
	t_cmd	*current;

	current = cmd_list;
	while (current)
	{
		if (current->infd != STDIN_FILENO)
			close(current->infd);
		if (current->outfd != STDOUT_FILENO)
			close(current->outfd);
		current = current->next;
	}
}

/**
 * ENGLISH: Handles a child process termination due to a signal,
 *          updating the last exit status and printing messages.
 *
 * SPANISH: Maneja la terminación de un proceso hijo debido a una señal,
 * 			actualizando el último estado de salida e imprimiendo mensajes.
 *
 * @param status               The termination status of the child process. /
 *                             El estado de terminación del proceso hijo.
 * @param last_exit_status     Pointer to the last exit status variable. /
 *                             Puntero a la variable del último estado de
 *                             salida.
 */
static void	ft_handle_signaled(int status, int *last_exit_status)
{
	int	sig;

	sig = WTERMSIG(status);
	*last_exit_status = 128 + sig;
	if (sig == SIGQUIT)
	{
		if (WCOREDUMP(status))
			ft_putstr_fd("Quit (core dumped)\n", 2);
		else
			ft_putstr_fd("Quit\n", 2);
	}
}

/**
 * ENGLISH: Waits for all child processes to finish,
 *          updating the last exit status accordingly.
 *
 * SPANISH: Espera a que todos los procesos hijos terminen,
 * 			actualizando el último estado de salida en consecuencia.
 *
 * @param pids                 The array of child process IDs. /
 *                             La matriz de IDs de procesos hijos.
 * @param cmd_count            The number of commands (child processes). /
 *                             El número de comandos (procesos hijos).
 * @param last_exit_status     Pointer to the last exit status variable. /
 *                             Puntero a la variable del último estado de
 *                             salida.
 */
static void	ft_wait_for_children(pid_t *pids, int cmd_count,
		int *last_exit_status)
{
	int	i;
	int	status;

	i = 0;
	while (i < cmd_count)
	{
		if (pids[i] > 0)
		{
			waitpid(pids[i], &status, 0);
			if (WIFEXITED(status))
				*last_exit_status = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				ft_handle_signaled(status, last_exit_status);
		}
		i++;
	}
}

/**
 * ENGLISH: Finalizes the execution process by closing file descriptors,
 *          waiting for child processes, freeing resources, and updating
 *          the last exit status.
 *
 * SPANISH: Finaliza el proceso de ejecución cerrando descriptores de archivo,
 *          esperando a los procesos hijos, liberando recursos y actualizando
 *          el último estado de salida.
 *
 * @param pids       The array of child process IDs. /
 *                   La matriz de IDs de procesos hijos.
 * @param cmd_list   The head of the command list. /
 *                   La cabeza de la lista de comandos.
 * @param data       The shell data structure. /
 *                   La estructura de datos del shell.
 *
 * @returns The last exit status after execution. /
 *          El último estado de salida después de la ejecución.
 */
int	ft_finish_execution(pid_t *pids, t_cmd *cmd_list, t_data *data)
{
	int	last_exit_status;

	last_exit_status = data->last_exit_status;
	ft_close_fds(cmd_list);
	ft_wait_for_children(pids, data->cmd_count, &last_exit_status);
	data->last_exit_status = last_exit_status;
	free(pids);
	ft_free_cmd_list(cmd_list);
	cmd_list = NULL;
	if (data && data->argv)
	{
		ft_free_matrix(data->argv);
		data->argv = NULL;
	}
	return (last_exit_status);
}
