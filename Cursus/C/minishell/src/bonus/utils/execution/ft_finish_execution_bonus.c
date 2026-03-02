/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish_execution_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 20:10:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/12/03 01:06:21 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

/**
 * ENGLISH: Closes all file descriptors in the command list that are not
 *          standard input/output.
 *
 * SPANISH: Cierra todos los descriptores de archivo en la lista de comandos
 *          que no son la entrada/salida estándar.
 *
 * @param cmd_list   The list of commands. /
 *                   La lista de comandos.
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
 * ENGLISH: Handles the case when a child process is terminated by a signal,
 *          updating the last exit status and printing appropriate messages.
 *
 * SPANISH: Maneja el caso cuando un proceso hijo es terminado por una señal,
 *          actualizando el último estado de salida e imprimiendo mensajes
 *          apropiados.
 *
 * @param status               The status code returned by waitpid. /
 *                             El código de estado devuelto por waitpid.
 * @param last_exit_status     Pointer to the last exit status to update. /
 *                             Puntero al último estado de salida a actualizar.
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
 * ENGLISH: Checks if all child processes have already been waited for.
 *
 * SPANISH: Verifica si todos los procesos hijos ya han sido esperados.
 *
 * @param pids         Array of process IDs of the child processes. /
 *                     Array de IDs de proceso de los procesos hijos.
 * @param cmd_count    The number of commands (and thus child processes). /
 *                     El número de comandos (y por lo tanto de procesos hijos).
 *
 * @returns 1 if all processes have been waited for, 0 otherwise. /
 *          1 si todos los procesos han sido esperados, 0 en caso contrario.
 */
static int	ft_check_already_waited(pid_t *pids, int cmd_count)
{
	int	i;

	i = 0;
	while (i < cmd_count)
	{
		if (pids[i] == 0)
			return (1);
		i++;
	}
	return (0);
}

/**
 * ENGLISH: Waits for all child processes to finish and updates the last exit
 *          status based on the last process that finished.
 *
 * SPANISH: Espera a que todos los procesos hijos terminen y actualiza el
 *          último estado de salida basado en el último proceso que terminó.
 *
 * @param pids               Array of process IDs of the child processes. /
 *                           Array de IDs de proceso de los procesos hijos.
 * @param cmd_count          The number of commands (and thus child processes).
 *                           / El número de comandos (y por lo tanto de procesos
 *                           hijos).
 * @param last_exit_status   Pointer to the last exit status to update. /
 *                           Puntero al último estado de salida a actualizar.
 */
static void	ft_wait_for_children(pid_t *pids, int cmd_count,
		int *last_exit_status)
{
	int	i;
	int	status;
	int	already_waited;

	already_waited = ft_check_already_waited(pids, cmd_count);
	i = 0;
	while (i < cmd_count)
	{
		if (pids[i] > 0)
		{
			waitpid(pids[i], &status, 0);
			if (!already_waited)
			{
				if (WIFEXITED(status))
					*last_exit_status = WEXITSTATUS(status);
				else if (WIFSIGNALED(status))
					ft_handle_signaled(status, last_exit_status);
			}
		}
		i++;
	}
}

/**
 * ENGLISH: Finalizes the execution of commands by closing file descriptors,
 *          waiting for child processes, updating the last exit status,
 *          freeing allocated memory, and resetting the command list pointer.
 *
 * SPANISH: Finaliza la ejecución de comandos cerrando descriptores de archivo,
 *          esperando a los procesos hijos, actualizando el último estado
 * 			de salida, liberando memoria asignada y reiniciando el puntero
 * 			de la lista de comandos.
 *
 * @param pids       Array of process IDs of the child processes. /
 *                   Array de IDs de proceso de los procesos hijos.
 * @param cmd_list   Pointer to the head of the command list. /
 *                   Puntero al inicio de la lista de comandos.
 * @param data       Pointer to the data structure containing environment
 *                   and status info. /
 *                   Puntero a la estructura de datos que contiene información
 *                   del entorno y estado.
 */
int	ft_finish_execution(pid_t *pids, t_cmd *cmd_list, t_data *data)
{
	int		last_exit_status;
	t_cmd	*tmp;

	(void)tmp;
	last_exit_status = data->last_exit_status;
	ft_close_fds(cmd_list);
	ft_wait_for_children(pids, data->cmd_count, &last_exit_status);
	data->last_exit_status = last_exit_status;
	free(pids);
	ft_free_cmd_list(cmd_list);
	if (data && data->argv)
	{
		ft_free_matrix(data->argv);
		data->argv = NULL;
	}
	return (last_exit_status);
}
