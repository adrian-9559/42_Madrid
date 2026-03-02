/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 20:29:05 by agarcia           #+#    #+#             */
/*   Updated: 2025/11/24 17:56:21 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

/**
 * ENGLISH: Assigns a file descriptor to the command structure based on
 *          the redirection type.
 *
 * SPANISH: Asigna un descriptor de archivo a la estructura del comando
 *          según el tipo de redirección.
 *
 * @param cmd       Pointer to the command structure to update.
 *                  Puntero a la estructura de comando a actualizar.
 *
 * @param filename  The filename for the redirection.
 *                  El nombre del archivo para la redirección.
 *
 * @param type      The type of redirection ("<", ">", ">>", "<<").
 *                  El tipo de redirección ("<", ">", ">>", "<<").
 *
 * @returns The file descriptor on success, -1 on error.
 *          El descriptor de archivo en caso de éxito, -1 en caso de error.
 */
int	ft_assign_fd(t_cmd **cmd, char *filename, char *type)
{
	int	fd;

	fd = -1;
	if (ft_strcmp(type, "<") == 0)
		fd = ft_handle_infile(filename);
	else if (!ft_strcmp(type, ">") || !ft_strcmp(type, ">>"))
		fd = ft_handle_outfile(filename, 0 + (ft_strcmp(type, ">>") == 0));
	else if (ft_strcmp(type, "<<") == 0)
		fd = ft_heredoc(filename, (*cmd)->data);
	if (fd == -1)
		return (-1);
	if (ft_strcmp(type, "<") == 0 || ft_strcmp(type, "<<") == 0)
	{
		if ((*cmd)->infd != STDIN_FILENO)
			close((*cmd)->infd);
		(*cmd)->infd = fd;
	}
	else
	{
		if ((*cmd)->outfd != STDOUT_FILENO)
			close((*cmd)->outfd);
		(*cmd)->outfd = fd;
	}
	return (fd);
}

/**
 * ENGLISH: Checks if the given filename for redirection is ambiguous.
 *          A filename is considered ambiguous if it is NULL, empty,
 *          or contains spaces or tabs.
 *
 * SPANISH: Verifica si el nombre de archivo dado para la redirección
 *          es ambiguo.
 *          Un nombre de archivo se considera ambiguo si es NULL,
 *          está vacío, o contiene espacios o tabulaciones.
 *
 * @param filename  The filename to check.
 *                  El nombre del archivo a verificar.
 *
 * @returns 1 if the filename is ambiguous, 0 otherwise.
 *          1 si el nombre del archivo es ambiguo, 0 en caso contrario.
 */
static int	ft_is_ambiguous_redirect(char *filename)
{
	int	i;

	if (!filename || !filename[0])
		return (1);
	i = 0;
	while (filename[i])
	{
		if (filename[i] == ' ' || filename[i] == '\t')
			return (1);
		i++;
	}
	return (0);
}

/**
 * ENGLISH: Checks for ambiguous redirection in the command's argument.
 *          If ambiguous, it sets error flags and prints an error message.
 *
 * SPANISH: Verifica si hay una redirección ambigua en el argumento
 *          del comando.
 *          Si es ambigua, establece las banderas de error e imprime
 *          un mensaje de error.
 *
 * @param cmd           Pointer to the command structure.
 *                      Puntero a la estructura del comando.
 *
 * @param argv          The command's argument vector.
 *                      El vector de argumentos del comando.
 *
 * @param i             The index of the redirection operator in argv.
 *                      El índice del operador de redirección en argv.
 *
 * @param expanded_arg  The processed argument after expansions.
 *                      El argumento procesado después de las expansiones.
 *
 * @returns 1 if ambiguous redirection is detected, 0 otherwise.
 *          1 si se detecta una redirección ambigua, 0 en caso contrario.
 */
static int	ft_check_ambiguous(t_cmd *cmd, char **argv, int i,
		char *expanded_arg)
{
	char	*clean_arg;
	char	*original_arg;

	original_arg = argv[i + 1];
	clean_arg = ft_remove_quotes(argv[i + 1]);
	if (!clean_arg)
		clean_arg = argv[i + 1];
	if (ft_strcmp(argv[i], "<<") != 0 && ((!original_arg || !expanded_arg)
			|| ft_strcmp(original_arg, expanded_arg) != 0)
		&& ft_is_ambiguous_redirect(expanded_arg))
	{
		if (clean_arg != argv[i + 1])
			free(clean_arg);
		ft_fprintf(2, ERROR_AMBIGUOUS_REDIRECT, original_arg);
		cmd->data->last_exit_status = 1;
		cmd->has_error = 1;
		free(expanded_arg);
		return (1);
	}
	if (clean_arg != argv[i + 1])
		free(clean_arg);
	return (0);
}

/**
 * ENGLISH: Handles file descriptor errors after attempting to assign
 *          a file descriptor for redirection.
 *
 * SPANISH: Maneja los errores de descriptor de archivo después de
 *          intentar asignar un descriptor de archivo para la redirección.
 *
 * @param cmd     Pointer to the command structure.
 *                Puntero a la estructura del comando.
 *
 * @param fd_ret  The return value from the file descriptor assignment.
 *                El valor de retorno de la asignación del descriptor
 *                de archivo.
 *
 * @returns -1 if a critical error occurred, 0 otherwise.
 *          -1 si ocurrió un error crítico, 0 en caso contrario.
 */
static int	ft_handle_fd_error(t_cmd *cmd, int fd_ret)
{
	if (fd_ret == -2)
		return (-1);
	if (fd_ret == -1)
	{
		cmd->data->last_exit_status = 1;
		cmd->has_error = 1;
	}
	return (0);
}

/**
 * ENGLISH: Handles redirection for the command based on the
 *          specified arguments.
 *
 * SPANISH: Maneja la redirección para el comando según los
 *          argumentos especificados.
 *
 * @param cmd   Pointer to the command structure.
 *              Puntero a la estructura del comando.
 * @param argv  The command's argument vector.
 *              El vector de argumentos del comando.
 * @param i     The index of the redirection operator in argv.
 *              El índice del operador de redirección en argv.
 *
 * @returns The next index to process in argv, or -1 on error.
 *          El siguiente índice a procesar en argv, o -1 en caso de error.
 */
int	ft_redir(t_cmd *cmd, char **argv, int i)
{
	char	*expanded_arg;
	char	*clean_arg;
	int		fd_ret;

	expanded_arg = ft_process_arg(argv[i + 1], cmd->data);
	if (ft_check_ambiguous(cmd, argv, i, expanded_arg))
		return (i++);
	if (cmd->has_error == 1 && ft_strcmp(argv[i], "<<") != 0)
		return (free(expanded_arg), i++);
	clean_arg = ft_remove_quotes(expanded_arg);
	if (!clean_arg)
		clean_arg = expanded_arg;
	fd_ret = ft_assign_fd(&cmd, clean_arg, argv[i]);
	if (clean_arg != expanded_arg)
		free(clean_arg);
	free(expanded_arg);
	if (ft_handle_fd_error(cmd, fd_ret) == -1)
		return (-1);
	return (i + 1);
}
