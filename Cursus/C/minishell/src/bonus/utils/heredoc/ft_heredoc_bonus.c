/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 12:00:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/24 18:42:13 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_bonus.h"

/**
 * ENGLISH: Processes a single line of heredoc input.
 *
 * SPANISH: Procesa una sola línea de entrada heredoc.
 *
 * @param fd    The file descriptor to write the processed line to. /
 *              El descriptor de archivo donde escribir la línea procesada.
 * @param line  The input line to process. /
 * 			La línea de entrada a procesar.
 * @param del   The heredoc delimiter string. /
 * 			La cadena delimitadora del heredoc.
 * @param data  Pointer to the shell data structure. /
 * 			Puntero a la estructura de datos del shell.
 *
 * @returns 1 if the delimiter is matched (end of heredoc), 0 otherwise,
 *          or -1 on error. /
 *          1 si se coincide con el delimitador (fin del heredoc), 0
 *          en caso contrario, o -1 en caso de error.
 */
static int	hdoc_process(int fd, char *line, const char *del, t_data *data)
{
	char	*exp;
	int		nl;

	nl = (line[ft_strlen(line) - 1] == '\n');
	if (!ft_strncmp(line, del, ft_strlen(line) - nl) && ft_strlen(line)
		- nl == ft_strlen(del))
	{
		free(line);
		return (1);
	}
	exp = ft_process_arg(line, data);
	if (!exp)
		return (free(line), -1);
	write(fd, exp, ft_strlen(exp));
	write(fd, "\n", 1);
	free(exp);
	return (free(line), 0);
}

/**
 * ENGLISH: Main loop for reading heredoc input until the delimiter is found.
 *
 * SPANISH: Bucle principal para leer la entrada heredoc hasta que se
 *          encuentra el delimitador.
 *
 * @param fd    The file descriptor to write the heredoc content to. /
 *              El descriptor de archivo donde escribir el contenido del
 *              heredoc.
 * @param del   The heredoc delimiter string. /
 * 			La cadena delimitadora del heredoc.
 * @param data  Pointer to the shell data structure. /
 * 			Puntero a la estructura de datos del shell.
 *
 * @returns 0 on success, -1 on error. /
 *          0 en caso de éxito, -1 en caso de error.
 */
static int	hdoc_loop(int fd, const char *del, t_data *data)
{
	char	*line;

	while (1)
	{
		line = readline(HEREDOC_PROMPT);
		if (!line)
			return (-1);
		if (hdoc_process(fd, line, del, data) != 0)
			break ;
	}
	return (0);
}

/**
 * ENGLISH: Child process function for handling heredoc input.
 *
 * SPANISH: Función del proceso hijo para manejar la entrada heredoc.
 *
 * @param fd    The file descriptor to write the heredoc content to. /
 *              El descriptor de archivo donde escribir el contenido del
 *              heredoc.
 * @param del   The heredoc delimiter string. /
 * 			La cadena delimitadora del heredoc.
 * @param data  Pointer to the shell data structure. /
 * 			Puntero a la estructura de datos del shell.
 */
static void	hdoc_child(int fd, const char *del, t_data *data)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	hdoc_loop(fd, del, data);
	close(fd);
	_exit(0);
}

/**
 * ENGLISH: Parent process function for handling heredoc input.
 *
 * SPANISH: Función del proceso padre para manejar la entrada heredoc.
 *
 * @param pid   The PID of the child process handling heredoc. /
 *              El PID del proceso hijo que maneja el heredoc.
 * @param rd    The read end of the heredoc pipe. /
 *              El extremo de lectura de la tubería heredoc.
 * @param wr    The write end of the heredoc pipe. /
 *              El extremo de escritura de la tubería heredoc.
 * @param data  Pointer to the shell data structure. /
 *              Puntero a la estructura de datos del shell.
 *
 * @returns The read end of the heredoc pipe on success, or -1 on error. /
 *          El extremo de lectura de la tubería heredoc en caso de éxito,
 *          o -1 en caso de error.
 */
static int	hdoc_parent(pid_t pid, int rd, int wr, t_data *data)
{
	int	status;

	close(wr);
	waitpid(pid, &status, 0);
	ft_init_signals();
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
	{
		close(rd);
		write(1, "\n", 1);
		data->last_exit_status = 130;
		return (-1);
	}
	return (rd);
}

/**
 * ENGLISH: Handles the heredoc functionality by creating a pipe,
 *          forking a child process to read input until the delimiter
 *          is found, and returning the read end of the pipe.
 *
 * SPANISH: Maneja la funcionalidad heredoc creando una tubería,
 *          haciendo fork de un proceso hijo para leer la entrada
 *          hasta que se encuentra el delimitador, y devolviendo
 *          el extremo de lectura de la tubería.
 *
 * @param del   The heredoc delimiter string. /
 *              La cadena delimitadora del heredoc.
 * @param data  Pointer to the shell data structure. /
 *              Puntero a la estructura de datos del shell.
 *
 * @returns The read end of the heredoc pipe on success, or -1 on error. /
 *          El extremo de lectura de la tubería heredoc en caso de éxito,
 *          o -1 en caso de error.
 */
int	ft_heredoc(const char *del, t_data *data)
{
	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) == -1)
		return (-1);
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid < 0)
		return (close(pipefd[0]), close(pipefd[1]), -1);
	if (pid == 0)
	{
		close(pipefd[0]);
		hdoc_child(pipefd[1], del, data);
	}
	return (hdoc_parent(pid, pipefd[0], pipefd[1], data));
}
