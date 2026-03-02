/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_pid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 00:35:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/24 17:40:47 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * ENGLISH: Extracts PID from a ps output line.
 *
 * SPANISH: Extrae el PID de una línea de salida de ps.
 *
 * @param line The line from ps output.
 *             La línea de salida de ps.
 *
 * @returns The PID string, or NULL on error.
 *          El string del PID, o NULL en caso de error.
 */
static char	*ft_extract_pid_from_line(char *line)
{
	char	*pid_start;
	char	*pid_end;
	int		len;

	pid_start = line;
	while (*pid_start && (*pid_start == ' ' || *pid_start == '\t'))
		pid_start++;
	pid_end = pid_start;
	while (*pid_end && *pid_end >= '0' && *pid_end <= '9')
		pid_end++;
	len = pid_end - pid_start;
	if (len == 0)
		return (NULL);
	return (ft_substr(pid_start, 0, len));
}

/**
 * ENGLISH: Executes the ps command and redirects output to a pipe.
 *
 * SPANISH: Ejecuta el comando ps y redirige la salida a una tubería.
 *
 * @param pipefd The pipe file descriptors.
 *               Los descriptores de archivo de la tubería.
 *
 * @param envp   The environment variables.
 *               Las variables de entorno.
 */
static void	ft_exec_ps_command(int pipefd[2], char **envp)
{
	char	*args[4];
	char	*ps_path;

	close(pipefd[0]);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	ps_path = "/bin/ps";
	args[0] = "ps";
	args[1] = "-o";
	args[2] = "pid,comm";
	args[3] = NULL;
	execve(ps_path, args, envp);
	exit(1);
}

/**
 * ENGLISH: Finds the line containing "minishell" in ps output.
 *
 * SPANISH: Encuentra la línea que contiene "minishell" en la salida de ps.
 *
 * @param buffer The ps output buffer.
 *               El buffer de salida de ps.
 *
 * @returns Pointer to the start of the minishell line, or NULL if not found.
 *          Puntero al inicio de la línea de minishell,
 *          o NULL si no se encuentra.
 */
static char	*ft_find_minishell_line(char *buffer)
{
	char	*result;
	char	*line_start;

	result = ft_strstr(buffer, "minishell");
	if (!result)
		return (NULL);
	line_start = result;
	while (line_start > buffer && *(line_start - 1) != '\n')
		line_start--;
	return (line_start);
}

/**
 * ENGLISH: Retrieves the PID of the minishell process.
 *
 * SPANISH: Recupera el PID del proceso minishell.
 *
 * @param data The shell data structure.
 *             La estructura de datos del shell.
 *
 * @returns The PID string, or NULL on error.
 *          El string del PID, o NULL en caso de error.
 */
static char	*ft_get_minishell_pid(t_data *data)
{
	int		pipefd[2];
	pid_t	pid;
	char	buffer[1024];
	int		bytes_read;
	char	*line_start;

	if (pipe(pipefd) == -1)
		return (NULL);
	pid = fork();
	if (pid == -1)
		return (close(pipefd[0]), close(pipefd[1]), NULL);
	if (pid == 0)
		ft_exec_ps_command(pipefd, data->envp);
	close(pipefd[1]);
	bytes_read = read(pipefd[0], buffer, sizeof(buffer) - 1);
	close(pipefd[0]);
	waitpid(pid, NULL, 0);
	if (bytes_read <= 0)
		return (NULL);
	buffer[bytes_read] = '\0';
	line_start = ft_find_minishell_line(buffer);
	if (!line_start)
		return (NULL);
	return (ft_extract_pid_from_line(line_start));
}

/**
 * ENGLISH: Expands $$ to the PID of the minishell process.
 *
 * SPANISH: Expande $$ al PID del proceso minishell.
 *
 * @param dst Pointer to the destination string.
 *            Puntero al string de destino.
 *
 * @param j   Pointer to current position in the argument.
 *            Puntero a la posición actual en el argumento.
 *
 * @returns SUCCESS on success, FAILURE on error.
 *          SUCCESS en caso de éxito, FAILURE en caso de error.
 */
int	ft_expand_pid(char **dst, int *j, t_data *data)
{
	char	*pid_str;
	int		ret;

	pid_str = ft_get_minishell_pid(data);
	if (!pid_str)
	{
		(*j) += 2;
		return (SUCCESS);
	}
	ret = ft_append(dst, pid_str);
	free(pid_str);
	(*j) += 2;
	return (ret);
}
