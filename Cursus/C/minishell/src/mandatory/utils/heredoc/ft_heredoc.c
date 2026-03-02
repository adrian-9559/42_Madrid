/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 12:00:00 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/24 17:50:06 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * ENGLISH: Processes a single line of heredoc input.
 * 		It checks for the delimiter and performs variable expansion
 * 		before writing to the heredoc file descriptor.
 *
 * SPANISH: Procesa una sola línea de entrada heredoc.
 * 		Verifica el delimitador y realiza la expansión de variables
 * 		antes de escribir en el descriptor de archivo heredoc.
 *
 * @param fd   The file descriptor for the heredoc. /
 *             El descriptor de archivo para el heredoc.
 * @param line The line of input to process. /
 *             La línea de entrada a procesar.
 * @param del  The heredoc delimiter. /
 *             El delimitador del heredoc.
 * @param data Pointer to the shell data structure. /
 *             Puntero a la estructura de datos del shell.
 *
 * @returns 1 if the delimiter is matched, 0 on success, or -1 on error. /
 *          1 si se coincide con el delimitador, 0 en caso de éxito,
 *          o -1 en caso de error.
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
 * ENGLISH: Main loop for reading heredoc input lines.
 * 		It continues to read lines until the delimiter is matched
 * 		or an error occurs.
 *
 * SPANISH: Bucle principal para leer líneas de entrada heredoc.
 * 		Continúa leyendo líneas hasta que se coincide con el
 * 		delimitador o ocurre un error.
 *
 * @param fd   The file descriptor for the heredoc. /
 *             El descriptor de archivo para el heredoc.
 * @param del  The heredoc delimiter. /
 * 			El delimitador del heredoc.
 * @param data Pointer to the shell data structure. /
 * 			Puntero a la estructura de datos del shell.
 *
 * @returns 0 on success, or -1 on error. /
 *          0 en caso de éxito, o -1 en caso de error.
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
 * ENGLISH: Child process function for heredoc handling.
 * 		It sets default signal handlers and starts the heredoc input loop.
 *
 * SPANISH: Función del proceso hijo para el manejo de heredoc.
 * 		Establece controladores de señales predeterminados y
 * 		inicia el bucle de entrada heredoc.
 *
 * @param fd   The file descriptor for the heredoc. /
 * 			El descriptor de archivo para el heredoc.
 * @param del  The heredoc delimiter. /
 * 			El delimitador del heredoc.
 * @param data Pointer to the shell data structure. /
 * 			Puntero a la estructura de datos del shell.
 *
 * @returns This function does not return ; it exits the child process. /
 *          Esta función no retorna; sale del proceso hijo.
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
 * ENGLISH: Parent process function for heredoc handling.
 * 		It waits for the child process to finish and checks for
 * 		interrupt signals.
 *
 * SPANISH: Función del proceso padre para el manejo de heredoc.
 * 		Espera a que el proceso hijo termine y verifica
 * 		las señales de interrupción.
 *
 * @param pid The PID of the child process. /
 *            El PID del proceso hijo.
 * @param rd  The read end of the heredoc pipe. /
 *            El extremo de lectura de la tubería heredoc.
 * @param wr  The write end of the heredoc pipe. /
 *            El extremo de escritura de la tubería heredoc.
 * @param data Pointer to the shell data structure. /
 *             Puntero a la estructura de datos del shell.
 *
 * @returns The read end file descriptor on success, or -1 on interrupt. /
 *          El descriptor de archivo del extremo de lectura en caso
 *          de éxito, o -1 en caso de interrupción.
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
 * ENGLISH: Main function to handle heredoc input.
 * 		It creates a pipe, forks a child process to read
 * 		heredoc input, and manages the parent process.
 * 		It returns the read end of the pipe for further processing.
 * 		Handles interrupts and errors appropriately.
 *
 * SPANISH: Función principal para manejar la entrada heredoc.
 * 		Crea una tubería, bifurca un proceso hijo para leer
 * 		la entrada heredoc, y gestiona el proceso padre.
 * 		Devuelve el extremo de lectura de la tubería para
 * 		procesamiento adicional.
 * 		Maneja interrupciones y errores adecuadamente.
 *
 * @param del  The heredoc delimiter. /
 * 			El delimitador del heredoc.
 * @param data Pointer to the shell data structure. /
 * 			Puntero a la estructura de datos del shell.
 *
 * @returns The read end file descriptor on success, or -1 on error. /
 *          El descriptor de archivo del extremo de lectura en caso
 *          de éxito, o -1 en caso de error.
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
