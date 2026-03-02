/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_subshell_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 00:00:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/12/03 01:09:25 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

/**
 * ENGLISH: Sets up I/O redirections for the subshell child process.
 *
 * SPANISH: Configura las redirecciones de E/S para el proceso hijo del
 *          subshell.
 *
 * @param cmd   The command containing I/O descriptors. /
 *              El comando que contiene los descriptores de E/S.
 */
static void	ft_setup_subshell_io(t_cmd *cmd)
{
	if (cmd->infd != STDIN_FILENO)
	{
		dup2(cmd->infd, STDIN_FILENO);
		close(cmd->infd);
	}
	if (cmd->outfd != STDOUT_FILENO)
	{
		dup2(cmd->outfd, STDOUT_FILENO);
		close(cmd->outfd);
	}
}

/**
 * ENGLISH: Handles the parent process after forking a subshell.
 *
 * SPANISH: Maneja el proceso padre después de hacer fork de un subshell.
 *
 * @param cmd   The command containing I/O descriptors. /
 *              El comando que contiene los descriptores de E/S.
 *
 * @param pids  Array to store the PIDs of forked processes. /
 *              Array para almacenar los PIDs de los procesos forked.
 *
 * @param pid   The PID of the forked child process. /
 *              El PID del proceso hijo forked.
 */
static void	ft_handle_subshell_parent(t_cmd *cmd, pid_t *pids, pid_t pid)
{
	pids[cmd->index] = pid;
	if (cmd->infd != STDIN_FILENO)
		close(cmd->infd);
	if (cmd->outfd != STDOUT_FILENO)
		close(cmd->outfd);
}

/**
 * ENGLISH: Executes a subshell (command group in parentheses) in a
 *          child process.
 *
 * SPANISH: Ejecuta un subshell (grupo de comandos entre paréntesis) en un
 *          proceso hijo.
 *
 * @param cmd   The command containing the subshell. /
 *              El comando que contiene el subshell.
 *
 * @param data  Pointer to the shell data structure. /
 *              Puntero a la estructura de datos del shell.
 *
 * @param pids  Array to store the PIDs of forked processes. /
 *              Array para almacenar los PIDs de los procesos forked.
 *
 * @returns SUCCESS on successful execution, ERROR on failure. /
 *          SUCCESS en ejecución exitosa, ERROR en fallo.
 */
int	ft_execute_subshell(t_cmd *cmd, t_data **data, pid_t *pids)
{
	pid_t	pid;

	if (!cmd || !cmd->subshell)
		return (ERROR);
	pid = fork();
	if (pid == 0)
	{
		ft_setup_subshell_io(cmd);
		(*data)->last_exit_status = ft_execute_cmds(cmd->subshell, data);
		exit((*data)->last_exit_status);
	}
	else if (pid > 0)
	{
		ft_handle_subshell_parent(cmd, pids, pid);
		return (SUCCESS);
	}
	return (perror("fork"), ERROR);
}
